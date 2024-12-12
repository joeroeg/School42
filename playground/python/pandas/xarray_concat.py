import xarray as xr
import numpy as np

"""
xarray is designed to handle data that naturally exists in more than two dimensions (like geospatial data, climate data, etc.).
It provides labeled axes (coordinates), which makes it easier to manipulate and analyze multidimensional data compared to using plain numpy arrays.
"""

# Create a 3D numpy array
data = np.random.rand(4, 3, 2)

# Create an xarray DataArray
coords = {
    'time': ['2024-01-01', '2024-01-02', '2024-01-03', '2024-01-04'],
    'lat': [10, 20, 30],
    'lon': [100, 110]
}

data_array = xr.DataArray(data, coords=coords, dims=['time', 'lat', 'lon'])

print(data_array)


