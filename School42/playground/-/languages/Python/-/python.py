# from tensorflow import keras
# from typing import List
# from keras.preprocessing.text import Tokenizer

# sentence = ["John likes to watch movies. Mary likes movies too."]

# def print_bow(sentence: List[str]) -> None:
#     tokenizer = Tokenizer()
#     tokenizer.fit_on_texts(sentence)
#     sequences = tokenizer.texts_to_sequences(sentence)
#     word_index = tokenizer.word_index 
#     bow = {}
#     for key in word_index:
#         bow[key] = sequences[0].count(word_index[key])

#     print(f"Bag of word sentence 1:\n{bow}")
#     print(f"We found {len(word_index)} unique tokens.")

# print_bow(sentence)


import fitz  # PyMuPDF
from difflib import ndiff

def extract_text_from_pdf(pdf_path):
    doc = fitz.open(pdf_path)
    text = ""
    for page_num in range(doc.page_count):
        page = doc[page_num]
        text += page.get_text()
    doc.close()
    return text

def compare_and_show_differences(pdf1_path, pdf2_path):
    text1 = extract_text_from_pdf(pdf1_path)
    text2 = extract_text_from_pdf(pdf2_path)

    diff_lines = list(ndiff(text1.splitlines(), text2.splitlines()))

    for line in diff_lines:
        if line.startswith("- "):
            print(f"Removed: {line[2:]}")
        elif line.startswith("+ "):
            print(f"Added: {line[2:]}")
        elif line.startswith("? "):
            print(f"Changed: {line[2:]}")
        else:
            print(f"Unchanged: {line[2:]}")

if __name__ == "__main__":
    pdf1_path = "/home/device/Downloads/pdf_comparison/C_first_edition.pdf"
    pdf2_path = "/home/device/Downloads/pdf_comparison/C_second_edition.pdf"
    compare_and_show_differences(pdf1_path, pdf2_path)


