/*
** init_sX.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue May  9 17:43:25 2008 emilien ampe
** Last update Fri May 23 13:24:58 2008 yoann jaspar
*/

#include "raytracer.h"

void	init_sX(char **av)
{
  t_mlx		s;
  t_coord	c;
  t_list	*b;
  t_list	*spot;
  
  b = xmalloc(1 * sizeof(*b));
  spot = xmalloc(1 * sizeof(*spot));
  b = NULL;
  spot = NULL;
  if ((s.mlx = mlx_init()))
    {
      parse_conf(&c, &b, &spot, av[1]);
      if (c.winx > 1280 || c.winy > 1024)
	xerror("Invalid window size\n");
      s.win_x = c.winx;
      s.win_y = c.winy;
      if (check_list_size(b) > 0)
	{
	  s.img = mlx_new_image(s.mlx, c.winx, c.winy);
	  s.data = mlx_get_data_addr(s.img, &s.bpp, &s.sizeline, &s.endian);
	  s.win = mlx_new_window(s.mlx, c.winx, c.winy, "<|** Raytracer **|>");
	  remplis_image(&s, &c, b, spot);
	  mlx_put_image_to_window(s.mlx, s.win, s.img, 0, 0);
	  mlx_key_hook(s.win, gere_key, &s);
	  mlx_expose_hook(s.win, gere_expose, &s);
	  mlx_loop(s.mlx);
	}
      else
	xerror("No Object found\n");
    }
  else
    xerror("Can't Connect to Server X\n");
}
