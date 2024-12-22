from S1E9 import Character


class Baratheon(Character):
    """
    A class representing a member of House Baratheon, inheriting from Character.
    """
    def __init__(self, first_name, is_alive=True):
        super().__init__(first_name, is_alive)

    def __str__(self):
        return f"Baratheon {self.first_name}"

    def __repr__(self):
        return f"Baratheon {self.first_name}"

    def die(self):
        """
        Kill the Baratheon character.
        """
        self.is_alive = False

robert = Baratheon("Robert")

class Lannister(Character):
    """
    A class representing a member of House Lannister, inheriting from Character.
    """
    def __init__(self, first_name, is_alive=True):
        super().__init__(first_name, is_alive)

    def die(self):
        """
        Kill the Lannister character.
        """
        self.is_alive = False

    def create_lannister():
        pass
