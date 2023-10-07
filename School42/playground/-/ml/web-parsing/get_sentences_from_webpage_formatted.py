import requests
from bs4 import BeautifulSoup
import re

def get_sentences_from_webpage(url):
    try:
        response = requests.get(url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        paragraphs = soup.find_all('p')  # Assuming the paragraphs contain the content.

        sentences = []
        for paragraph in paragraphs:
            text = paragraph.get_text()
            # Split the text into sentences using a regular expression.
            sentences.extend(re.split(r'(?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s', text))

        return sentences
    except requests.exceptions.RequestException as e:
        print(f"Error fetching the webpage: {e}")
        return []

def save_sentences_to_file(sentences, output_file):
    with open(output_file, 'w', encoding='utf-8') as file:
        file.write("\n".join(sentences))

if __name__ == "__main__":
    # Replace the URL with the Wikipedia page you want to parse.
    url = 'https://en.wikipedia.org/wiki/Web_scraping'
    sentences = get_sentences_from_webpage(url)
    
    # Replace 'output_file.txt' with the desired file name.
    output_file = 'formatted_sentences_file.txt'
    save_sentences_to_file(sentences, output_file)
    print(f"Sentences saved to {output_file}.")
