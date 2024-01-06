# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_all_tests.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 13:24:20 by vketteni          #+#    #+#              #
#    Updated: 2024/01/05 23:17:10 by vketteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE_42=42

TEST_TYPE=("nl" "no_nl" "only_nl")
TOTAL_BYTES_IN_FILE=("41" "42" "43")


RED=$(tput setaf 1)
RESET=$(tput sgr0)

echo -e "${RED}*************************${RESET}"
echo -e "${RED}*      START TESTS      *${RESET}"
echo -e "${RED}*************************${RESET}"

for BYTES in ${TOTAL_BYTES_IN_FILE[@]}; do
	printf "$(tput setaf 12)Test: $(tput sgr0)$(tput bold)${BYTES}_${TEST_TYPE[0]} $(tput setaf 12)with $(tput sgr0)$(tput bold)BUFFER_SIZE=$BUFFER_SIZE_42$(tput sgr0)\n"
	tests/gnl_test.sh $BUFFER_SIZE_42 ${BYTES}_${TEST_TYPE[0]} $1
	echo -e "$(tput setaf 1)*************************$(tput sgr0)"
	TEST_NAME="41_with_nl"
	printf "$(tput setaf 12)Test: $(tput sgr0)$(tput bold)${BYTES}_${TEST_TYPE[1]} $(tput setaf 12)with $(tput sgr0)$(tput bold)BUFFER_SIZE=$BUFFER_SIZE_42$(tput sgr0)\n"
	tests/gnl_test.sh $BUFFER_SIZE_42 ${BYTES}_${TEST_TYPE[1]} $1
	echo -e "$(tput setaf 1)*************************$(tput sgr0)"
	TEST_NAME="41_only_nl"
	printf "$(tput setaf 12)Test: $(tput sgr0)$(tput bold)${BYTES}_${TEST_TYPE[2]} $(tput setaf 12)with $(tput sgr0)$(tput bold)BUFFER_SIZE=$BUFFER_SIZE_42$(tput sgr0)\n"
	tests/gnl_test.sh $BUFFER_SIZE_42 ${BYTES}_${TEST_TYPE[2]} $1
	echo -e "$(tput setaf 1)*************************$(tput sgr0)"
done

BUFFER_SIZES=(1 2 10 1024 131072 1048576)

for BUFFER_SIZE in ${BUFFER_SIZES[@]}; do
	printf "$(tput setaf 12)Test: $(tput sgr0)$(tput bold)42_${TEST_TYPE[0]} $(tput setaf 12)with $(tput sgr0)$(tput bold)BUFFER_SIZE=$BUFFER_SIZE$(tput sgr0)\n"
	tests/gnl_test.sh $BUFFER_SIZE "42_${TEST_TYPE[1]}" $1
	echo -e "$(tput setaf 1)*************************$(tput sgr0)"
	TEST_NAME="41_with_nl"
	printf "$(tput setaf 12)Test: $(tput sgr0)$(tput bold)42_${TEST_TYPE[1]} $(tput setaf 12)with $(tput sgr0)$(tput bold)BUFFER_SIZE=$BUFFER_SIZE$(tput sgr0)\n"
	tests/gnl_test.sh $BUFFER_SIZE "42_${TEST_TYPE[1]}" $1
	echo -e "$(tput setaf 1)*************************$(tput sgr0)"
	TEST_NAME="41_only_nl"
	printf "$(tput setaf 12)Test: $(tput sgr0)$(tput bold)42_${TEST_TYPE[2]} $(tput setaf 12)with $(tput sgr0)$(tput bold)BUFFER_SIZE=$BUFFER_SIZE$(tput sgr0)\n"
	tests/gnl_test.sh $BUFFER_SIZE "42_${TEST_TYPE[2]}" $1
	echo -e "$(tput setaf 1)*************************$(tput sgr0)"
done