try:
    # Code that might cause an exception
    x = 1 / 0
except ZeroDivisionError:
    # Code to execute if a ZeroDivisionError occurs
    print("You can't divide by zero!")
