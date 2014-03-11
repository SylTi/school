##
## Makefile for colle2 in /u/all/jaspar_y/public/collissimo
## 
## Made by jean-philippe rey
## Login   <rey_e@epitech.net>
## 
## Started on  Fri May 16 21:24:15 2008 jean-philippe rey
## Last update Wed May 21 15:17:42 2008 yoann jaspar
##

NAME		=	colle2-2

SRC		= 	edit_prompt.c\
			gere_char.c\
			list_chainbis.c\
			end.c\
			delete_list.c\
			show_menu.c\
			cpy_to_tcsh.c\
			test_key.c\
			move.c\
			list_chain.c\
			smenu.c\
			empty_buf.c\
			my_putstr.c\
			xverifs.c\
			menu.c\
			match.c\
			get_prompt.c\
			get_next_line.c\
			xterm.c\
			init_menu2.c\
			mais_lol.c\

OBJ		=	$(SRC:.c=.o)

CC_FreeBSD	=	gcc
CC_solaris	=	/usr/sfw/bin/gcc
CC_linux	=	gcc
CC		=	$(CC_${OSTYPE})

INCLUDES	=	-I.
CFLAGS		+=	-W -Wall -pedantic -ansi -Werror -Wstrict-prototypes $(INCLUDES)

RM		=	rm -rf

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -ltermcap

all		:	$(NAME)

clean		:
			$(RM) *~ */*~
			$(RM) *\# */*\#
			$(RM) $(OBJ)

fclean		: clean
			$(RM) $(NAME)

re		: fclean all
