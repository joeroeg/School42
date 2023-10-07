# This code imports the dis module and uses the dis.dis() function to display the bytecode instructions for both the square function and the main block of code.
# The dis() function disassembles the bytecode into a more human-readable format that shows the individual instructions and their operands.
# When you run this code, you should see the bytecode instructions printed to the console for both the square function and the main block of code.
# Note that the dis() function only works with functions and blocks of code that have been defined in the current scope.
# If you want to disassemble code that is defined in a different module, you can use the dis.disassemble() function instead.
import dis

def square(x):
    return x * x

def main():
    i = 0
    y = 0
    while True:
        y += square(i)
        if y > 100000:
            break
        i = i + 1

dis.dis(square)
dis.dis(main.__code__)
