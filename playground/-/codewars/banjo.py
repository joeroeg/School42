def plays_banjo(name):
    name = input("Enter your name: ")
    if name.startswith("R") or name.startswith("r"):
        return name + " plays banjo"
    else:


print(plays_banjo("Ricky"))
print(plays_banjo("Molly"))
