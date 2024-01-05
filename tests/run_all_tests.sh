# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_all_tests.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 13:24:20 by vketteni          #+#    #+#              #
#    Updated: 2024/01/05 17:45:27 by vketteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE_42=42

TEST_TYPE=("nl" "no_nl" "only_nl")
TOTAL_BYTES_IN_FILE=("41" "42" "43")


echo -e "\e[1;31m*************************\e[0m"
echo -e "\e[1;31m*      START TESTS      *\e[0m"
echo -e "\e[1;31m*************************\e[0m"

for BYTES in ${TOTAL_BYTES_IN_FILE[@]}; do
    printf "\e[1;30mTest: \e[0;1m${BYTES}_${TEST_TYPE[0]} \e[1;30mwith \e[0;1mBUFFER_SIZE=$BUFFER_SIZE_42\e[0m\n"
    tests/gnl_test.sh $BUFFER_SIZE_42 ${BYTES}_${TEST_TYPE[0]} $1
    echo -e "\e[1;31m*************************\e[0m"
    TEST_NAME="41_with_nl"
    printf "\e[1;30mTest: \e[0;1m${BYTES}_${TEST_TYPE[1]} \e[1;30mwith \e[0;1mBUFFER_SIZE=$BUFFER_SIZE_42\e[0m\n"
    tests/gnl_test.sh $BUFFER_SIZE_42 ${BYTES}_${TEST_TYPE[1]} $1
    echo -e "\e[1;31m*************************\e[0m"
    TEST_NAME="41_only_nl"
    printf "\e[1;30mTest: \e[0;1m${BYTES}_${TEST_TYPE[2]} \e[1;30mwith \e[0;1mBUFFER_SIZE=$BUFFER_SIZE_42\e[0m\n"
    tests/gnl_test.sh $BUFFER_SIZE_42 ${BYTES}_${TEST_TYPE[2]} $1
    echo -e "\e[1;31m*************************\e[0m"
done

BUFFER_SIZES=(1 2 10 1024 131072 1048576)

for BUFFER_SIZE in ${BUFFER_SIZES[@]}; do
    printf "\e[1;30mTest: \e[0;1m42_${TEST_TYPE[0]} \e[1;30mwith \e[0;1mBUFFER_SIZE=$BUFFER_SIZE\e[0m\n"
    tests/gnl_test.sh $BUFFER_SIZE "42_${TEST_TYPE[1]}" $1
    echo -e "\e[1;31m*************************\e[0m"
    TEST_NAME="41_with_nl"
    printf "\e[1;30mTest: \e[0;1m42_${TEST_TYPE[1]} \e[1;30mwith \e[0;1mBUFFER_SIZE=$BUFFER_SIZE\e[0m\n"
    tests/gnl_test.sh $BUFFER_SIZE "42_${TEST_TYPE[1]}" $1
    echo -e "\e[1;31m*************************\e[0m"
    TEST_NAME="41_only_nl"
    printf "\e[1;30mTest: \e[0;1m42_${TEST_TYPE[2]} \e[1;30mwith \e[0;1mBUFFER_SIZE=$BUFFER_SIZE\e[0m\n"
    tests/gnl_test.sh $BUFFER_SIZE "42_${TEST_TYPE[2]}" $1
    echo -e "\e[1;31m*************************\e[0m"
done