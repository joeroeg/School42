"""Tester."""

from array2D import slice_me


def main():
    """Test the function."""
    family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]

    test_cases = [
        (family, 0, 2),         # Valid case: slice the first row
        (family, 1, -2),        # Valid case: negative slice
        ([[1, 2, 3]], 0, 1),    # Valid case: 2D list
        (family, -1, -2),       # Valid case: negative indices for slicing
        (family, 0, 0),         # Valid Edge case: empty slice range
        ([], 0, 2),             # Invalid Edge case: empty list
        (family, 0, "2"),       # Invalid case: string as index
        (family, 0, 2.0),       # Invalid case: float as index
        (family, 0, 5),         # Invalid case: index out of range
        (tuple(family), 0, 2),  # Invalid case: passing a tuple
        ([1, 2, 3], 0, 1),      # Invalid case: 1D list
        (family, 0, 6),         # Invalid case: index beyond list length
        (family, 2, 5),         # Invalid case: large slice range
        (family, "a", 2),       # Invalid case: string as index
        (family, 0, 1.5),       # Invalid case: float for slice
        (family, 1, "end"),     # Invalid case: "end" as index
        (family, 0, None)       # Invalid case: None as index
    ]

    for case in test_cases:
        try:
            print(slice_me(*case))
        except ValueError as e:
            print(f"{case}: {e}")
        except TypeError as e:
            print(f"{case}: {e}")
        except Exception as e:
            print(f"{case}: Unexpected error - {e}")


if __name__ == '__main__':
    main()
