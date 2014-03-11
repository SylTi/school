/*
** ombres1.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:46:34 2008 emilien ampe
** Last update Fri May 23 14:44:33 2008 paul bourjac
*/

#include "raytracer.h"

extern int	(*tab1[])();

double		shadow(t_coord *c, t_list *b, t_list *sp)
{
  double	flag;
  t_list	*one;
  t_obj		*obj;
  t_spot	*tmp;

  sh_calc_n(c);
  flag = (double)1;
  while (sp)
    {
      tmp = sp->data;
      sh_calc_lsh(c, tmp);
      one = b;
      while (one)
	{
	  obj = one->data;
	  sh_trans(c, obj);
	  if (obj->type != PLAN)
	    if (((tab1[obj->type - 1](c, obj)) == 1)
		&& (obj->pcs_shadow != c->max_shadow))
	      flag -= c->coef_spot;
	  sh_de_trans(c, obj);
	  one = one->next;
	}
      sp = sp->next;
    }
  if (flag < (double)0)
    return ((double)0);
  return (flag);
}

int		sh_inter_cone(t_coord *c, t_obj *b)
{
  sh_calc_delta_cone(c, b);
  if (c->delta >= 0.0001)
    {
      c->lambda = (double)(-1);
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / ((double)2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / ((double)2 * c->ax);
      if ((MAX_LAMBDA(c->lambda_1, c->lambda_2)) ||
	  (NEG(c->lambda_2) && NO_NEG(c->lambda_1)))
	c->lambda = c->lambda_1;
      else if (MAX_LAMBDA(c->lambda_2, c->lambda_1) ||
	       (NEG(c->lambda_1) && NO_NEG(c->lambda_2)))
	c->lambda = c->lambda_2;
      else
	c->lambda = (double)0;
      if (NO_NEG(c->lambda) && c->lambda < (double)1)
	return (1);
    }
  return (0);
}

int		sh_inter_cyl(t_coord *c, t_obj *b)
{
  sh_calc_delta_cyl(c, b);
  if (c->delta >= 0.0001)
    {
      c->lambda = (double)(-1);
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / ((double)2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / ((double)2 * c->ax);
      if ((MAX_LAMBDA(c->lambda_1, c->lambda_2)) ||
	  (NEG(c->lambda_2) && NO_NEG(c->lambda_1)))
	c->lambda = c->lambda_1;
      else if (MAX_LAMBDA(c->lambda_2, c->lambda_1) ||
	       (NEG(c->lambda_1) && NO_NEG(c->lambda_2)))
	c->lambda = c->lambda_2;
      else
	c->lambda = (double)0;
      if (NO_NEG(c->lambda) && c->lambda < (double)1)
	return (1);
    }
  return (0);
}

int		sh_inter_sph(t_coord *c, t_obj *b)
{
  sh_calc_delta_sph(c, b);
  if (c->delta >= (double)(0))
    {
      c->lambda = (double)(-1);
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((MAX_LAMBDA(c->lambda_1, c->lambda_2)) ||
	  (NEG(c->lambda_2) && NO_NEG(c->lambda_1)))
	c->lambda = c->lambda_1;
      else if (MAX_LAMBDA(c->lambda_2, c->lambda_1) ||
	       (NEG(c->lambda_1) && NO_NEG(c->lambda_2)))
	c->lambda = c->lambda_2;
      else
	c->lambda = (double)0;
      if (NO_NEG(c->lambda) && c->lambda < (double)1)
	return (1);
    }
  return (0);
}
