#!/bin/bash

# Define variables
API_URL=""
AUTH_TOKEN=""
PAGE=1
OUTPUT_FILE="device_logs.json"

# Initialize output file
echo "[" > "$OUTPUT_FILE"

while true; do
  # Fetch the current page
  RESPONSE=$(curl -s -X GET "$API_URL&page=$PAGE" \
    -H "Authorization: Bearer $AUTH_TOKEN" \
    -H "accept: application/json")

  # Print raw response for debugging
  echo "Response for page $PAGE: $RESPONSE"

  # Validate if RESPONSE is a non-empty JSON
  if [ -z "$RESPONSE" ] || ! echo "$RESPONSE" | jq . > /dev/null 2>&1; then
    echo "Invalid or empty response received."
    break
  fi

  # Extract results from the response
  RESULTS=$(echo "$RESPONSE" | jq '.results // empty')

  # Check if results are null or empty
  if [ -z "$RESULTS" ] || [ "$RESULTS" == "[]" ]; then
    echo "No more data found or invalid response format."
    break
  fi

  # Append results to output file
  echo "$RESULTS" | jq -c '.[]' >> "$OUTPUT_FILE"

  # Move to the next page
  PAGE=$((PAGE + 1))
  echo "Fetched page $PAGE"
done

# Close the JSON array
echo "]" >> "$OUTPUT_FILE"
