class calculator:
    """Perform dot product, addition, and subtraction of two vectors."""

    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """Calculate and print the dot product."""
        result = 0
        i = 0

        while True:
            try:
                result += V1[i] * V2[i]
                i += 1
            except IndexError:
                break
        print(f"Dot product is: {result}")

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """Calculate and print the sum of two vectors."""
        result = []
        i = 0

        while True:
            try:
                result.append(V1[i] + V2[i])
                i += 1
            except IndexError:
                break
        print(f"Add Vector is: {result}")

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """Calculate and print the difference of two vectors."""
        result = []
        i = 0

        while True:
            try:
                result.append(V1[i] - V2[i])
                i += 1
            except IndexError:
                break
        print(f"Sous Vector is: {result}")
