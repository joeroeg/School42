"""Format the time.

mktime() - takes a time and returns seconds since the epoch.
strftime() - takes a time and returns a timw (string).
gmtime() - takes a seconds since the epoch and returns a time.
time() - returns the current time in seconds since the epoch.
"""

import time

since_text = "Seconds since January 1, 1970: "
scientific_text = " in scientific notation"

# Get the current time
current_time = time.time()

# Get the epoch time
epoch_time = time.gmtime(0)

# Calculate the difference
time_diff = current_time - time.mktime(epoch_time)

# Format the time difference
time_diff_formatted = "{:.4f}".format(time_diff)

# Convert in scientific notation
time_diff_sci = "{:.2e}".format(time_diff)

# Build the formatted string
formatted = since_text + time_diff_formatted + scientific_text + time_diff_sci

# Print the formatted string
print(formatted.format(time_diff, time_diff))

# Get the current date
current_date = time.strftime("%B %d %Y", time.localtime())

# Print the current date
print(current_date)
