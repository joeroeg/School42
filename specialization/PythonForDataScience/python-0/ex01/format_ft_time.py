import time

scitext = "in scientific notation"

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
formatted_string = "Seconds since January 1, 1970: {:,.4f} or {:.2e} scitext"

# Print the formatted string
print(formatted_string.format(time_diff, time_diff))

# Get the current date
current_date = time.strftime("%B %d %Y", time.localtime())

# Print the current date
print(current_date)


"""
mktime() - takes a time tuple and returns seconds since the epoch.
strftime() - takes a time tuple and returns a time.
gmtime() - takes a number of seconds since the epoch and returns a time tuple.
time() - returns the current time in seconds since the epoch.
"""
