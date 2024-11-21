"""This module calculates the BMI of two people and applies a limit to it."""


def validate(height: list[int | float], weight: list[int | float]) -> None:
    """Validate the input lists for calculate_bmi."""
    if len(height) != 2 or len(weight) != 2:
        raise ValueError("must contain exactly two elements.")

    if not all(isinstance(h, (int, float)) and h > 0 for h in height):
        raise ValueError("must be positive integers or floats.")

    if not all(isinstance(w, (int, float)) and w > 0 for w in weight):
        raise ValueError("must be positive integers or floats.")


def bmi(h: list[int | float], w: list[int | float]) -> list[int | float]:
    """Calculate the BMI for two people given height and weight lists."""
    bmi = []
    for i in range(2):
        bmi.append(w[i] / (h[i]) ** 2)
    return bmi


def give_bmi(h: list[int | float], w: list[int | float]) -> list[int | float]:
    """Validate input and calculates BMI."""
    try:
        validate(h, w)
        return bmi(h, w)
    except Exception as e:
        print(f"Error: {e}")
        return []


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """Apply a limit to the BMI values."""
    return [b > limit for b in bmi]
