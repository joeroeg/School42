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

  # Extract results from the response
  # Check if the response is an array
  if echo "$RESPONSE" | jq -e 'type == "array"' > /dev/null; then
    RESULTS="$RESPONSE"
  else
    # If the response is an object, extract the 'results' field
    RESULTS=$(echo "$RESPONSE" | jq '.results')
  fi

  # Check if results are empty
  if [ "$RESULTS" == "[]" ]; then
    echo "No more data found."
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
