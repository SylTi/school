/*
** ombres2.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:47:28 2008 emilien ampe
** Last update Fri May 23 14:42:29 2008 paul bourjac
*/

#include "raytracer.h"

int		sh_inter_plan(t_coord *c, t_obj *b)
{
  b = b;
  c->lambda = -((c->Nz) / c->Lsh_z);
  c->lambda_2 = -((c->o_z) / c->Vz);
  if (c->lambda > 0.00001 && c->lambda < 1.0000)
    return (1);
  return (0);
}

void		sh_calc_delta_cone(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) - (b->var * SQ(c->Vz));
  c->bx = 2 * ((c->Nx * c->Vx) + (c->Ny * c->Vy) - (b->var * c->Nz * c->Vz));
  c->cx = SQ(c->Nx) + SQ(c->Ny) - (b->var * SQ(c->Nz));
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void		sh_calc_delta_cyl(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy);
  c->bx = 2 * ((c->Nx * c->Vx) + (c->Ny * c->Vy));
  c->cx = SQ(c->Nx) + SQ(c->Ny) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void		sh_calc_delta_sph(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) + SQ(c->Vz);
  c->bx = 2 * ((c->Nx * c->Vx) + (c->Ny * c->Vy) + (c->Nz * c->Vz));
  c->cx = SQ(c->Nx) + SQ(c->Ny) + SQ(c->Nz) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}
