from setuptools import setup, find_packages

setup(
    name='ft_package',                          # Name of your package
    version='0.1.0',                            # Version of your package
    description='A simple example package',     # Short description
    author='joe',                               # Your name or organization
    author_email='joe@example.com',             # Your contact email
    url='https://github.com/joe/mypackage',     # URL of your package (e.g., GitHub)
    packages=find_packages(),                   # Automatically find all packages in the directory
    install_requires=[                          # List of dependencies
    ],
    classifiers=[                               # Optional: A list of keywords that are used to categorize the package.
    ],
    python_requires='>=3.6',                    # Specify the Python version required
)
