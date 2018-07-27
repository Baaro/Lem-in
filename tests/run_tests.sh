#!/bin/bash	
arr_unvalid=(./tests/unvalid/*)
test=./lem-in

printf "\n"
for ((i = 0; i < ${#arr_unvalid[@]}; i++)); do {
    echo "--UNVALID_test_$i--";
    ${test} < ${arr_unvalid[i]};
    printf "\n"
}
done
