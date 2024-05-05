#!/bin/bash

test_rpn() {
    expression="$1"
    expected_result="$2"
    result=$(./RPN "$expression")
    if [ "$result" == "$expected_result" ]; then
        echo "PASS: $expression = $result"
    else
        echo "FAIL: $expression expected $expected_result but got $result"
    fi
}

# Test cases
test_rpn "8 9 * 9 - 9 - 9 - 4 - 1 +" 42
test_rpn "7 7 * 7 -" 42
test_rpn "1 2 * 2 / 2 * 2 4 - +" 0
test_rpn "1 2 * 2 / 2 * 2 4 * +" 10
test_rpn "2 3 + 4 *" 20
test_rpn "5 5 + 5 /" 2
test_rpn "3 2 - 5 +" 6
test_rpn "9 3 / 2 *" 6
test_rpn "4 2 / 3 *" 6
test_rpn "2 3 * 5 +" 11
test_rpn "6 2 / 3 +" 6
test_rpn "1 2 + 3 4 + *" 21
test_rpn "1 2 * 3 4 * +" 14
test_rpn "1 2 3 * + 4 +" 11
test_rpn "1 2 3 + * 4 +" 9
test_rpn "1 2 3 + 4 + *" 9
test_rpn "1 2 3 4 5 6 7 8 9 + + + + + + + +" 45
test_rpn "1 2 3 4 5 6 7 8 9 - - - - - - - -" 5
test_rpn "1 2 3 4 5 6 7 8 9 + + + + + + + + 9 8 7 6 5 4 3 2 1 - - - - - - - - -" 40
test_rpn "1 2 3 4 5 6 7 8 9 * * * * * * * *" 362880
test_rpn "1 2 3 4 5 6 7 8 9 / / / / / / / /" 2.46094
test_rpn "8 9 * 9 - 9 - 9 - 4 - 1 +" 42
test_rpn "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" 42
test_rpn "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" 15
