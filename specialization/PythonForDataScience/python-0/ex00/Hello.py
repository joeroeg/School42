ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello": "titi!"}


ft_list[1] = "World!"
ft_tuple = ("Hello", "Canada!")
ft_set.remove("tutu!")
ft_set.add("Quebec!")
ft_dict["Hello"] = "42Quebec!"


print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)

# https://docs.python.org/3/tutorial/datastructures.html#
# The point of this exercise is to show that:
# lists, tuples, sets and dictionaries are mutable and can be modified.
