"""This module returns the type of the object passed as a parameter."""


def all_thing_is_obj(object: any) -> int:
    """Return the type of the object passed as a parameter.

    object: any -> int - This is a function definition with type hints.
    object: any indicates that the parameter object can be of any type.
    -> int indicates that the function returns an integer value
    """
    value = type(object)
    if value == list:
        print("List : {}".format(value))
    elif value == tuple:
        print("Tuple : {}".format(value))
    elif value == set:
        print("Set : {}".format(value))
    elif value == dict:
        print("Dict : {}".format(value))
    elif value == str and object == "Brian":
        print("Brian is in the kitchen : {}".format(value))
    else:
        print("Type not found")
    return 42
