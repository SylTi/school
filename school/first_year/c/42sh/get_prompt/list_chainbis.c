/*
** list_chainbis.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:26:33 2008 jean-philippe rey
** Last update Fri May 16 21:38:41 2008 jean-philippe rey
*/

#include <stdlib.h>
#include "colle.h"

void	my_add_in_list(t_list *list, char c)
{
  t_elm	*tmp;
  t_elm	*new;

  if ((list->list) && (!list->list->prev))
    my_put_in_list_f(list, c);
  else if ((list->list) && (!list->list->next))
    my_put_in_list(list, c);
  else if (list->list)
    {
      tmp = list->list->prev;
      new = xmalloc(sizeof(*new));
      new->c = c;
      tmp->next = new;
      list->list->prev = new;
      new->next = list->list;
      new->prev = tmp;
    }
  else
    my_put_in_list(list, c);
}

void	free_list(t_list *list)
{
  t_elm	*tmp;

  list->list = list->first;
  while (list->list)
    {
      tmp = list->list;
      list->list = list->list->next;
      free(tmp);
    }
  free(list);
}
