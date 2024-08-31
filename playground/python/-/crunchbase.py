# import requests

# api_key = ""
# base_url = "https://api.crunchbase.com/api/v4/entities/organizations"

# params = {
#     "user_key": api_key,
#     "location_country_code": "Canada",  # Use the appropriate country code
#     "limit": 1,  # Adjust this limit based on your needs and API tier
#     "page": 1
# }

# all_organizations = []
# while True:
#     response = requests.get(base_url, params=params)
#     if response.status_code == 200:
#         data = response.json()
#         all_organizations.extend(data['data']['items'])  # Store the current page’s results

#         # If there's a next page, continue
#         if "next_page_url" in data['metadata'] and data['metadata']['next_page_url']:
#             params['page'] += 1
#         else:
#             break
#     else:
#         print(f"Error: {response.status_code}, {response.text}")
#         break

# print(f"Found {len(all_organizations)} organizations in the specified country.")


import requests

url = "https://api.crunchbase.com/v4/data/searches/organizations"

headers = {
    "accept": "application/json",
    "content-type": "application/json",
    "X-cb-user-key": ""
}

response = requests.post(url, headers=headers)

print(response.text)
