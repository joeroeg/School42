def callLimit(limit: int):
    def callLimiter(function):
        count = 0

        def limit_function(*args, **kwds):
            nonlocal count
            if count < limit:
                count += 1
                return function(*args, **kwds)
            else:
                print(f"Error: {function} call too many times")
                return None
        return limit_function
    return callLimiter
