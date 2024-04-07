#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

function test_case {
    input="$1"
    expected="$2"

    result=$(./RPN "$input" 2>&1)
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}Pass${NC}"
    else
        echo -e "${RED}Fail${NC}"
    fi
}


echo "Test Case 1:"
echo -n "$> ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\" "
test_case "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"

echo "Test Case 2:"
echo -n "$> ./RPN \"7 7 * 7 -\" "
test_case "7 7 * 7 -" "42"

echo "Test Case 3:"
echo -n "$> ./RPN \"1 2 * 2 / 2 * 2 4 - +\" "
test_case "1 2 * 2 / 2 * 2 4 - +" "0"

echo "Test Case 4:"
echo -n "$> ./RPN \"8 2 /\" "
test_case "8 2 /" "4"

echo "Test Case 5:"
echo -n "$> ./RPN \"2 3 + 4 *\" "
test_case "2 3 + 4 *" "20"

echo "Test Case 6:"
echo -n "$> ./RPN \"5 1 2 + 4 * + 3 -\" "
test_case "5 1 2 + 4 * + 3 -" "14"

echo "Test Case 7:"
echo -n "$> ./RPN \"7 3 /\" "
test_case "7 3 /" "2"

echo "Test Case 8:"
echo -n "$> ./RPN \"2 3 * 4 /\" "
test_case "2 3 * 4 /" "1"

echo "Test Case 9:"
echo -n "$> ./RPN \"5 2 / 3 +\" "
test_case "5 2 / 3 +" "5"

echo "Test Case 10:"
echo -n "$> ./RPN \"8 2 / 4 *\" "
test_case "8 2 / 4 *" "16"

echo "Test Case 11:"
echo -n "$> ./RPN \"7 5 - 3 +\" "
test_case "7 5 - 3 +" "5"

echo "Test Case 12:"
echo -n "$> ./RPN \"6 2 + 3 -\" "
test_case "6 2 + 3 -" "5"

echo "Test Case 13:"
echo -n "$> ./RPN \"9 3 / 2 *\" "
test_case "9 3 / 2 *" "6"

echo "Test Case 14:"
echo -n "$> ./RPN \"7 2 * 5 /\" "
test_case "7 2 * 5 /" "2"

echo "Test Case 15:"
echo -n "$> ./RPN \"4 2 * 2 *\" "
test_case "4 2 * 2 *" "16"

echo "Test Case 16:"
echo -n "$> ./RPN \"8 4 / 2 /\" "
test_case "8 4 / 2 /" "1"

echo "Test Case 17:"
echo -n "$> ./RPN \"3 4 + 5 -\" "
test_case "3 4 + 5 -" "2"

echo "Test Case 18:"
echo -n "$> ./RPN \"6 3 / 2 *\" "
test_case "6 3 / 2 *" "4"

echo "Test Case 19:"
echo -n "$> ./RPN \"5 3 +\" "
test_case "5 3 +" "8"

echo "Test Case 20:"
echo -n "$> ./RPN \"7 2 * 4 /\" "
test_case "7 2 * 4 /" "3"

echo "Test Case 21:"
echo -n "$> ./RPN \"9 3 / 2 *\" "
test_case "9 3 / 2 *" "6"

echo "Test Case 19:"
echo -n "$> ./RPN \"5 3 + 4 * 6 /\" "
test_case "5 3 + 4 * 6 /" "5"

echo "Test Case 20:"
echo -n "$> ./RPN \"7 2 * 4 / 3 + 2 -\" "
test_case "7 2 * 4 / 3 + 2 -" "4"

echo "Test Case 21:"
echo -n "$> ./RPN \"9 3 / 2 * 5 + 1 -\" "
test_case "9 3 / 2 * 5 + 1 -" "10"

echo "Test Case 22:"
echo -n "$> ./RPN \"8 2 / 4 * 7 - 3 +\" "
test_case "8 2 / 4 * 7 - 3 +" "12"

echo "Test Case 23:"
echo -n "$> ./RPN \"6 2 + 3 - 2 * 5 /\" "
test_case "6 2 + 3 - 2 * 5 /" "2"

echo "Test Case 24:"
echo -n "$> ./RPN \"4 2 * 2 * 3 - 6 / 7 -\" "
test_case "4 2 * 2 * 3 - 6 / 7 -" "-5"

echo "Test Case 25:"
echo -n "$> ./RPN \"8 4 / 2 / 1 + 3 *\" "
test_case "8 4 / 2 / 1 + 3 *" "6"

echo "Test Case 26:"
echo -n "$> ./RPN \"3 4 + 5 - 6 * 2 / 8 -\" "
test_case "3 4 + 5 - 6 * 2 / 8 -" "-2"

echo "Test Case 27:"
echo -n "$> ./RPN \"6 3 / 2 * 4 - 1 +\" "
test_case "6 3 / 2 * 4 - 1 +" "1"