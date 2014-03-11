/*
** sh_calc.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:09:00 2008 emilien ampe
** Last update Thu May 22 22:09:46 2008 emilien ampe
*/

#include "raytracer.h"

void		sh_calc_n(t_coord *c)
{
  c->Nx = c->o_x + (c->lambda * c->x1);
  c->Ny = c->o_y + (c->lambda * c->y1);
  c->Nz = c->o_z + (c->lambda * c->z1);
}

void		sh_calc_lsh(t_coord *c, t_spot *tmp)
{
  c->Lsh_x = tmp->x_spot - c->Nx;
  c->Lsh_y = tmp->y_spot - c->Ny;
  c->Lsh_z = tmp->z_spot - c->Nz;
}
