# Navigate to project directory
cd /path/to/ft_package

# Install build tools
pip install build wheel

# Build the distributions
python -m build

# Uninstall any previous installation (if applicable)
pip uninstall ft_package

# Install from source distribution
pip install ./dist/ft_package-0.0.1.tar.gz

# Install from wheel distribution
pip install ./dist/ft_package-0.0.1-py3-none-any.whl

# Clean up previous build artifacts
rm -rf dist build *.egg-info
