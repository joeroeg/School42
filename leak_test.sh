#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NO_COLOR='\033[0m'

PROGRAM="./cub3D"
MAPS_DIR="./maps"

INPUT_PARAMS=($(find $MAPS_DIR -type f -name "*.cub"))


# Initialize counters
COUNTER=0
SUCCESS_COUNT=0
TOTAL_COUNT=0

# Loop through all input parameters/test cases
for PARAM in "${INPUT_PARAMS[@]}"; do
    TOTAL_COUNT=$((TOTAL_COUNT + 1))
    SAFE_PARAM="test_${COUNTER}"
    COUNTER=$((COUNTER + 1))
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --suppressions=./suppressions.supp $PROGRAM $PARAM > "/tmp/valgrind_output_${SAFE_PARAM}.txt" 2>&1
    if ! grep "file descriptor" "/tmp/valgrind_output_${SAFE_PARAM}.txt" | awk '/file descriptor [34567]:/ {print; f=1} END {exit !f}' && \
       ! grep -q "Invalid read of size" "/tmp/valgrind_output_${SAFE_PARAM}.txt" && \
       ! grep -q "Invalid write of size" "/tmp/valgrind_output_${SAFE_PARAM}.txt" && \
       ! grep -q "invalid file descriptor" "/tmp/valgrind_output_${SAFE_PARAM}.txt" && \
       ! grep -q "Warning: invalid file descriptor" "/tmp/valgrind_output_${SAFE_PARAM}.txt" && \
       grep -q "definitely lost: 0 bytes in 0 blocks" "/tmp/valgrind_output_${SAFE_PARAM}.txt" && \
       grep -q "indirectly lost: 0 bytes in 0 blocks" "/tmp/valgrind_output_${SAFE_PARAM}.txt" && \
       grep -q "possibly lost: 0 bytes in 0 blocks" "/tmp/valgrind_output_${SAFE_PARAM}.txt"; then
        echo -e "${GREEN}✅ Test ${COUNTER}: $PARAM${NO_COLOR}"
        SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
    else
        echo -e "${RED}❌ Test ${COUNTER}: $PARAM${NO_COLOR}"
        echo "Debugging output for Test ${COUNTER}:"
        cat "/tmp/valgrind_output_${SAFE_PARAM}.txt"
    fi
done
if [ "$SUCCESS_COUNT" -eq "$TOTAL_COUNT" ]; then
    echo -e "${GREEN}Final Result: ${SUCCESS_COUNT}/${TOTAL_COUNT} (All tests passed)${NO_COLOR}"
else
    echo -e "${RED}Final Result: ${SUCCESS_COUNT}/${TOTAL_COUNT} (Some tests failed)${NO_COLOR}"
fi
