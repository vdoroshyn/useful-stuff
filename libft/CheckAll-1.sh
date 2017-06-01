# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CheckAll                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkovalch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 10:21:59 by dkovalch          #+#    #+#              #
#    Updated: 2016/12/06 18:34:39 by dkovalch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/sh

#Colorcodes
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)

#Checking existence of the author file
printf "Author file:\t"
if [ -f libft/author ];
then
	Fls=$(ls libft/*.c)
	Auth=$(cat -e "libft/author")
	if [ "$Auth" != "" ]
	then
		printf "${GREEN}[OK]${NORMAL} "
	else
		printf "${RED}[Empty]${NORMAL} "
	fi
	Th=$(whoami | cat -e)
	if [ $Auth = $Th ]
	then
		printf "${GREEN}[OK]${NORMAL} "
	else
		printf "${RED}[Who are you?]${NORMAL}"
	fi
	for word in $Fls;
	do
		Tt=$(cat "$word" | grep "By: ")
		if [ "$Tt" = "" ]
		then
			printf "${RED}[No header in $word]${NORMAL}stopping the check...\n"
			break
		else
			Temp=$(cat "$word" | grep "By: " | cut -f2 -d ":" | sed 's/^ //g' | cut -f1 -d " "| cat -e)
			if [ "$Auth" != "$Temp" ]
			then
				printf "${RED}[Different logins]${NORMAL}stopping the check...\n\t$Auth is not $Temp in $word\n"
				break
			fi
		fi
	done
else
	echo "${RED}[No file!]${NORMAL}"
fi

#Checking Makefile
printf "\nMakefile:\t"
if [ -f libft/Makefile ];
then
	#Wildcards test
	Auth=$(cat "libft/Makefile" | grep "*.c")
	if [ "$Auth" != "" ]
	then
		printf "${RED}[Wildcards] ${NORMAL}"
	else
		printf "${GREEN}[OK]${NORMAL} "
	fi
	#Flags
	Temp=$(cat "libft/Makefile" | grep "\-Wall" | grep "\-Werror" | grep "\-Wextra")
	if [ "$Temp" = "" ]
	then
		printf "${RED}[No flags] ${NORMAL}"
	else
		printf "${GREEN}[OK]${NORMAL} "
	fi
	#Recompile
	Temp=$(make -C libft -f Makefile > /dev/null && make -C libft -f Makefile | grep "Nothing to be done for")
	if [ "$Temp" = "" ]
	then
		printf "${RED}[Recompile] ${NORMAL}"
	else
		printf "${GREEN}[OK]${NORMAL} "
	fi
	#clean
	Obj=$(ls libft/*.o)
	All=$(ls -l libft/* | grep -v "$Obj")
	Temp=$(make clean -C libft -f Makefile > /dev/null && ls -l libft/* | grep -v "$Obj")
	if [ "$Temp" != "$All" ]
	then
		printf "${RED}[clean doesn't work] ${NORMAL}"
	else
		printf "${GREEN}[OK]${NORMAL} "
	fi
	#fclean
	Temp=$(make fclean -C libft -f Makefile > /dev/null && ls -l libft/ | grep "libft.a")
	if [ "$Temp" != "" ]
	then
		printf "${RED}[fclean doesn't work] ${NORMAL}"
	else
		printf "${GREEN}[OK]${NORMAL} "
	fi
else
	echo "${RED}[No file!]${NORMAL}"
fi
#Norm!
printf "\nNorm:\t\t"
Temp=$(norminette libft/*.c libft/*.h | grep -B1 "Error\|Warning")
if [ "$Temp" = "" ]
then
	echo "${GREEN}[OK]${NORMAL}"
else
	echo "${RED}[Norm error!]${NORMAL}"
	echo "$Temp"
fi
