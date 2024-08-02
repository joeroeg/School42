import time

# Get the current time
current_time = time.time()

# Get the epoch time
epoch_time = time.gmtime(0)

# Calculate the difference
time_diff = current_time - time.mktime(epochcd _time)

# Format the time difference
time_diff_formatted = "{:.4f}".format(time_diff)

# Convert in scientific notation
time_diff_sci = "{:.2e}".format(time_diff)

# Build the formatted string
formatted_string = "Seconds since January 1, 1970: {:,.4f} or {:.2e} in scientific notation"

# Print the formatted string
print(formatted_string.format(time_diff, time_diff))

# Get the current date
current_date = time.strftime("%B %d %Y", time.localtime())

# Print the current date
print(current_date)


"""
mktime() - This function takes a time tuple and returns the number of seconds since the epoch.
strftime() - This function takes a time tuple and returns a string representing the time, controlled by a format string.
gmtime() - This function takes a number of seconds since the epoch and returns a time tuple.
time() - This function returns the current time in seconds since the epoch.
"""
