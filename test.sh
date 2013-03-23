#!/bin/bash

show_error_and_exit(){
    local code="$1"
    exit $code
}

tests_dir="tests"
n=0
for table in conjunction logical_conjunction subtraction
do
    echo "$table testing"
    echo
    for file in tests/${table}_?
    do
        test_file="$file"
        echo "Test:"
        cat ${test_file}
        echo
        bin/turing_machine -f tables/${table} -n400 -o10 < ${test_file} > ${test_file}_result
        echo "Result:"
        cat ${test_file}_result
        echo
        echo "Answer:"
        cat ${test_file}_answer
        echo
        cmp ${test_file}_result ${test_file}_answer
        assertion_error=$?
        if [[ $assertion_error != 0 ]]; then
            show_error_and_exit $assertion_error
        fi
        n=$((n + 1))
        echo "OK"
        echo
    done
done
echo "$n tests are successfully passed."
