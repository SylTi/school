/*
** push.h for push in /u/all/bizet_v/cu/rendu/c/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Sun Jun 21 16:42:27 2009 virgile bizet
** Last update Mon Jun 22 14:56:33 2009 nikola cebovic
*/

#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__
#include <sys/time.h>
/*
** STRUCT
*/

typedef struct		s_elem
{
  int			fd;
  char			*cmd;
  struct timeval	time;
  struct s_elem		*prev;
  struct s_elem		*next;
}			t_elem;

typedef struct	s_list
{
  t_elem	*first;
  t_elem	*last;
}		t_list;

/*
** FUNCTIONS
*/

void		init_list(t_list *s);
void            clear_list(t_list *l);
int		check_list(int fd, t_list *s);
void		unaction_1(t_list *l, t_elem *tmp);
void		unaction_2(t_list *l, t_elem *tmp);
void		unaction_3(t_list *l, t_elem *tmp);
void		unaction_4(t_elem *tmp);

#endif
