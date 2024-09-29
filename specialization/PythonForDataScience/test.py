def divide(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        print("Handled by the callee: Returning None")
        return None
    except TypeError as e:
        # Re-raise the exception for the caller to handle
        raise e

print(divide(10, 0))
