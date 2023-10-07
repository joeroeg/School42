import concurrent.futures

def factorial(n):
    result = 1
    if n != 0:
        for i in range(1, n + 1):
            result *= i
    return result

input_values = [1000000, 2000000, 3000000, 4000000, 5000000]

# Use a ThreadPoolExecutor to compute the factorials in parallel
with concurrent.futures.ThreadPoolExecutor() as executor:
    factorials = list(executor.map(factorial, input_values))

# Print the results
for n, f in zip(input_values, factorials):
    print(f"The factorial of {n} is {f}")


