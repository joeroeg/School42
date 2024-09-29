"""Tester."""

from array2D import slice_me


def main():
    """Test the function."""
    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]

    test_cases = [
        (family, 0, 2),
        (family, 1, -2),
        (family, 0, "2"),
        (family, 0, 2.0),
        (family, 0, 5),
        (tuple(family), 0, 2),
        ([1, 2, 3], 0, 2)
    ]

    for case in test_cases:
        try:
            print(slice_me(*case))
        except ValueError as e:
            print(f"{case}: {e}")


if __name__ == '__main__':
    main()
