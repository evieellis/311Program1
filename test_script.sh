#!/bin/bash

# Written by Evelyn Ellis

# this script automates the testing of the sloppySim program with different configurations
# to assess its behavior under various conditions

# function to run tests
run_test() {
    #echo "Running test with $1 threads, Sloppiness=$2, Work_Time=$3 ms, Work_Iterations=$4,
    #CPU_Bound=$5, Do_Logging=$6"
    time ./sloppySim $1 $2 $3 $4 $5 $6
    echo "--------------------------------------------------------"
}

# test scenarios
run_test #default
run_test 2 10 10 100 false false  # small number of threads, I/O bound
run_test 4 5 11 100 true true  # medium number of threads, CPU bound
run_test 4 5 11 100 false true  # moderate number of threads, I/O bound with logging
run_test 80 5 11 100 true true  # large number of threads, CPU bound with logging