"""Function that slices a 2D list."""


def slice_me(family: list, start: int, end: int) -> list:
    """Slices a 2D list from start index to end index (exclusive)."""
    if not isinstance(family, list):
        raise ValueError("Error: Please enter a list.")

    if not isinstance(start, int) or not isinstance(end, int):
        raise ValueError("Error: Please enter integers for all parameters.")

    if end > len(family):
        raise ValueError("Error: End index cannot be greater than the length.")

    if not family or not all(isinstance(row, list) for row in family):
        raise ValueError("Error: Please enter a 2D list.")

    num_rows = len(family)
    num_cols = len(family[0])
    print(f"My shape is : ({num_rows}, {num_cols})")

    sliced_family = family[start:end]

    new_num_rows = len(sliced_family)
    print(f"My new shape is : ({new_num_rows}, {num_cols})")

    return sliced_family
