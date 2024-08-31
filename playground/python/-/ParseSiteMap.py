import requests
import csv
import hashlib
import time
import xml.etree.ElementTree as ET

def monitor_changes(urls, interval=3600):
    page_hashes = {}

    while True:
        for url in urls:
            try:
                response = requests.get(url)
                content = response.text
                current_hash = hashlib.md5(content.encode('utf-8')).hexdigest()

                if url in page_hashes:
                    if page_hashes[url] != current_hash:
                        print(f"Change detected on {url}")

                page_hashes[url] = current_hash
            except requests.RequestException as e:
                print(f"Error checking {url}: {e}")

        time.sleep(interval)

def save_urls_to_csv(urls, filename='urls.csv'):
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['URL'])
        for url in urls:
            writer.writerow([url])

def check_links(urls):
    for url in urls:
        try:
            response = requests.head(url, allow_redirects=True)
            if response.status_code != 200:
                print(f"Broken link: {url} (Status code: {response.status_code})")
        except requests.RequestException as e:
            print(f"Error checking {url}: {e}")

def parse_sitemap(sitemap_url):
    response = requests.get(sitemap_url)
    sitemap_content = response.content

    # Parse XML content
    root = ET.fromstring(sitemap_content)

    # Define the namespace
    namespace = {'ns': 'http://www.sitemaps.org/schemas/sitemap/0.9'}

    # Extract URLs
    urls = []
    for url in root.findall('ns:url', namespace):
        loc = url.find('ns:loc', namespace)
        if loc is not None and loc.text is not None:
            urls.append(loc.text)

    return urls

# URL of the sitemap
sitemap_url = 'https://www.canada.ca/en/immigration-refugees-citizenship.sitemap.xml'

# Extract and print URLs
urls = parse_sitemap(sitemap_url)

# Save URLs to a CSV file
save_urls_to_csv(urls, 'sitemap_urls.csv')

# Check links
# check_links(urls)

# Monitor changes every minute
monitor_changes(urls, interval=60)
