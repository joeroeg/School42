import os
from datetime import datetime

print(os.getcwd())                                          # current working directory
os.chdir('/Users/hezhukov/Desktop/42/playground/python/')   # change directory
print(os.getcwd())                                          # current working directory
print(os.listdir())                                         # list of all the files and directories in the current working directory
try:
    os.mkdir('os-demo')                                     # make a new directory
    os.makedirs('os-demo-2/sub-dir-1')                      # make a new directory and sub-directory
except FileExistsError:
    pass
try:
    os.rename('os-demo-2', 'os-demo')                       # rename a directory
except FileNotFoundError:
    pass

print(os.stat('os-demo'))                                   # get information about a file or directory
print(os.stat('os-demo').st_size)                           # get size of a file or directory
print(os.stat('os-demo').st_mtime)                          # get last modification time

mod_time = os.stat('os-demo').st_mtime                      # get last modification time
print(datetime.fromtimestamp(mod_time))                     # convert last modification time to human readable format

for dirpath, dirnames, filenames in os.walk('/Users/hezhukov/Desktop/42/playground/python/'):
    print('Current Path:', dirpath)
    print('Directories:', dirnames)
    print('Files:', filenames)
    print()

try:
    os.removedirs('os-demo/sub-dir-1')                      # remove a directory and sub-directory
except FileNotFoundError:
    pass

print(os.environ.get('HOME'))                               # get environment variable
file_path = os.path.join(os.environ.get('HOME'), 'test.txt')# join two paths
print(file_path)

print(os.path.basename('/tmp/test.txt'))                    # get the base name of a path
