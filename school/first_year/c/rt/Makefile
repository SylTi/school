##
## Makefile for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
## 
## Made by emilien ampe
## Login   <ampe_e@epitech.net>
## 
## Started on  Thu May 22 15:03:13 2008 emilien ampe
## Last update Fri May 23 14:05:43 2008 emilien ampe
##

CC		=		gcc
SRC		=		main.c \
				init_sX.c \
				init.c \
				init_n.c \
				get_next_line.c \
				get_col.c \
				calc_rot.c \
				calc_rot2.c \
				calc.c \
				calc_cosa.c \
				fill_win_size.c \
				calc_delta.c \
				calc_roeil.c \
				check_liste_size.c \
				gere.c \
				inter.c \
				light.c \
				load.c \
				li_trans.c \
				my_put_in_list.c \
				rotation.c \
				parse_conf.c \
				prepare.c \
				ray1.c \
				ray2.c \
				ombres1.c \
				ombres2.c \
				sh_calc.c \
				sh_trans.c \
				reflection.c \
				remplis_image.c \
				save_coord_ref_trans.c \
				trans.c \
				transparence.c \
				gl_parse1.c \
				gl_parse2.c \
				gl_parse3.c \
				plan_limite.c \
				fill.c \
				fill_space.c \
				fill_3_space.c \
				fill_oeil.c \
				fill_spot.c \
				anti_aa.c \
				xerror.c

NAME		=		rt
OBJS		=		$(SRC:.c=.o)
RM		=		rm -f
CFLAGS		=		-g3 -pedantic -Wall -O3 -W -ansi \
				-I/usr/X11/include
LDFLAGS		=		-L/usr/X11/lib/ \
				-lmlx_`uname` \
				-L/usr/X11/lib \
				-lXext \
				-lX11 \
				-lm \
				-L. -lmy
$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all	:	$(NAME)

clean	:
		$(RM) *~
		$(RM) *#
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	: clean all