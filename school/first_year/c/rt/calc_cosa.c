/*
** calc_cosa.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:31:46 2008 emilien ampe
** Last update Thu May 22 18:31:57 2008 emilien ampe
*/

#include "raytracer.h"

double		calcul_cosa(t_coord *c)
{
  double	cosa;

  c->Norme_N = sqrt(SQ(c->Nx) + SQ(c->Ny) + SQ(c->Nz));
  c->Norme_P = sqrt(SQ(c->Lx) + SQ(c->Ly) + SQ(c->Lz));
  c->scal_NP = (c->Lx * c->Nx) + (c->Ly * c->Ny) + (c->Lz * c->Nz);
  cosa = (c->scal_NP / (c->Norme_N * c->Norme_P));
  return (cosa);
}
