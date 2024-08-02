def NULL_not_found(object: any) -> int:
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
