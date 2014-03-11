/*
** list_chain.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:26:22 2008 jean-philippe rey
** Last update Fri May 16 21:26:23 2008 jean-philippe rey
*/

#include <string.h>
#include <stdio.h>

#include "colle.h"

t_list	*init_list(t_list *list, int fd, int t)
{
  list = xmalloc(sizeof(*list));
  list->first = 0;
  list->list = 0;
  list->last = 0;
  list->fd = fd;
  list->x = 0;
  list->type = t;
  return (list);
}

void	my_put_in_list(t_list *list, char c)
{
  t_elm	*new;

  new = xmalloc(sizeof(*new));
  new->next = 0;
  new->c = c;
  new->prev = list->last;
  if (list->last)
    list->last->next = new;
  else
    {
      list->first = new;
      list->list = new;
    }
  list->last = new;
}

void	my_put_in_list_f(t_list *list, char c)
{
  t_elm	*new;

  new = xmalloc(sizeof(*new));
  new->next = list->first;
  new->c = c;
  new->prev = 0;
  if (list->first)
    list->first->prev = new;
  else
    {
      list->last = new;
      list->list = new;
    }
  list->first = new;
}

void	put_prompt_to_list(t_list *list, char *str)
{
  int	i;

  i = 0;
  list->x = strlen(str);
  list->lim_x = strlen(str);
  while (str[i])
    {
      if (str[i] != '"')
	my_put_in_list(list, str[i]);
      else if (str[i] == '"')
	{
	  list->x--;
	  list->lim_x--;
	}
      i++;
    }
}

void	view_list(t_list *list)
{
  list->list = list->first;
  while (list->list)
    {
      printf("%c", list->list->c);
      list->list = list->list->next;
    }
  printf("\n");
}
