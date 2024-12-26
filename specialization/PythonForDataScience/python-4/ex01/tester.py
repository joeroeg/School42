from in_out import outer
from in_out import square
from in_out import pow

my_counter = outer(3, square)
print(my_counter())
print(outer(3, square))
print(my_counter())
print(outer(3, square))
print(my_counter())
print(outer(3, square))
print("---")
my_counter = outer(2, square)
print(my_counter())
print(outer(2, square))
print(my_counter())
print(outer(2, square))
print(my_counter())
print(outer(2, square))
# print("---")
# another_counter = outer(1.5, pow)
# print(another_counter())
# print(another_counter())
# print(another_counter())
