/*
** li_trans.c<2> for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:29:06 2008 emilien ampe
** Last update Fri May 23 13:22:24 2008 emilien ampe
*/

#include "raytracer.h"

void		li_trans(t_coord *c, t_obj *b)
{
  c->Px -= b->xt;
  c->Py -= b->yt;
  c->Pz -= b->zt;

  if (b->ax != 0 || b->ay != 0 || b->az != 0)
    calc_li_rotation(c, b);
}

void		de_li_trans(t_coord *c, t_obj *b)
{
  if (b->ax != 0 || b->ay != 0 || b->az != 0)
    calc_li_rotation_inv(c, b);

  c->Px += b->xt;
  c->Py += b->yt;
  c->Pz += b->zt;
}
