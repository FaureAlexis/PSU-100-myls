##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for my_ls
##

SRC	    =	src/*.c

S_LIB   =   lib/*.c

NAME	=	my_ls

all:	$(NAME)

$(NAME):
	make m_lib
	gcc -o $(NAME) main.c $(SRC) -Llib -lls -g

clean:
	-rm -f *.o

fclean:	clean
	-rm -rf $(NAME)
	-rm -rf lib/libls.a
	-rm unit*
	-rm *gcno
	-rm *gcda

re:
	make fclean
	make

tests_run:	re
	gcc -o unit_tests $(SRC) tests/*.c -I include -Llib -lls -lcriterion --coverage

m_lib:
	gcc -c $(S_LIB)
	@ar rc libls.a *.o
	make clean
	mv libls.a lib/

.PHONY:
	all clean fclean m_lib re tests_run
