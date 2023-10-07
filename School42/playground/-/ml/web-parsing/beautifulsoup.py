#!/usr/bin/env python3
# Anchor extraction from HTML document
from bs4 import BeautifulSoup
from urllib.request import urlopen

with urlopen('https://en.wikipedia.org/wiki/Main_Page') as response:
    soup = BeautifulSoup(response, 'html.parser')
    extracted_sentences = []
    for anchor in soup.find_all('a'):
        href = anchor.get('href', '/')
        extracted_sentences.append(href)

# Saving the extracted sentences to a file.
with open("sentences.txt", "w", encoding="utf-8") as file:
    file.write("\n".join(extracted_sentences))
    print(f"Extracted {len(extracted_sentences)} sentences and saved to 'sentences.txt'.")
