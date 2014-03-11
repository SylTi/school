/*
** delete_list.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:25:01 2008 jean-philippe rey
** Last update Fri May 16 21:25:02 2008 jean-philippe rey
*/

#include <stdlib.h>

#include "colle.h"

void		delete_b(t_list *list)
{
  t_elm	*tmp;

  tmp = list->last;
  list->last = tmp->prev;
  if (list->last)
    list->last->next = NULL;
  else
    {
      list->list = NULL;
      list->first = NULL;
    }
  free(tmp);
}

void		delete_f(t_list *list)
{
  t_elm	*tmp;

  tmp = list->first;
  list->list = tmp->next;
  list->first = tmp->next;
  if (list->list)
    list->list->prev = NULL;
  else
    list->last = NULL;
  free(tmp);
}

void		delete_all(t_list *list)
{
  t_elm	*save;
  t_elm	*tmp;
  t_elm	*tmp2;

  if (!list->list->prev)
    delete_f(list);
  else if (!list->list->next)
    delete_b(list);
  else
    {
      save = list->list;
      tmp = save->next;
      tmp2 = save->prev;
      free(save);
      tmp2->next = tmp;
      tmp->prev = tmp2;
    }
}
