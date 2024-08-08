#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Function to run a single test
run_test() {
    description=$1
    pipex_command=$2
    shell_command=$3
    input_file=$4
    output_file=$5

    echo -e "${CYAN}${BOLD}Running Test:${NC} $description"

    # Run the pipex command
    eval $pipex_command

    # Run the equivalent shell command
    eval $shell_command

    # Compare the outputs
    if diff "$output_file" shell_outfile.txt > /dev/null; then
        echo -e "${GREEN}${BOLD}Test Passed${NC}"
    else
        echo -e "${RED}${BOLD}Test Failed${NC}"
    fi

    # Clean up
    rm -f shell_outfile.txt "$output_file"
}

# Header
echo -e "${YELLOW}${BOLD}Starting pipex Tests${NC}"

# Create input files
echo -e "this is a line\nthis is another line\nno match here" > infile.txt
echo -e "" > empty_file.txt
echo -e "this is a line\nthis is another line\nno match here" > no_permission_file.txt
chmod 000 no_permission_file.txt

# Test cases

# Basic Functionality Test
run_test "Basic Functionality" \
    "./pipex infile.txt \"grep this\" \"wc -l\" pipex_outfile.txt" \
    "< infile.txt grep this | wc -l > shell_outfile.txt" \
    infile.txt pipex_outfile.txt

# Incorrect Number of Arguments
echo -e "${CYAN}${BOLD}Running Test:${NC} Incorrect Number of Arguments"
if ./pipex infile.txt "grep this" "wc -l"; then
    echo -e "${RED}${BOLD}Test Failed${NC}"
else
    echo -e "${GREEN}${BOLD}Test Passed${NC}"
fi

# Non-existing Input File
echo -e "${CYAN}${BOLD}Running Test:${NC} Non-existing Input File"
if ./pipex non_existing_file.txt "grep this" "wc -l" pipex_outfile.txt; then
    echo -e "${RED}${BOLD}Test Failed${NC}"
else
    echo -e "${GREEN}${BOLD}Test Passed${NC}"
fi

# No Permission on Input File
echo -e "${CYAN}${BOLD}Running Test:${NC} No Permission on Input File"
if ./pipex no_permission_file.txt "grep this" "wc -l" pipex_outfile.txt; then
    echo -e "${RED}${BOLD}Test Failed${NC}"
else
    echo -e "${GREEN}${BOLD}Test Passed${NC}"
fi
chmod 644 no_permission_file.txt  # Reset permissions for cleanup

# Non-existing Command
echo -e "${CYAN}${BOLD}Running Test:${NC} Non-existing Command"
if ./pipex infile.txt "non_existing_command" "wc -l" pipex_outfile.txt; then
    echo -e "${RED}${BOLD}Test Failed${NC}"
else
    echo -e "${GREEN}${BOLD}Test Passed${NC}"
fi

# Empty Input File
run_test "Empty Input File" \
    "./pipex empty_file.txt \"grep this\" \"wc -l\" pipex_outfile.txt" \
    "< empty_file.txt grep this | wc -l > shell_outfile.txt" \
    empty_file.txt pipex_outfile.txt

# Additional Tests

# Test Case: grep and sort
run_test "grep and sort" \
    "./pipex infile.txt \"grep this\" \"sort\" pipex_outfile.txt" \
    "< infile.txt grep this | sort > shell_outfile.txt" \
    infile.txt pipex_outfile.txt

# Test Case: cat and grep
run_test "cat and grep" \
    "./pipex infile.txt \"cat\" \"grep line\" pipex_outfile.txt" \
    "< infile.txt cat | grep line > shell_outfile.txt" \
    infile.txt pipex_outfile.txt

# Test Case: grep and awk
run_test "grep and awk" \
    "./pipex infile.txt \"grep this\" \"awk '{print \$1}'\" pipex_outfile.txt" \
    "< infile.txt grep this | awk '{print \$1}' > shell_outfile.txt" \
    infile.txt pipex_outfile.txt

# Test Case: grep with multiple words
echo -e "this is a test\nthis is another test\njust a test" > infile_multiple.txt
run_test "grep multiple words" \
    "./pipex infile_multiple.txt \"grep 'this is'\" \"wc -l\" pipex_outfile.txt" \
    "< infile_multiple.txt grep 'this is' | wc -l > shell_outfile.txt" \
    infile_multiple.txt pipex_outfile.txt

# Clean up input files
rm -f infile.txt empty_file.txt no_permission_file.txt infile_multiple.txt

# Footer
echo -e "${YELLOW}${BOLD}All tests completed.${NC}"
