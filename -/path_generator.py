base_directory = "./textures/"
extension = ".png"
filler_length = 255 - len(base_directory) - len(extension)  # Calculate remaining length for filler
filler = 'a' * filler_length  # Use 'a' as the filler character

max_length_path = base_directory + filler + extension
print(f"Path Length: {len(max_length_path)}")
print(max_length_path)
