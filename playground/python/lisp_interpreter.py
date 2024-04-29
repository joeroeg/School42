# Parsing Input: The interpreter needs to be able to read and understand Lisp code. This involves breaking down the input (code) into tokens (lexing) and then organizing these tokens into a structure that represents the program (parsing), typically using recursive descent parsing.
# Environment Setup: Define the environment where variables and functions are stored. In Lisp, environments are often implemented as stacks of hash tables (or dictionaries in Python), where each table represents a scope.
# Evaluating Expressions: Once the input is parsed into an abstract syntax tree (AST), the interpreter evaluates these expressions. Evaluation in Lisp is unique because of its homoiconicity, where the code is data and can be manipulated as such.
# Functions and Special Forms: Implementing built-in functions (like car, cdr, cons, list, etc.) and special forms (like if, define, lambda, etc.). Functions are generally easier to implement as they follow regular evaluation rules, while special forms may require special handling as their operands are not always evaluated.
# Recursion and Self-Reference: Because Lisp heavily uses recursive structures and functions, an interpreter must efficiently support recursive calls and self-referential data structures.
# Error Handling: Providing informative error messages and handling unexpected inputs or operations gracefully.

def parse(program):
    "Read a Scheme expression from a string."
    return read_from_tokens(tokenize(program))

def tokenize(s):
    "Convert a string into a list of tokens."
    return s.replace('(', ' ( ').replace(')', ' ) ').split()

def read_from_tokens(tokens):
    "Read an expression from a sequence of tokens."
    if len(tokens) == 0:
        raise SyntaxError('unexpected EOF while reading')
    token = tokens.pop(0)
    if token == '(':
        L = []
        while tokens[0] != ')':
            L.append(read_from_tokens(tokens))
        tokens.pop(0)  # pop off ')'
        return L
    elif token == ')':
        raise SyntaxError('unexpected )')
    else:
        return atom(token)

def atom(token):
    "Numbers become numbers; every other token is a symbol."
    try:
        return int(token)
    except ValueError:
        try:
            return float(token)
        except ValueError:
            return str(token)

def eval(x, env):
    "Evaluate an expression in an environment."
    if isinstance(x, str):  # variable reference
        return env[x]
    elif not isinstance(x, list):  # constant literal
        return x
    elif x[0] == 'quote':  # quotation
        (_, exp) = x
        return exp
    else:  # procedure call
        proc = eval(x[0], env)
        args = [eval(arg, env) for arg in x[1:]]
        return proc(*args)

# Environment setup
env = {
    '+': lambda x, y: x + y,
    '-': lambda x, y: x - y,
    '*': lambda x, y: x * y,
    '/': lambda x, y: x / y,
}

# Example usage
program = "(+ 1 2)"
parsed = parse(program)
result = eval(parsed, env)
print(result)  # Output: 3
