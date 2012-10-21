#!/bin/bash

show_error_and_exit(){
    local test_file="$1"
    local code="$2"
    echo "Error passing test $test_file"
    exit $code
}

tests_dir="tests"
table="conjunction"
n=0

for file in tests/${table}_?
do
    test_file="$file"
    bin/turing_machine -f tables/${table} -n200 -o10 < ${test_file} > ${test_file}_result
    cmp ${test_file}_result ${test_file}_answer
    assertion_error=$?
    if [[ $assertion_error != 0 ]]; then
        show_error_and_exit "$test_file" "$assertion_error"
    fi
    n=$((n + 1))
done
echo "$n tests are successfully passed."
