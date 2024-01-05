# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:16:32 by vketteni          #+#    #+#              #
#    Updated: 2024/01/05 12:24:10 by vketteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 	inspired by: 
#	https://github.com/Glagan/42-ft_printf/blob/master/test.sh 

BUFFER_SIZE=$1
TEST_NAME=$2

# compile main
printf "\e[1;32mCompile\n"
gcc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=$BUFFER_SIZE -D INPUT_FILE="\"tests/${TEST_NAME}.txt\"" -o gnl_main

# get result
./gnl_main > $TEST_NAME 2> /dev/null &

# check leaks
printf "\e[1;33mLeaks ? "
leaks gnl_main > leaks.res 2> /dev/null
show_leaks=0
if grep "ROOT LEAK" < leaks.res > /dev/null 2> /dev/null ; then
	printf "\e[0;31mLEAKS\n\e[0m"
	show_leaks=1
else
	printf "\e[0;32mNO LEAKS\n\e[0m"
fi
pid=$( pgrep gnl_main )

# format result and expected
cat -e $TEST_NAME > ${TEST_NAME}.res
cat -e tests/${TEST_NAME}.txt > ${TEST_NAME}.exp

# diff
printf "\e[1;36mResult\n\e[0;36m"
if [[ $3 = "f" ]] || [[ $3 = "full" ]]; then
	diff -y --text ${TEST_NAME}.exp $TEST_NAME.res
else
	diff -y --suppress-common --text ${TEST_NAME}.exp $TEST_NAME.res
fi

# clean
rm -f ${TEST_NAME}.res
rm -f ${TEST_NAME}.exp
rm -f $TEST_NAME
rm -f gnl_main 

# leaks result
if [[ $show_leaks = 1 ]]; then
	printf "\e[1;31mLeaks Result\ne[1;30m"
	cat leaks.res
fi
rm -f leaks.res

printf "\e[1;32mDone\n\e[0m"