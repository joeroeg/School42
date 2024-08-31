"""This module calculates the BMI of two people and applies a limit to it."""

def validate_input(height: list[int | float], weight: list[int | float]) -> None:
    """Function must accept only two lists of two elements each, containing only integers or floats. If not, raise ValueError."""
    try:
        if len(height) != 2 or len(weight) != 2:
            raise ValueError("Input lists must contain exactly two elements.")
        for i in range(2):
            if type(height[i]) not in [int, float] or type(weight[i]) not in [int, float]:
                raise ValueError("Input lists must contain only integers or floats.")
    except ValueError as e:
        print(f"Validation Error: {e}")
    except TypeError as e:
        print(f"Type Error: {e}. Inputs should be lists of integers or floats.")

def calculate_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """Calculates the BMI for two people given height and weight lists."""
    try:
        bmi = []
        for i in range(2):
            bmi.append(weight[i] / (height[i] / 100) ** 2)
        return bmi
    except ZeroDivisionError:
        print("Error: Height cannot be zero when calculating BMI.")
        return []
    except Exception as e:
        print(f"An unexpected error occurred while calculating BMI: {e}")
        return []

def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """Validates input and calculates BMI."""
    try:
        validate_input(height, weight)
        return calculate_bmi(height, weight)
    except Exception as e:
        print(f"An error occurred in give_bmi: {e}")
        return []

def apply_limit(bmi: list[int | float], limit: int) -> list[int | float]:
    """Applies a limit to the BMI values."""
    try:
        return [min(b, limit) for b in bmi]
    except Exception as e:
        print(f"An error occurred while applying limit: {e}")
        return []

def main():
    """Main function."""
    try:
        height = [2.71, 1.15]
        weight = [165.3, 38.4]

        bmi = give_bmi(height, weight)
        print(f"BMI: {bmi}")

        # bmi = give_bmi([180, 170], [70, 80])
        # print(f"BMI: {bmi}")

        # bmi = apply_limit(bmi, 27)
        # print(f"BMI with limit: {bmi}")

        # Error cases

        # bmi = give_bmi([180, 170, 0], [70, 80])
        # print(f"BMI: {bmi}")

        # bmi = give_bmi([180, a], [70, 80])
        # print(f"BMI: {bmi}")

        # bmi = give_bmi([0, 0], [0, 0])
        # print(f"BMI: {bmi}")

        # bmi = apply_limit(bmi, 27)
        # print(f"BMI with limit: {bmi}")

        bmi = give_bmi([180, 170.11], [70, 80.00])
        print(f"BMI: {bmi}")


    except Exception as e:
        print(f"An error occurred in main: {e}")

if __name__ == "__main__":
    main()
