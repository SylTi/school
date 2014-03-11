/*
** load.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 16:22:39 2008 emilien ampe
** Last update Fri May 23 14:02:27 2008 emilien ampe
*/

#include "raytracer.h"

void		loading(t_mlx *s, t_coord *c, int x)
{
  int		i;
  char		*prc;
  static char	*old;

  prc = xmalloc(10 * sizeof(*prc));
  mlx_string_put(s->mlx, s->win, (c->winx / 2 - 100), (c->winy / 2 - 50), 0x009933, "Loading, please wait ...");
  i = 0;  
  while (i < x)
    {
      mlx_string_put(s->mlx, s->win, i, c->winy / 2 + 10, 0xCCFF00, "||");
      i++;
    }  
  if (old)
    {
      mlx_string_put(s->mlx, s->win, x - 50 - 1, (c->winy / 2 + 25), 0x000000, old);
      free(old);
    }
  mlx_string_put(s->mlx, s->win, x - 50, (c->winy / 2 + 25), 0xFF0000, prc);
  old = strdup(prc);
  free(prc);
}
