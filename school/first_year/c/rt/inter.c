/*
** inter.c for intersection  in /u/epitech_2012/ampe_e/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 19:53:54 2008 emilien ampe
** Last update Fri May 23 13:57:30 2008 emilien ampe
*/

#include "raytracer.h"

int	inter_cone(t_coord *c, t_obj *b)
{
  calc_delta_cone(c, b);
  if (c->delta >= 0.00001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int	inter_cyl(t_coord *c, t_obj *b)
{
  calc_delta_cyl(c, b);
  if (c->delta >= 0.00001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int	inter_sph(t_coord *c, t_obj *b)
{
  calc_delta_sph(c, b);
  if (c->delta >= 0.000001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int	inter_para(t_coord *c, t_obj *b)
{
  calc_delta_para(c, b);
  if (c->delta >= 0.00001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int             inter_plan(t_coord *c, t_obj *b)
{
  c->lambda = -((c->o_z) / c->Vz);
  if (c->lambda > (double)0)
    {
      if (b->pl_type > 0)
        {
          c->Px = c->o_x + (c->lambda * c->Vx);
          c->Py = c->o_y + (c->lambda * c->Vy);
        }
      if (if_plan_limite(c, b) == 1)
	return (1);
      return (0);
    }
  return (0);
}
