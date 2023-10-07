import sys

def chunk_text(text, chunk_size):
    return [text[i:i+chunk_size] for i in range(0, len(text), chunk_size)]

file_name = sys.argv[1]  # get the file name from the command line
chunk_size = 1000  # adjust this to the size you want

with open(file_name, 'r') as f:
    text = f.read()

chunks = chunk_text(text, chunk_size)

# Now chunks is a list of strings, each with a length of chunk_size or less
for i, chunk in enumerate(chunks):
    with open(f"chunk_{i+1}.txt", 'w') as f:
        f.write(chunk)
