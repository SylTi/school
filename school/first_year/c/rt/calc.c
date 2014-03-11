/*
** calc.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:23:45 2008 emilien ampe
** Last update Fri May 23 11:42:21 2008 emilien ampe
*/

#include "raytracer.h"

extern int	(*tab[])();

unsigned long	calc(t_coord *c, t_list *b, t_list *spot)
{
  double	k;
  t_list	*one;
  t_obj		*obj;
  t_obj		*tmp;

  one = b;
  c->shadow = 0;
  tmp = 0;
  k = 100000;
  c->shadow++;
  while (b)
    {
      obj = b->data;
      obj->pcs_shadow = c->shadow;
      trans(c, obj);
      (c->k_k) = tab[obj->type - 1](c, obj);
      de_trans(c, obj);
      if ((c->k_k) == 1 && c->lambda < k && c->lambda > 0.000001)
	{
	  c->max_shadow = c->shadow;
	  k = c->lambda;
	  tmp = obj;
	}
      c->shadow++;
      b = b->next;
    }
  if (k > 99999.0)
    return ((unsigned long)NULL);
  c->lambda = k;
  return (light(c, one, spot, tmp));
}
