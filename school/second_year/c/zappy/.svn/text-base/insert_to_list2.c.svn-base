/*
** insert_to_list2.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 17:50:51 2009 yoann jaspar
** Last update Mon Jun 22 14:54:43 2009 nikola cebovic
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "serveur.h"
#include "push.h"
#include "serveur.h"

typedef struct  s_opers
{
  char          *opers;
  int           time;
}               t_opers;

t_opers gl_tab[] = {
  {"avance", 7},
  {"droite", 7},
  {"gauche", 7},
  {"voir", 7},
  {"inventaire", 1},
  {"prend", 7},
  {"pose", 7},
  {"expulse", 7},
  {"broadcast ", 7},
  {"incantation", 0},
  {"my_incantation", 300},
  {"fork", 42},
  {"my_fork", 600},
  {"mort", 1260},
  {"connect_nbr", 0},
  {0, 0}
};

void		init_list(t_list *s)
{
  s->first = NULL;
  s->last = NULL;
}

int		check_list(int fd, t_list *s)
{
  t_elem	*new;
  int		cnt;

  cnt = 0;
  new = s->first;
  while (new != NULL)
    {
      if (new->fd == fd)
	cnt++;
      if (cnt >= 10)
	return (0);
      new = new->next;
    }
  return (1);
}

int	check_time(t_list *s, char *cmd)
{
  int   i;

  s = s;
  i = 0;
  while (gl_tab[i].opers != 0)
    {
      if (strncmp(gl_tab[i].opers, cmd, strlen(gl_tab[i]. opers)) == 0)
	return (gl_tab[i].time);
      i++;
    }
  return (-1);
}

void		*insert_by_order(t_list *s, struct timeval time)
{
  t_elem	*new;

  new = s->first;
  if (timercmp(&(s->first->time),  &time, >))
    {
      return (s->first);
    }
  while (new != NULL)
    {
      if (timercmp(&new->time, &time, >))
	{
	  return (new);
	}
      new = new->next;
    }
  return (s->last);
}
