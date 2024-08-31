from .module2 import count_in_list  # This imports count_in_list from module2
__all__ = ['module1', 'module2']    # This imports module1 and module2

"""__init__.py indicates to Python that the directory should be treated as a package."""

"""
Key functions of __init__.py:
- Marks a Directory as a Package: Allows Python to recognize the directory as a package.
- Controls Exports: Specifies what gets imported with from package import *.
- Re-exports Symbols: Exposes selected submodules or functions at the package level.
- Initialization Code: Contains setup code that runs when the package is imported.
- Namespace Management: Manages the package's namespace to avoid conflicts and provide a clear structure.
"""
