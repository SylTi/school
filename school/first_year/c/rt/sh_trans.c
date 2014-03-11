/*
** sh_trans.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:11:53 2008 emilien ampe
** Last update Thu May 22 22:12:46 2008 emilien ampe
*/

#include "raytracer.h"

void		sh_trans(t_coord *c, t_obj *b)
{
  c->Vx = c->Lsh_x;
  c->Vy = c->Lsh_y;
  c->Vz = c->Lsh_z;
  c->Nx -= b->xt;
  c->Ny -= b->yt;
  c->Nz -= b->zt;
  if (b->ax != (double)0 || b->ay != (double)0 || b->az != (double)0)
    calc_sh_rotation(c, b);
}

void		sh_de_trans(t_coord *c, t_obj *b)
{
  if (b->ax != (double)0 || b->ay != (double)0 || b->az != (double)0)
    calc_sh_rotation_inv(c, b);
  c->Nx += b->xt;
  c->Ny += b->yt;
  c->Nz += b->zt;
}
