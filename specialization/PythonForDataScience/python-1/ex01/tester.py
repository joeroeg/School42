"""Tester."""


from array2D import slice_me

family = [[1.80, 78.4], [2.15, 102.7], [2.10, 98.5], [1.88, 75.2]]

print(f"My shape is : ({len(family)}, {len(family[0])})")
print(f"My new shape is : ({len(slice_me(family, 0, 2))}, {len(family[0])})")
print(slice_me(family, 0, 2))
print()
print(f"My shape is : ({len(family)}, {len(family[0])})")
print(f"My new shape is : ({len(slice_me(family, 1, -2))}, {len(family[0])})")
print(slice_me(family, 1, -2))
