from S1E9 import Character, Stark


# Create an instance of the Stark class
Ned = Stark("Ned")
print(Ned.__dict__)             # Inspect the attributes of the object
print(Ned.is_alive)             # Check the initial alive status
Ned.die()                       # Kill Ned
print(Ned.is_alive)             # Verify the status has changed
print(Ned.__doc__)              # Print the docstring of the Stark class
print(Ned.__init__.__doc__)     # Print the docstring of the __init__ method
print(Ned.die.__doc__)          # Print the docstring of the die method

print("---")

# Create another instance with is_alive set to False
Lyanna = Stark("Lyanna", False)
print(Lyanna.__dict__)          # Inspect the attributes of the object


# Try to create an instance of the abstract class (should raise an error)
try:
    hodor = Character("Hodor")
except TypeError as e:
    print("TypeError:", e)      # Print the error message
