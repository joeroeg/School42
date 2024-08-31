To create your own Python package, you need to organize your Python code into a structured directory, create a few metadata files, and use a package manager like `setuptools` to handle packaging and distribution.

Here’s a step-by-step guide to creating a Python package:

### 1. **Organize Your Code into a Directory Structure**

First, create a directory for your package. For example, let's say your package is named `mypackage`.

```bash
mypackage/
├── mypackage/
│   ├── __init__.py      # It defines what is exposed when a package is imported.
│   ├── module1.py       # Python module (e.g., functions, classes)
│   └── module2.py       # Python module (e.g., functions, classes)
├── README.md            # Optional: description of your package
├── setup.py             # Metadata and instructions for building the package
└── LICENSE              # Optional: license for your package
```

- **`mypackage/`**: The root directory of your package.
- **`mypackage/` (inside the root)**: The subdirectory that contains your actual code.
- **`__init__.py`**: An empty file (can be non-empty if needed) that makes this directory a Python package.

### 2. **Create the `setup.py` File**

`pyproject.toml` is the build script for setuptools, which contains metadata about your package and instructions on how to install it. Here is a basic example:

- **`build-system`**: Configuration for the build system is used to build the package.
- **`project`**: Metadata about the project, including the package name, version, description, authors, license, and readme file.
- **`tool.setuptools`**: Setuptools configuration, including the packages to include in the distribution.
- **`tool.setuptools.package-data`**: Package data configuration to include Python files in the package.

```toml
[build-system]                                                      # Build system configuration
requires = ["setuptools>=42", "wheel"]                              # Build system requirements
build-backend = "setuptools.build_meta"                             # Build backend (setuptools)

[project]                                                           # Project metadata
name = "ft_package"                                                 # Name of your package
version = "0.1.0"                                                   # Version of your package
description = "A custom package for counting elements in a list"    # Short description
authors = [{name = "Your Name", email = "youremail@example.com"}]   # Author information
license = {text = "MIT"}                                            # License information
readme = "README.md"                                                # Readme file
dependencies = []                                                   # List of dependencies

[tool.setuptools]                                                   # Setuptools configuration
packages = ["ft_package"]                                           # Packages to include

[tool.setuptools.package-data]                                      # Package data configuration
ft_package = ["*.py"]                                               # Include all Python files in the package
```

### 3. **Write Your Package Code**

Add your code to the `mypackage/` directory. Each `.py` file is a module that can be imported from your package.

Example of `mypackage/module1.py`:

```python
def hello():
    return "Hello from module1!"
```

### 4. **Build and Distribute Your Package**

To build your package, navigate to the root directory of your package and run:

```bash
python setup.py sdist bdist_wheel
```

- **`sdist`**: Creates a source distribution (a `.tar.gz` file).
- **`bdist_wheel`**: Creates a binary distribution (a `.whl` file).

These files will be created in a `dist/` directory.

> `python setup.py sdist bdist_wheel` is currently deprecated, use the `build` tool to build your package:



1. **Install `build` if you haven’t already:**

   ```bash
   pip install build
   ```

2. **Build Your Package with `build`:**

   Run the following command from your package root directory:

   ```bash
   python -m build
   ```

   This will create both the source distribution (`.tar.gz`) and the wheel distribution (`.whl`) files in the `dist/` directory.

### 5. **Install Your Package Locally**

To test the installation of your package locally, run:

```bash
pip install .
```

Alternatively, to install from the generated distribution files:

```bash
pip install dist/mypackage-0.1.0-py3-none-any.whl
```

### 6. Uninstall Your Package
To uninstall a package that has been installed in your environment using pip, run:

``` bash
pip uninstall <package-name>
```

If you want to delete the files generated during the build process (.tar.gz, .whl, etc.), you should remove the dist/ and build/ directories created by the packaging tools.

``` bash
rm -rf dist/ build/ *.egg-info
```

### 7. **Upload Your Package to PyPI (Optional)**

If you want to share your package publicly, you can upload it to the Python Package Index (PyPI):

1. **Install `twine`**:

    ```bash
    pip install twine
    ```

2. **Upload your package**:

    ```bash
    twine upload dist/*
    ```

This will prompt you to enter your PyPI credentials and upload your package.
