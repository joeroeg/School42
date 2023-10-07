from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.oauth2.credentials import Credentials  # Add this line
import os

# Set the scope to read and modify emails
SCOPES = ['https://mail.google.com/']

def main():
    creds = None
    # The file token.json stores the user's access and refresh tokens
    if os.path.exists('token.json'):
        creds = Credentials.from_authorized_user_file('token.json', SCOPES)
    # If there are no (valid) credentials available, let the user log in
    if not creds or not creds.valid:
        flow = InstalledAppFlow.from_client_secrets_file('client_secret_701573341166-5rg5qn39msvmggpmccjvtn8hv7t8cclc.apps.googleusercontent.com.json', SCOPES)
        creds = flow.run_local_server(port=0)
        # Save the credentials for the next run
        with open('token.json', 'w') as token:
            token.write(creds.to_json())

    # Build the Gmail API service
    service = build('gmail', 'v1', credentials=creds)

    # Delete emails based on search query
    search_query = "before:2023/08/01"
    results = service.users().messages().list(userId='me', q=search_query).execute()
    messages = results.get('messages', [])
    if not messages:
        print("No emails found.")
        return

    for message in messages:
        msg_id = message['id']
        service.users().messages().delete(userId='me', id=msg_id).execute()
        print(f"Deleted email with ID: {msg_id}")

if __name__ == '__main__':
    main()

