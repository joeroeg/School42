import base64

def decode_base64(base64_string):
    try:
        # Add padding if necessary
        padding = len(base64_string) % 4
        if padding != 0:
            base64_string += '=' * (4 - padding)

        # Decode the Base64 string
        decoded_bytes = base64.b64decode(base64_string)
        # Convert the decoded bytes to a string
        decoded_string = decoded_bytes.decode('utf-8')
        return decoded_string
    except Exception as e:
        print(f"Error decoding Base64: {str(e)}")
        return None

# Example usage
base64_string = "SGVsbG8gV29ybGQ"
decoded_string = decode_base64(base64_string)
print(decoded_string)
