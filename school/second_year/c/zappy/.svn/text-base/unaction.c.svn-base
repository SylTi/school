/*
** unaction.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Fri Jun 19 15:08:41 2009 emilien ampe
** Last update Fri Jun 19 15:09:05 2009 emilien ampe
*/

#include "serveur.h"

void	unaction_1(t_list *l, t_elem *tmp)
{
  l->first = NULL;
  l->last = NULL;
  free(tmp);
}

void	unaction_2(t_list *l, t_elem *tmp)
{
  l->first = tmp->next;
  l->first->prev = NULL;
  free(tmp);
}

void	unaction_3(t_list *l, t_elem *tmp)
{
  l->last = l->last->prev;
  l->last->next = NULL;
  free(tmp);
}

void	unaction_4(t_elem *tmp)
{
  if (tmp->prev)
    if (tmp->prev->next)
      tmp->prev->next = tmp->next;
  if (tmp->next)
    if (tmp->next->prev)
      tmp->next->prev = tmp->prev;
  free(tmp);
}
