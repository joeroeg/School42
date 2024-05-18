import random
from sympy import isprime, mod_inverse

def generate_prime(bits):
    """Generates a prime number of the given bit length."""
    while True:
        candidate = random.getrandbits(bits)  # Generate a random number with the specified bit length.
        candidate |= (1 << bits - 1) | 1      # Ensure the candidate is odd and has the correct bit length.
        if isprime(candidate):                # Check if the candidate is prime.
            return candidate                  # Return the prime number once found.


def generate_keypair(bits):
    """Generates RSA key pair with specified bit length."""
    p = generate_prime(bits // 2)
    print(p)
    q = generate_prime(bits // 2)
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 65537  # Common choice for e
    d = mod_inverse(e, phi)
    return (e, n), (d, n)

def encrypt(pk, plaintext):
    """Encrypts plaintext using the public key."""
    e, n = pk
    cipher = [pow(ord(char), e, n) for char in plaintext]
    return cipher

def decrypt(pk, ciphertext):
    """Decrypts ciphertext using the private key."""
    d, n = pk
    plain = [chr(pow(char, d, n)) for char in ciphertext]
    return ''.join(plain)

if __name__ == "__main__":
    bits = int(input("Enter the bit length for the keys: "))
    public, private = generate_keypair(bits)
    # print("Public key:", public)
    # print("Private key:", private)

    # message = input("Enter a message to encrypt: ")
    # encrypted_msg = encrypt(public, message)
    # print("Encrypted message:", encrypted_msg)

    # decrypted_msg = decrypt(private, encrypted_msg)
    # print("Decrypted message:", decrypted_msg)

