/*
** colle.h for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:24:06 2008 jean-philippe rey
** Last update Mon May 26 10:54:45 2008 yoann jaspar
*/

#ifndef __COLLE_H__
# define __COLLE_H__

#include "ansicolours.h"

#define INSERT(a) ((a) > (0) ? (0) : (1))
#define HOME 72
#define END 70
#define PR 1
#define RPR 2
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define DEL 5

typedef struct		s_elm
{
  char			c;
  struct s_elm		*next;
  struct s_elm		*prev;
}			t_elm;

typedef struct		s_list
{
  t_elm			*first;
  t_elm			*list;
  t_elm			*last;
  int			fd;
  int			x;
  int			lim_x;
  int			type;
}			t_list;

typedef struct		s_allpr
{
  t_list		*pr;
  t_list		*rpr;
  t_list		*cur;
}			t_allpr;

typedef	struct		s_term
{
  char			*area;
  char			*clstr;
  char			*kustr;
  char			*kdstr;
  char			*klstr;
  char			*krstr;
  char			*ndstr;
  char			*lestr;
  char			*dcstr;
  char			*cmstr;
  char			*sostr;
  char			*sestr;
  char			*term;
  char			t[4096];
  char			bp[1024];
}			t_term;

typedef	struct		s_prompt
{
  int			fd;
  char			*prompt;
  char			*rprompt;
}			t_prompt;

typedef	struct		s_smenu
{
  char			*var;
  char			*opt;
}			t_smenu;

typedef	struct		s_menu
{
  char			*var;
  t_smenu		*smenu;
}			t_menu;

void	insert_char(t_allpr *lpr, char c, t_term *term, int flag);
void	del_char(t_allpr *lpr, t_term *term);
void	del_elm(t_list *list);
void	ins_elm(t_list *list, char c);
void	aff_prompt(t_list *pr, t_list *rpr);
void	add_str_to_list(char *str, t_allpr *lpr, t_term *term, int flag);
void	cpy_to_tcsh(t_allpr *lpr);
int	main_move(t_allpr *lpr, t_term *term);
t_list	*init_list(t_list *list, int fd, int t);
void	my_put_in_list(t_list *list, char c);
void	put_prompt_to_list(t_list *list, char *str);
void	view_list(t_list *list);
void	delete_all(t_list *list);
void	my_put_in_list_f(t_list *list, char c);
void	free_list(t_list *list);
void	my_add_in_list(t_list *list, char c);
void	*xmalloc(int size);
int	xwrite(int output, void *buffer, int to_write);
char	*xgetenv(char *str);
int	xtgetent(char *bp, char *term);
char	*xtgetstr(char *cap, char **area);
void	xtputs(char *str, int affcnt, int (*putc)(int));
int	my_outc(int c);
int	xread(int d, void *buf, int nbyte);
int	xopen(char *path, int more);
int	xlseek(int fd, int pos, int next);
char	*main_smenu(t_term *term, int xmenu, t_menu *menu);
char	*main_menu(t_term *term);
int	main_xmenu(void);
void	show_menu(t_menu *menu, int xmenu, int xsmenu, t_term *term);
int	accept(t_term *term);
void	empty_buf(char *buf, int size);
void	my_putstr(char *str);
void	my_putchar(char c);
char	*get_next_line(int fd);
int	matchn(char *to_find, char *here);
int	test_key(t_term *term, char c);
void	get_prompt(t_prompt *prompt);
void	init_menu2(t_menu *menu);
int	mais_lol(int flag, t_term *term, t_allpr *lpr);
void	move_curs(int x, t_allpr *lpr, t_term *term);
void	move_key(t_term *term, int nb_key, t_allpr *lpr);
void	init_cano(struct termios *conf);

#endif
