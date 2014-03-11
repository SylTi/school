/*
** delete_to_list.c for push_swap in /u/epitech_2012/bizet_v/cu/rendu/c/push_swap
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Fri Jan 11 15:03:46 2008 virgile bizet
** Last update Mon Jun 22 15:59:37 2009 nikola cebovic
*/

#include <stdlib.h>
#include "push.h"

void		pop_front(t_list *l)
{
  t_elem	*tmp;

  tmp = l->first;
  if (!tmp)
    return ;
  l->first = tmp->next;
  if (l->first)
    l->first->prev = NULL;
  else
    l->last = NULL;
  free(tmp);
}

void		unaction(t_list *l, int fd)
{
  t_elem	*tmp;

  tmp = l->first;
  if (!tmp)
    return ;
  while (tmp)
    {
      if (tmp->fd == fd)
	{
	  free(tmp->cmd);
	  if (tmp == l->first && tmp == l->last)
	    unaction_1(l, tmp);
	  else if (tmp == l->first)
	    unaction_2(l, tmp);
	  else if (tmp == l->last)
	    unaction_3(l, tmp);
	  else
	    unaction_4(tmp);
	}
      tmp = tmp->next;
    }
}
