def __len__(*args: int) -> int:
    length = 0
    for arg in args:
        length += 1
    return length


def __sum__(*args: int) -> int:
    summation = 0
    for arg in args:
        summation += arg
    return summation


def __sort__(*args: int) -> list:
    sorted_list = []
    for arg in args:
        sorted_list.append(arg)
        if __len__(sorted_list) > 1:
            for i in range(__len__(sorted_list) - 1):
                if sorted_list[i] > sorted_list[i + 1]:
                    sorted_list[i], sorted_list[i + 1] = sorted_list[i + 1], sorted_list[i]
    return sorted_list


def __mean__(*args: int) -> float:
    return __sum__(*args) / __len__(*args)


def __median__(*args: int) -> float:
    pass


def __variance__(*args: int) -> float:
    mean = __mean__(*args)
    return sum((x - mean) ** 2 for x in args) / __len__(*args)


def __std__(*args: int) -> float:
    return __variance__(*args) ** 0.5


def __quartile__(*args: int) -> list:
    pass

def ft_statistics(*args: int, **kwargs: str) -> None:
    if not args or not kwargs:
        print("ERROR")
        return

    valid_stats = {"mean", "median", "quartile", "std", "var"}
    invalid_stats = set(kwargs.values()) - valid_stats

    if invalid_stats:
        for _ in invalid_stats:
            print("ERROR")
        return

    if "mean" in kwargs.values():
        print(f"mean: {__mean__(*args)}")
    if "median" in kwargs.values():
        pass
    if "quartile" in kwargs.values():
        pass
    if "std" in kwargs.values():
        print(f"std: {__std__(*args)}")
    if "var" in kwargs.values():
        print(f"var: {__variance__(*args)}")
