
##
## Makefile for snake in /u/epitech_2012/bizet_v/public/colle1
## 
## Made by virgile bizet
## Login   <bizet_v@epitech.net>
## 
## Started on  Wed Apr 30 19:41:07 2008 virgile bizet

##

CC_FreeBSD	=	gcc

CC_sun4		=	/usr/sfw/bin/gcc

CC_ia64-linux	=	gcc

CC		=	$(CC_$(HOSTTYPE))

DIR_IA          =       client_ia/

NAME		=	serveur

NAME_IA		=	zappy_ia

SRC_SRC		=	test.c			\
			insert_to_list.c	\
			insert_to_list2.c	\
			delete_to_list.c	\
			unaction.c		\
			random.c		\
			init.c			\
			init2.c			\
			init3.c			\
			inventaire.c		\
			serveur_init.c		\
			serveur_init2.c		\
			xfunctions1.c		\
			usual.c			\
			serveur.c		\
			serveur2.c		\
			serveur_add.c		\
			builtins.c		\
			builtins_gr.c		\
			builtins_gr2.c		\
			builtins_gr3.c		\
			avance.c		\
			prend.c			\
			prend_ressource.c	\
			pose.c			\
			pose_ressource.c	\
			expulse.c		\
			expulse_direc.c		\
			broadcast.c		\
			incantation.c		\
			incantation2.c		\
			incantation3.c		\
			gauche_droite.c		\
			parsinator.c		\
			parsinator_plus.c	\
			parsinator_display.c	\
			builtin_voir.c		\
			voir_norme.c		\
			my_broadcast.c		\
			my_broadcast2.c		\
			voir_direct.c		\
			winner.c		\
			update_time_death_pos.c	\

SRC_IA		=	zappy_ia.php

OBJS		=	$(SRC_SRC:.c=.o) $(SRC_ERROR:.c=.o)

INCLUDE		=	-I ./include 

LDFLAGS		=	

CFLAGS		+=	-W -Wall   -ansi -pedantic

COLOR_YELL	=	\33[32m
COLOR_RESET	=	\33[m

all		:	$(NAME)
			@make $(NAME_IA)
			@printf "$(COLOR_YELL)[8===D]\nFin de compilation.\n$(COLOR_RESET)"

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
			@printf "\n$(COLOR_YELL)$(NAME) compile !\n$(COLOR_RESET)"
$(NAME_IA)	:
			ln -s $(DIR_IA)$(SRC_IA) $(NAME_IA)

clean		:
			rm -rf $(OBJ)
			rm -f *~
			rm -f *#
			rm -f */*~
			rm -f *.o
			rm -f $(LINKNAME)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
.c.o		:
			$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDE)
