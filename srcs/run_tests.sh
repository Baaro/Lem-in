#!/bin/bash	
arr_valid=(./tests/valid/*)
arr_unvalid=(./tests/unvalid/*)
test=./test

for ((i = 0; i < ${#arr_valid[@]}; i++)); do {
    echo "--VALID_test_$i--";
    ${test} < ${arr_valid[$i]};
    printf "\n"
}
done
printf "\n"
for ((i = 0; i < ${#arr_unvalid[@]}; i++)); do {
    echo "--UNVALID_test_$i--";
    ${test} < ${arr_unvalid[$i]};
    printf "\n"
}
done
