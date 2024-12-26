def length(*args: int) -> int:
    """Length is the number of elements in a list."""
    count = 0
    for _ in args:
        count += 1
    return count


def summation(*args: int) -> int:
    """Summation is the total of a list of numbers."""
    summation = 0
    for arg in args:
        summation += arg
    return summation


def sorting(*args: float) -> list:
    sl = list(args)
    n = length(*args)
    for i in range(n):
        swapped = False
        for j in range(n - i - 1):
            if sl[j] > sl[j + 1]:
                sl[j], sl[j + 1] = sl[j + 1], sl[j]
                swapped = True
        if not swapped:
            break
    return sl


def arithmetic_mean(*args: int) -> float:
    """Mean is the average of a list of numbers."""
    if not args:
        raise ValueError("Cannot compute mean of an empty list")
    return summation(*args) / length(*args)


def arithmetic_median(*args: int) -> float:
    """Median is the middle value of a sorted list."""
    sorted_list = sorting(*args)
    n = length(*args)
    if n % 2 == 0:
        return (sorted_list[n // 2 - 1] + sorted_list[n // 2]) / 2
    return sorted_list[n // 2]


def variance(*args: int) -> float:
    """Variance is the average of the squared differences from the Mean."""
    mean = arithmetic_mean(*args)
    return arithmetic_mean(*[(x - mean) ** 2 for x in args])


def standard_deviation(*args: int) -> float:
    """Standard deviation is the square root of variance."""
    return variance(*args) ** 0.5

# [1 11] [42] [64 360]

def quartile(*args: float) -> dict:
    """Quartile is the median of the lower and upper half of a sorted list."""
    sorted_data = sorting(*args)
    n = length(*sorted_data)

    def interpolate(p):
        position = p * (n - 1)
        k = int(position)
        f = position - k
        if k + 1 < n:
            return sorted_data[k] + f * (sorted_data[k + 1] - sorted_data[k])
        return sorted_data[k]

    q1 = interpolate(0.25)
    q3 = interpolate(0.75)

    return [q1, q3]


def ft_statistics(*args: int, **kwargs: str) -> None:
    """Prints the statistics of a list of numbers."""
    valid_stats = {"mean", "median", "quartile", "std", "var"}

    if not set(kwargs.values()).issubset(valid_stats):
        return

    if not args or not kwargs:
        for _ in kwargs.values():
            print("ERROR")
        return

    if "mean" in kwargs.values():
        print(f"mean : {arithmetic_mean(*args)}")
    if "median" in kwargs.values():
        print(f"median : {arithmetic_median(*args)}")
    if "quartile" in kwargs.values():
        print(f"quartile : {quartile(*args)}")
    if "std" in kwargs.values():
        print(f"std : {standard_deviation(*args)}")
    if "var" in kwargs.values():
        print(f"var : {variance(*args)}")
