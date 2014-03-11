/*
** remplis_image.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 17:49:02 2008 emilien ampe
** Last update Fri May 23 13:24:56 2008 yoann jaspar
*/

#include "raytracer.h"

extern t_ray	gl_ray[];

void		remplis_image(t_mlx *s, t_coord *c, t_list *b, t_list *spot)
{
  int		x;
  int		y;
  t_color_x	couleur;
  t_color_x	tmpcol;
  
  x = 0;
  c->coef_spot = (double)1 / ((double)check_list_size(spot) + (double)1);
  while (x <= c->winx)
    {
      loading(s, c, x);
      y = 0;
      while (y <= c->winy)
	{
	  if ((c->aa == 4 || c->aa == 8))
	    tmpcol.color = anti_aa(x, y, c, b, spot);
	  else
	    tmpcol.color = ray1(x, y, c, b, spot);
	  couleur.color = mlx_get_color_value(s->mlx, tmpcol.color);
	  put_pixel_to_image(s, x, y, &couleur);
	  y++;
	}
      x++;
    }
}
