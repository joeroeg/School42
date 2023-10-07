def factorize(n):
    def is_factor(d):
        return n % d == 0
    
    factors = []
    for i in range(1, int(n**0.5) + 1):
        if is_factor(i):
            factors.append(i)
            if i*i != n:  # if not a perfect square
                factors.append(n//i)
    return factors

# test the function
n = 150
print(factorize(n))
