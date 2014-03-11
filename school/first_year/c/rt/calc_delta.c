/*
** calc_delta.c for calc delta in /u/epitech_2012/ampe_e/public/raytracer/lolo/test/FAIT
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 22 17:38:34 2008 sylvain tissier
** Last update Thu May 22 17:46:42 2008 sylvain tissier
*/

#include "raytracer.h"

void	calc_delta_cone(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) - (b->var * SQ(c->Vz));
  c->bx = 2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy) - (b->var * c->o_z * c->Vz));
  c->cx = SQ(c->o_x) + SQ(c->o_y) - (b->var * SQ(c->o_z));
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void	calc_delta_cyl(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy);
  c->bx = 2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy));
  c->cx = SQ(c->o_x) + SQ(c->o_y) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void	calc_delta_sph(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) + SQ(c->Vz);
  c->bx = 2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy) + (c->o_z * c->Vz));
  c->cx = SQ(c->o_x) + SQ(c->o_y) + SQ(c->o_z) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void	calc_delta_para(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy);
  c->bx = (2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy))) - (b->var * c->Vz);
  c->cx = SQ(c->o_x) + SQ(c->o_y) - (b->var * c->o_z);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}
