/*
** fill_spot.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 20 22:04:49 2008 emilien ampe
** Last update Fri May 23 13:15:36 2008 emilien ampe
*/

#include "raytracer.h"

void		fill_spot(t_list **sp, t_coord *t_x)
{
  t_spot	*spot;

  spot = xmalloc(sizeof(*spot) * 1);
  fill_3_space(get_next_line(t_x->fd), t_x);
  spot->x_spot = t_x->t[0];
  spot->y_spot = t_x->t[1];
  spot->z_spot = t_x->t[2];
  spot->var = atof(fill_space(get_next_line(t_x->fd)));
  fill_3_space(get_next_line(t_x->fd), t_x);
  spot->col = get_col(t_x->t);
  my_put_in_list(sp, spot);
}
