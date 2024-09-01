"""This module calculates the BMI of two people and applies a limit to it."""

def validate_input(height: list[int | float], weight: list[int | float]) -> None:
    """Validates the input lists for calculate_bmi."""
    if len(height) != 2 or len(weight) != 2:
        raise ValueError("must contain exactly two elements.")

    if not all(isinstance(h, (int, float)) and h > 0 for h in height):
        raise ValueError("must be positive integers or floats.")

    if not all(isinstance(w, (int, float)) and w > 0 for w in weight):
        raise ValueError("must be positive integers or floats.")

def calculate_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """Calculates the BMI for two people given height and weight lists."""
    bmi = []
    for i in range(2):
        bmi.append(weight[i] / (height[i]) ** 2)
    return bmi

def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """Validates input and calculates BMI."""
    try:
        validate_input(height, weight)
        return calculate_bmi(height, weight)
    except Exception as e:
        print(f"Error: {e}")
        return []


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """Applies a limit to the BMI values."""
    return [b > limit for b in bmi]


def main():
    """Main function."""
    try:
        height = [2.71, 1.15]
        weight = [165.3, 38.4]

        bmi = give_bmi(height, weight)

        print(f"BMI: {bmi}")

        bmi = apply_limit(bmi, 27)
        print(f"BMI with limit: {bmi}")

        # Error cases

        bmi = give_bmi([180, 170, 12], [70, 80, 12])
        bmi = give_bmi([180, "a"], [70, 80])
        bmi = give_bmi([0, 0], [0, 0])
        bmi = give_bmi(height + 10, weight + 10)
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
