/*
** ray1.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:01:12 2008 emilien ampe
** Last update Thu May 22 19:39:23 2008 emilien ampe
*/

#include "raytracer.h"

unsigned long	ray1(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x);
  c->z1 = (c->winy / 2.0) - ((double)y);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray2(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x + 0.25);
  c->z1 = (c->winy / 2.0) - ((double)y);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray3(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x - 0.25);
  c->z1 = (c->winy / 2.0) - ((double)y);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray4(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x);
  c->z1 = (c->winy / 2.0) - ((double)y + 0.25);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray5(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x);
  c->z1 = (c->winy / 2.0) - ((double)y - 0.25);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}
