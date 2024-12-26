import random
import string
from dataclasses import dataclass, field


def generate_id() -> str:
    return "".join(random.choices(string.ascii_lowercase, k=15))

def generate_login(name: str, surname: str) -> str:
    return f"{name[:1]}{surname}"

@dataclass
class Student:
    name: str = field(init=True)
    surname: str = field(init=True)
    active: bool = field(default=True)
    login: str = generate_login(name, surname)
    ids: str = field(init=False, default=generate_id())

    # def __post_init__(self) -> None:
    #     self.login = f"{self.name[:1]}{self.surname}"
