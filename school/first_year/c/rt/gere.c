/*
** gere.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:41:26 2008 emilien ampe
** Last update Fri May 23 02:24:40 2008 emilien ampe
*/

#include "raytracer.h"

int		gere_expose(void *param)
{
  t_mlx		*p;

  p = param;
  mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
  return (1);
}

int		gere_key(int keycode, void *param)
{
  t_mlx		*p;

  p = param;
  if (keycode == ESC)
    {
      mlx_destroy_image(p->mlx, p->img);
      mlx_destroy_window(p->mlx, p->win);
      exit (0);
    }
  return (1);
}

void		put_pixel_to_image(t_mlx *s, int x, int y, void *color)
{
  int		i;
  t_color_x	*col;

  i = 0;
  col = color;
  if (x >= 0 && x <= s->win_x && y > 0 && y <= s->win_y)
    {
      while (i < (s->bpp) / 8)
	{
	  (s->data)[((x * ((s->bpp) / 8)) + (y * (s->sizeline))) + i] = col->c_color[i];
	  i++;
	}
    }
}
