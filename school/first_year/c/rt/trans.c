/*
** trans.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:13:46 2008 emilien ampe
** Last update Thu May 22 19:40:51 2008 emilien ampe
*/

#include "raytracer.h"

void		trans(t_coord *c, t_obj *b)
{
  c->Vx = c->x1;
  c->Vy = c->y1;
  c->Vz = c->z1;
  c->o_x -= b->xt;
  c->o_y -= b->yt;
  c->o_z -= b->zt;
  calc_rotation(c, b);
}

void		de_trans(t_coord *c, t_obj *b)
{
  calc_rotation_inv(c, b);
  c->o_x += b->xt;
  c->o_y += b->yt;
  c->o_z += b->zt;
}
