from abc import ABC, abstractmethod


class Character(ABC):
    """
    Abstract class for a character with a first name and health status.
    """

    def __init__(self, first_name, is_alive=True):
        """
        Initialize a character with a name and alive status.

        :param first_name: str - first name.
        :param is_alive: bool - alive status (default: True).
        """
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self):
        """
        Abstract method to change the alive status of the character to False.
        """
        pass


class Stark(Character):
    """
    A class representing a member of House Stark, inheriting from Character.
    """

    def __init__(self, first_name, is_alive=True):
        """
        Initialize a Stark character with a name and alive status.

        :param first_name: str - first name of the Stark.
        :param is_alive: bool - alive status of the Stark (default: True).
        :func: super() - allows to call the method of the parent/super class.
        """
        super().__init__(first_name, is_alive)

    def die(self):
        """
        Change the alive status of the Stark character to False.
        """
        self.is_alive = False
