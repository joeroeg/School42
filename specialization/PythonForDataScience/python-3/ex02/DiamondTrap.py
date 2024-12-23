from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """Representing the King family."""
    def __init__(self, first_name, is_alive=True):
        super().__init__(first_name, is_alive)
        self.family_name = "Baratheon"

    def __str__(self):
        return f"Vector: ('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    def __repr__(self):
        return f"Vector: ('{self.family_name}', '{self.eyes}', '{self.hairs}')"

    def die(self):
        """
        Kill the King character.
        """
        self.is_alive = False

    def set_eyes(self, eyes):
        """
        Set the eyes color of the King character.
        """
        self.eyes = eyes

    def set_hairs(self, hairs):
        """
        Set the hairs color of the King character.
        """
        self.hairs = hairs

    def get_eyes(self):
        """
        Get the eyes color of the King character.
        """
        return self.eyes

    def get_hairs(self):
        """
        Get the hairs color of the King character.
        """
        return self.hairs
