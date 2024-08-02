"""Return the type of the object passed as a parameter."""


def NULL_not_found(object: any) -> int:
    """Checks if the object is None, False, 0, or an empty string.

    If the object is a float and its value is "nan", it prints "Cheese".
    If the object is not found, it prints "Type not Found".
    """
    value = type(object)
    if object is None:
        print("Nothing:", object, value)
    elif isinstance(object, float) and str(object) == "nan":
        print("Cheese:", object, value)
    elif object is False:
        print("Fake:", object, value)
    elif object == 0:
        print("Zero:", object, value)
    elif object == '':
        print("Empty:", value)
    else:
        print("Type not Found")
    return 1
