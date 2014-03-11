/*
** ray2.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:06:36 2008 emilien ampe
** Last update Thu May 22 19:40:22 2008 emilien ampe
*/

#include "raytracer.h"

unsigned long	ray6(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x - 0.25);
  c->z1 = (c->winy / 2.0) - ((double)y - 0.25);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray7(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x + 0.25);
  c->z1 = (c->winy / 2.0) - ((double)y - 0.25);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray8(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x + 0.25);
  c->z1 = (c->winy / 2.0) - ((double)y + 0.25);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}

unsigned long	ray9(int x, int y, t_coord *c, t_list *b, t_list *spot)
{
  c->x1 = c->winx;
  c->y1 = (c->winx / 2.0) - ((double)x - 0.25);
  c->z1 = (c->winy / 2.0) - ((double)y + 0.25);
  calc_rotation_oeil(c);
  return (calc(c, b, spot));
}
