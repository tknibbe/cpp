#!/bin/bash

# Define a function to test RPN expressions
function test_rpn {
    local input="$1"       # First argument: the RPN expression
    local expected="$2"    # Second argument: the expected output

    # Display the input and expected output
    echo -e "\033[32mINPUT:\033[0m $input"
    echo -e "\033[32mEXPECTED OUTPUT:\033[0m $expected"

    # Capture the actual output by running the RPN program with the input
    output=$(./RPN "$input")

    # Display the actual output
    echo -e "\033[32mACTUAL OUTPUT:\033[0m $output"

    # Compare the actual output to the expected output
    if [[ "$output" == "$expected" ]]; then
        echo -e "\033[32m✔\033[0m Test passed!\n\n"
    else
        echo -e "\033[31m✘\033[0m Test failed!\n\n"
    fi
}

# Call the function with your example input and expected output
echo "SUBJECT EXAMPLES:\m"
test_rpn "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
test_rpn "7 7 * 7 -" "42"
test_rpn "1 2 * 2 / 2 * 2 4 - +" "0"

echo -e "\nMORE EXAMPLES:\n\n"
test_rpn "5 3 +" "8"
test_rpn "2 2 3 + *" "10"
test_rpn "7 2 -" "5"
test_rpn "4 5 6 + *" "44"
test_rpn "9 3 /" "3"
test_rpn "8 2 * 5 +" "21"

echo -e "\nINVALID EXAMPLES:\n" 
test_rpn "5 +" "" #empty string since error messages are printed on std::cerr
test_rpn "5 3 7" ""
test_rpn "5 0 /" ""
test_rpn "5 2 * +" ""
test_rpn "5 3 & +" ""