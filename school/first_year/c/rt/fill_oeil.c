/*
** fill_oeil.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:06:42 2008 emilien ampe
** Last update Fri May 23 13:46:18 2008 emilien ampe
*/

#include "raytracer.h"

void		fill_oeil(t_coord *t_x)
{
  fill_3_space(get_next_line(t_x->fd), t_x);
  t_x->o_x = (double)t_x->t[0];
  t_x->o_y = (double)t_x->t[1];
  t_x->o_z = (double)t_x->t[2];
  fill_3_space(get_next_line(t_x->fd), t_x);
  t_x->o_rx = ((double)t_x->t[0] * M_PI) / 180;
  t_x->o_ry = ((double)t_x->t[1] * M_PI) / 180;
  t_x->o_rz = ((double)t_x->t[2] * M_PI) / 180;
}
