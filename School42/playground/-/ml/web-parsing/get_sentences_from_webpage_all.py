import requests
from bs4 import BeautifulSoup
import re

def get_sentences_from_webpage(url):
    # Send a GET request to the webpage and get its content
    response = requests.get(url)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch the webpage. Status code: {response.status_code}")

    # Parse the HTML content using BeautifulSoup
    soup = BeautifulSoup(response.content, 'html.parser')

    # Extract all the text content from the webpage
    text_content = soup.get_text()

    # Split the text into sentences using a regular expression
    # Note: This regex might not be perfect for all cases, but it should work for many scenarios.
    # Depending on the complexity of the webpage, you might need to fine-tune the regex.
    sentences = re.split(r'(?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s', text_content)

    # Remove empty and whitespace-only sentences
    sentences = [sentence.strip() for sentence in sentences if sentence.strip()]

    return sentences

if __name__ == "__main__":
    # Replace this URL with the Wikipedia page or any webpage you want to parse
    wikipedia_url = "https://en.wikipedia.org/wiki/Web_scraping"
    sentences = get_sentences_from_webpage(wikipedia_url)

    # Save the sentences to a file
    with open("all_sentences.txt", "w", encoding="utf-8") as file:
        file.write("\n".join(sentences))

    print(f"Extracted {len(sentences)} sentences and saved to 'sentences.txt'.")
