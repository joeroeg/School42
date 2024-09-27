"""Slice a list of family members from start to end-1 index."""


def slice_me(family: list, start: int, end: int) -> list:
    """Slices a list of family members from start to end-1 index."""
    return family[start:end]


if __name__ == '__main__':
    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]

    print(slice_me(family, 0, 2))
    print(slice_me(family, 1, -2))
