def all_thing_is_obj(object: any) -> int:
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

"""
object: This is the name of the parameter. In this case, it's a single parameter named object.
: any: This is a type hint, which is a way to indicate the expected type of the parameter. In this case, any means that the parameter can be of any type (e.g., integer, string, list, etc.). Type hints are not enforced by Python, but they can help with code readability and are used by some IDEs and tools for code analysis.
-> int: This is the return type hint. It indicates the type of value that the function returns. In this case, the function returns an integer (int).
"""
