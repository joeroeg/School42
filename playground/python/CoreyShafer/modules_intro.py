import modules                          # Standard import
import modules as m                     # Import with alias
from modules import find_index, test    # Import specific functions and variables
from modules import find_index as find  # Import specific function with alias
from modules import *                   # Import all functions and variables
import sys                              # Import sys module
try:
    from . import modules          # ImportError when importing relative module
except ImportError as e:
    print(e)
# sys.path.append('/Users/42/42/playground/python/CoreyShafer') # Add directory to sys.path (not recommended)
# export PYTHONPATH="/Users/42/42/playground/python/CoreyShafer" # Add environment variable to PYTHONPATH (not recommended)
# sys.path.insert(0, '/Users/42/42/playground/python/CoreyShafer') # Add directory to sys.path (not recommended)
# sys.path.remove('/Users/42/42/playground/python/CoreyShafer') # Remove directory from sys.path (not recommended)



courses = ['History', 'Math', 'Physics', 'CompSci']

index = modules.find_index(courses, 'Math')
print(index)

index = m.find_index(courses, 'Math')
print(index)

index = find_index(courses, 'Math')
print(index)
print(test)

print(sys.path) # List of directories where Python looks for modules


"""Best Practices for Importing Modules:
1. Import modules at the top of the file.
2. Use absolute imports for clarity.
3. Avoid wildcard imports.
4. Avoid importing multiple modules on the same line.
5. Use aliases for modules with long names.
6. Use aliases for functions with long names.
7. Avoid using relative imports.
8. Handle ImportError exceptions when importing modules.

Organizing Imports:
1. Standard Library Imports
2. Related Third Party Imports
3. Local Application/Library Specific Imports
"""
