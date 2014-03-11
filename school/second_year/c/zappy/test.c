/*
** test.c for parseur_zappy in /u/all/bizet_v/cu/rendu/c/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Mon Apr 27 16:07:26 2009 virgile bizet
** Last update Mon Jun 22 16:10:27 2009 nikola cebovic
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"
#include "push.h"

void	view(t_list *s)
{
  t_elem	*new;

  new = s->first;
  while (new != NULL)
    {
      printf("JOUEUR  %d fait %s a %ld s %ld ms\n",
	     new->fd,
	     new->cmd,
	     new->time.tv_sec,
	     new->time.tv_usec);
      new = new->next;
    }
}

void	put_in_list(int fd, char *cmd, t_list *s, t_env *env)
{
  char  *pointeur1 = NULL;
  char  *pointeur2 = NULL;
  char  *pointeurtmp;
  char	*buffer;

  buffer = strdup(cmd);
  pointeur1 = strtok(buffer, "\n");
  pointeurtmp = xmalloc(1);
  if (check_list(fd, s) && pointeur1)
    insert_in_list(s, fd, pointeur1, env);
  while (pointeurtmp != NULL)
    {
      pointeurtmp = strtok( NULL, "\n");
      if (pointeurtmp != NULL)
        pointeur2 = pointeurtmp;
      if (check_list(fd, s) && pointeur2)
	insert_in_list(s, fd, pointeur2, env);
      pointeur2 = NULL;
      pointeur2 = NULL;
    }
  view(s);
  free(buffer);
}
