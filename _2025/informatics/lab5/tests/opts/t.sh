#!/bin/bash


PR="/home/Cyber_Wolf/Programs/5_university/informatics/lab5/out"
test_root="/home/Cyber_Wolf/Programs/5_university/informatics/lab5/tests/opts"

BLUE="\e[94m"
GREEN="\e[32m"
ORANGE="\e[208;33m"
RED="\e[31m"
RESER_COLOR="\e[0m"

check() {
    echo -n "$(basename $2): "

    $1 &> "$test_root/tmp"

    r=$(diff $test_root/tmp $2)

    if [[ $r == "" ]]; then
        echo -e "${GREEN}OK!${RESER_COLOR}"
    else
        echo -e "${RED}FAIL!${RESER_COLOR}"
    fi
}



##################################################=-> Test opt: -i <-=##################################################



# test 1

c="$PR -i bin,gh"
test_file="$test_root/1_i"

check "${c}" $test_file



# test 1

c="$PR -i txt,gh"
test_file="$test_root/1_i"

check "${c}" $test_file
