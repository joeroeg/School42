class calculator:
    """A class to perform basic operations on a list of numbers."""
    def __init__(self, number) -> None:
        self.number = number

    def __add__(self, object) -> None:
        self.number = [x + object for x in self.number]
        print(self.number)

    def __mul__(self, object) -> None:
        self.number = [x * object for x in self.number]
        print(self.number)

    def __sub__(self, object) -> None:
        self.number = [x - object for x in self.number]
        print(self.number)

    def __truediv__(self, object) -> None:
        try:
            self.number = [x / object for x in self.number]
            print(self.number)
        except ZeroDivisionError:
            print("Error: division by zero")
