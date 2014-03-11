/*
** my_put_in_list.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Wed Oct 19 15:36:01 2008 emilien ampe
** Last update Fri May 23 13:25:06 2008 emilien ampe
*/

#include "raytracer.h"

void		my_put_in_list(t_list **l, void *d)
{
  t_list	*new_elem;
  t_list	*cur_list;

  cur_list = *l;
  new_elem = xmalloc(1 * sizeof(*new_elem));
  new_elem->data = d;
  new_elem->next = cur_list;
  *l = new_elem;
}
