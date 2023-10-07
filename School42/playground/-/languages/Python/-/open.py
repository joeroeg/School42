# Open a file named "example.txt" in read mode
file = open("example.txt", "r")

# Read the contents of the file and print them
content = file.read()
print(content)

# Close the file
file.close()


# Open a file named "example.txt" in read mode using with statement
with open("example.txt", "r") as file:
    # Read the contents of the file and print them
    content = file.read()
    print(content)
