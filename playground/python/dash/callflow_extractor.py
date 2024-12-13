import ast
import json
import os
import fnmatch


class CallFlowGenerator(ast.NodeVisitor):
    def __init__(self, include_builtins=False, include_methods=True, include_parameters=True, simplify_builtins=False, nested_output=False, detail_level=1):
        self.call_hierarchy = {}  # Stores the call flow structure
        self.current_function = None
        self.include_builtins = include_builtins
        self.include_methods = include_methods
        self.include_parameters = include_parameters
        self.simplify_builtins = simplify_builtins
        self.nested_output = nested_output
        self.detail_level = detail_level  # Controls verbosity
        self.builtins = set(dir(__builtins__))  # Built-in names

    def visit_FunctionDef(self, node):
        self.current_function = node.name
        if self.nested_output:
            self.call_hierarchy[self.current_function] = {"calls": []}
        else:
            self.call_hierarchy[self.current_function] = []
        self.generic_visit(node)
        self.current_function = None

    def visit_Call(self, node):
        if self.current_function:
            call_name = self._get_call_name(node)
            if call_name:
                if not self.include_builtins and self._is_builtin(call_name):
                    return
                if not self.include_methods and "." in call_name:
                    return

                if self.detail_level >= 2 and self.include_parameters:
                    call_name += self._get_call_parameters(node)

                if self.nested_output and self.detail_level == 3:
                    nested_calls = self._extract_nested_calls(node)
                    call_data = {"call_name": call_name}
                    if nested_calls:
                        call_data["nested_calls"] = nested_calls
                    self.call_hierarchy[self.current_function]["calls"].append(call_data)
                else:
                    self.call_hierarchy[self.current_function].append(call_name)
        self.generic_visit(node)

    def _extract_nested_calls(self, node):
        nested_calls = []
        for arg in node.args:
            if isinstance(arg, ast.Call):
                nested_call_name = self._get_call_name(arg)
                if nested_call_name:
                    nested_call_data = {"call_name": nested_call_name}
                    nested_call_data["nested_calls"] = self._extract_nested_calls(arg)
                    nested_calls.append(nested_call_data)
        return nested_calls

    def _get_call_name(self, node):
        if isinstance(node.func, ast.Name):
            name = node.func.id
            return f"BUILTIN({name})" if self.simplify_builtins and name in self.builtins else name
        elif isinstance(node.func, ast.Attribute):
            obj = node.func.value
            if isinstance(obj, ast.Name):
                return f"{obj.id}.{node.func.attr}"
            return node.func.attr
        return None

    def _get_call_parameters(self, node):
        def resolve_argument(arg):
            if isinstance(arg, ast.Constant):
                return repr(arg.value)
            elif isinstance(arg, ast.Name):
                return arg.id
            elif isinstance(arg, ast.Call):
                nested_call_name = self._get_call_name(arg)
                nested_params = self._get_call_parameters(arg)
                return f"{nested_call_name}{nested_params}"
            elif isinstance(arg, ast.Attribute):
                return f"{arg.value.id}.{arg.attr}" if isinstance(arg.value, ast.Name) else arg.attr
            elif isinstance(arg, ast.BinOp):
                left = resolve_argument(arg.left)
                right = resolve_argument(arg.right)
                op = self._get_operator(arg.op)
                return f"({left} {op} {right})"
            elif isinstance(arg, ast.List):
                return "[" + ", ".join(resolve_argument(el) for el in arg.elts) + "]"
            elif isinstance(arg, ast.Dict):
                keys = [resolve_argument(key) for key in arg.keys]
                values = [resolve_argument(value) for value in arg.values]
                return "{" + ", ".join(f"{k}: {v}" for k, v in zip(keys, values)) + "}"
            elif isinstance(arg, ast.Lambda):
                return "<lambda>"
            elif isinstance(arg, ast.UnaryOp):
                operand = resolve_argument(arg.operand)
                op = self._get_operator(arg.op)
                return f"({op}{operand})"
            elif isinstance(arg, ast.Compare):
                left = resolve_argument(arg.left)
                comparators = [resolve_argument(cmp) for cmp in arg.comparators]
                ops = [self._get_operator(op) for op in arg.ops]
                return f"{left} {' '.join(op + ' ' + cmp for op, cmp in zip(ops, comparators))}"
            return "..."

        args = [resolve_argument(arg) for arg in node.args]
        kwargs = [f"{kw.arg}={resolve_argument(kw.value)}" for kw in node.keywords if kw.arg]

        return f"({', '.join(args + kwargs)})" if args or kwargs else "()"

    def _is_builtin(self, func_name):
        return func_name in self.builtins

    def _get_operator(self, op):
        op_map = {
            ast.Add: "+",
            ast.Sub: "-",
            ast.Mult: "*",
            ast.Div: "/",
            ast.Mod: "%",
            ast.Lt: "<",
            ast.Gt: ">",
            ast.Eq: "==",
            ast.NotEq: "!=",
            ast.LtE: "<=",
            ast.GtE: ">=",
            ast.And: "and",
            ast.Or: "or",
            ast.Not: "not",
        }
        return op_map.get(type(op), "unknown_op")


def parse_docstring(docstring):
    if not docstring:
        return {}

    valid_headers = {"purpose", "workflow", "dependencies", "inputs", "outputs", "state"}
    parsed = {}
    current_section = None

    for line in docstring.splitlines():
        line = line.strip()
        if ":" in line:
            potential_header, rest = line.split(":", 1)
            header_key = potential_header.strip().lower()
            if header_key in valid_headers:
                current_section = header_key
                parsed[current_section] = rest.strip() if rest else ""
                continue
        if current_section:
            parsed[current_section] += f" {line}".strip()
        else:
            parsed.setdefault("miscellaneous", "")
            parsed["miscellaneous"] += f" {line}".strip()

    for key in parsed:
        parsed[key] = parsed[key].strip()

    return parsed


def process_directory(base_dir, exclude_dirs=None, exclude_files=None):
    exclude_dirs = exclude_dirs or []
    exclude_files = exclude_files or []

    for root, dirs, files in os.walk(base_dir):
        dirs[:] = [d for d in dirs if d not in exclude_dirs]
        for file in fnmatch.filter(files, "*.py"):
            if file not in exclude_files:
                yield os.path.join(root, file)


def extract_code_outline_with_call_flow(file_path, **kwargs):
    with open(file_path, "r") as file:
        tree = ast.parse(file.read())

    generator = CallFlowGenerator(**kwargs)
    generator.visit(tree)

    outline = []
    for node in tree.body:
        if isinstance(node, ast.FunctionDef):
            function_name = node.name
            docstring = ast.get_docstring(node)
            docstring_data = parse_docstring(docstring) if docstring else {"miscellaneous": "No docstring provided."}
            call_data = generator.call_hierarchy.get(function_name, {"calls": []} if kwargs.get("nested_output") else [])
            outline.append({
                "function": function_name,
                **docstring_data,
                "callflow": call_data
            })
    return outline


def extract_code_outline_from_directory(base_dir, exclude_dirs=None, exclude_files=None, **kwargs):
    """
    Process all Python files and group results by file.
    """
    all_outlines = {}
    for file_path in process_directory(base_dir, exclude_dirs, exclude_files):
        try:
            outlines = extract_code_outline_with_call_flow(file_path, **kwargs)
            all_outlines[file_path] = outlines
        except Exception as e:
            print(f"Error processing {file_path}: {e}")
    return all_outlines


if __name__ == "__main__":
    base_dir = "."  # Base directory to start processing
    exclude_dirs = ["tests", "components"]  # Example: Exclude "tests" directory
    exclude_files = ["callflow_extractor.py"]  # Example: Exclude "setup.py"

    config = {
        "include_builtins": False,
        "include_methods": True,
        "include_parameters": True,
        "simplify_builtins": True,
        "nested_output": False,
        "detail_level": 2,
    }

    combined_data = extract_code_outline_from_directory(base_dir, exclude_dirs, exclude_files, **config)

    with open("callflow_output.json", "w") as file:
        json.dump(combined_data, file, indent=4)

    print("Combined output saved to 'callflow_output.json'.")
