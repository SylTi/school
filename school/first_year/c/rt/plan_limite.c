/*
** plan_limite.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:23:10 2008 emilien ampe
** Last update Fri May 23 14:45:58 2008 emilien ampe
*/

#include "raytracer.h"

int	if_plan_limite(t_coord *c, t_obj *b)
{
  if (b->pl_type == 2)
    {
      if (((SQ(c->Px) + SQ(c->Py)) < SQ(b->pl_vax))
	  && ((SQ(c->Px) + SQ(c->Py)) > SQ(b->pl_vay)))
	return (1);
      return (0);
    }
  return (1);
}
