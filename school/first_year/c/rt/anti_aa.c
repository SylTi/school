calc.c                                                                                              000644  214705  000000  00000001642 11016020173 013077  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** calc.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:23:45 2008 emilien ampe
** Last update Fri May 23 11:42:21 2008 emilien ampe
*/

#include "raytracer.h"

extern int	(*tab[])();

unsigned long	calc(t_coord *c, t_list *b, t_list *spot)
{
  double	k;
  t_list	*one;
  t_obj		*obj;
  t_obj		*tmp;

  one = b;
  c->shadow = 0;
  tmp = 0;
  k = 100000;
  c->shadow++;
  while (b)
    {
      obj = b->data;
      obj->pcs_shadow = c->shadow;
      trans(c, obj);
      (c->k_k) = tab[obj->type - 1](c, obj);
      de_trans(c, obj);
      if ((c->k_k) == 1 && c->lambda < k && c->lambda > 0.000001)
	{
	  c->max_shadow = c->shadow;
	  k = c->lambda;
	  tmp = obj;
	}
      c->shadow++;
      b = b->next;
    }
  if (k > 99999.0)
    return ((unsigned long)NULL);
  c->lambda = k;
  return (light(c, one, spot, tmp));
}
                                                                                              calc_cosa.c                                                                                         000644  214705  000000  00000001100 11016020173 014071  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** calc_cosa.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:31:46 2008 emilien ampe
** Last update Thu May 22 18:31:57 2008 emilien ampe
*/

#include "raytracer.h"

double		calcul_cosa(t_coord *c)
{
  double	cosa;

  c->Norme_N = sqrt(SQ(c->Nx) + SQ(c->Ny) + SQ(c->Nz));
  c->Norme_P = sqrt(SQ(c->Lx) + SQ(c->Ly) + SQ(c->Lz));
  c->scal_NP = (c->Lx * c->Nx) + (c->Ly * c->Ny) + (c->Lz * c->Nz);
  cosa = (c->scal_NP / (c->Norme_N * c->Norme_P));
  return (cosa);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                calc_delta.c                                                                                        000644  214705  000000  00000002500 11016020173 014242  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** calc_delta.c for calc delta in /u/epitech_2012/ampe_e/public/raytracer/lolo/test/FAIT
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 22 17:38:34 2008 sylvain tissier
** Last update Thu May 22 17:46:42 2008 sylvain tissier
*/

#include "raytracer.h"

void	calc_delta_cone(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) - (b->var * SQ(c->Vz));
  c->bx = 2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy) - (b->var * c->o_z * c->Vz));
  c->cx = SQ(c->o_x) + SQ(c->o_y) - (b->var * SQ(c->o_z));
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void	calc_delta_cyl(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy);
  c->bx = 2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy));
  c->cx = SQ(c->o_x) + SQ(c->o_y) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void	calc_delta_sph(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) + SQ(c->Vz);
  c->bx = 2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy) + (c->o_z * c->Vz));
  c->cx = SQ(c->o_x) + SQ(c->o_y) + SQ(c->o_z) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void	calc_delta_para(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy);
  c->bx = (2 * ((c->o_x * c->Vx) + (c->o_y * c->Vy))) - (b->var * c->Vz);
  c->cx = SQ(c->o_x) + SQ(c->o_y) - (b->var * c->o_z);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}
                                                                                                                                                                                                calc_roeil.c                                                                                        000644  214705  000000  00000001221 11016020173 014262  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** calc_roeil.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:04:08 2008 emilien ampe
** Last update Fri May 23 11:39:58 2008 emilien ampe
*/

#include "raytracer.h"

void   	calc_rotation_oeil(t_coord *c)
{
  if ((MAX_ANGLES(c->o_rx) == 0) && (MIN_ANGLES(c->o_rx) == 0))
    rotation_x(&(c->y1), &(c->z1), c->o_rx);
  if ((MAX_ANGLES(c->o_ry) == 0) && (MIN_ANGLES(c->o_ry) == 0))
    rotation_y(&(c->x1), &(c->z1), c->o_ry);
  if ((MAX_ANGLES(c->o_rz) == 0) && (MIN_ANGLES(c->o_rz) == 0))
    rotation_z(&(c->x1), &(c->y1), c->o_rz);
}
                                                                                                                                                                                                                                                                                                                                                                               calc_rot.c                                                                                          000644  214705  000000  00000003701 11016020175 013763  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** cal_rot.c for  in /u/epitech_2012/ampe_e/public/raytracer/lolo/test/FAIT
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 22 17:34:32 2008 sylvain tissier
** Last update Fri May 23 11:14:05 2008 emilien ampe
*/

#include "raytracer.h"

void	calc_li_rotation(t_coord *c, t_obj *b)
{
  if (b->ax != 0.000001 || b->ax != 360.0)
    rotation_x(&(c->Py), &(c->Pz), -b->ax);
  if (b->ay != 0.000001 || b->ay != 360.0)
    rotation_y(&(c->Px), &(c->Pz), -b->ay);
  if (b->az != 0.000001 || b->az != 360.0)
    rotation_z(&(c->Px), &(c->Py), -b->az);
}

void	calc_li_rotation_inv(t_coord *c, t_obj *b)
{
  if (b->az != 0.000001 || b->az != 360.0)
    rotation_z(&(c->Px), &(c->Py), b->az);
  if (b->ay != 0.000001 || b->ay != 360.0)
    rotation_y(&(c->Px), &(c->Pz), b->ay);
  if (b->ax != 0.000001 || b->ax != 360.0)
    rotation_x(&(c->Py), &(c->Pz), b->ax);
}

void	calc_sh_rotation(t_coord *c, t_obj *b)
{
  if ((MAX_ANGLES(b->ax) == 0) && (MIN_ANGLES(b->ax) == 0))
    {
      rotation_x(&(c->Ny), &(c->Nz), -b->ax);
      rotation_x(&(c->Vy), &(c->Vz), -b->ax);
    }
  if ((MAX_ANGLES(b->ay) == 0) && (MIN_ANGLES(b->ay) == 0))
    {
      rotation_y(&(c->Nx), &(c->Nz), -b->ay);
      rotation_y(&(c->Vx), &(c->Vz), -b->ay);
    }
  if ((MAX_ANGLES(b->az) == 0) && (MIN_ANGLES(b->az) == 0))
    {
      rotation_z(&(c->Nx), &(c->Ny), -b->az);
      rotation_z(&(c->Vx), &(c->Vy), -b->az);
    }
}

void	calc_sh_rotation_inv(t_coord *c, t_obj *b)
{
  if ((MAX_ANGLES(b->az) == 0) && (MIN_ANGLES(b->az) == 0))
    {
      rotation_z(&(c->Vx), &(c->Vy), b->az);
      rotation_z(&(c->Nx), &(c->Ny), b->az);
    }
  if ((MAX_ANGLES(b->ay) == 0) && (MIN_ANGLES(b->ay) == 0))
    {
      rotation_y(&(c->Vx), &(c->Vz), b->ay);
      rotation_y(&(c->Nx), &(c->Nz), b->ay);
    }
  if ((MAX_ANGLES(b->ax) == 0) && (MIN_ANGLES(b->ax) == 0))
    {
      rotation_x(&(c->Vy), &(c->Vz), b->ax);
      rotation_x(&(c->Ny), &(c->Nz), b->ax);
    }
}
                                                               calc_rot2.c                                                                                         000644  214705  000000  00000002536 11016020173 014050  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** cal_rot2.c for  in /u/epitech_2012/ampe_e/public/raytracer/lolo/test/FAIT
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 22 17:37:27 2008 sylvain tissier
** Last update Thu May 22 17:46:07 2008 sylvain tissier
*/

#include "raytracer.h"

void	calc_rotation(t_coord *c, t_obj *b)
{
  if ((MAX_ANGLES(b->ax) == 0) && (MIN_ANGLES(b->ax) == 0))
    {
      rotation_x(&(c->o_y), &(c->o_z), -b->ax);
      rotation_x(&(c->Vy), &(c->Vz), -b->ax);
    }
  if ((MAX_ANGLES(b->ay) == 0) && (MIN_ANGLES(b->ay) == 0))
    {
      rotation_y(&(c->o_x), &(c->o_z), -b->ay);
      rotation_y(&(c->Vx), &(c->Vz), -b->ay);
    }
  if ((MAX_ANGLES(b->az) == 0) && (MIN_ANGLES(b->az) == 0))
    {
      rotation_z(&(c->o_x), &(c->o_y), -b->az);
      rotation_z(&(c->Vx), &(c->Vy), -b->az);
    }
}

void	calc_rotation_inv(t_coord *c, t_obj *b)
{
  if ((MAX_ANGLES(b->az) == 0) && (MIN_ANGLES(b->az) == 0))
    {
      rotation_z(&(c->Vx), &(c->Vy), b->az);
      rotation_z(&(c->o_x), &(c->o_y), b->az);
    }
  if ((MAX_ANGLES(b->ay) == 0) && (MIN_ANGLES(b->ay) == 0))
    {
      rotation_y(&(c->Vx), &(c->Vz), b->ay);
      rotation_y(&(c->o_x), &(c->o_z), b->ay);
    }
  if ((MAX_ANGLES(b->ax) == 0) && (MIN_ANGLES(b->ax) == 0))
    {
      rotation_x(&(c->Vy), &(c->Vz), b->ax);
      rotation_x(&(c->o_y), &(c->o_z), b->ax);
    }
}
                                                                                                                                                                  check_liste_size.c                                                                                  000644  214705  000000  00000000642 11016020173 015503  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** check_liste_size.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 16:19:03 2008 emilien ampe
** Last update Fri May 23 13:30:15 2008 yoann jaspar
*/

#include "raytracer.h"

int		check_list_size(t_list *l)
{
  int	i;
  
  i = 0;
  while (l)
    {
      l = l->next;
      i++;
    }
  return (i);
}
                                                                                              fill.c                                                                                              000644  214705  000000  00000002667 11016020173 013133  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** fill.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 20:07:05 2008 emilien ampe
** Last update Fri May 23 13:14:59 2008 emilien ampe
*/

#include "raytracer.h"

t_parse gl_parse[] =
  {
    {"orig:", orig},
    {"rota:", rota},
    {"var:", var},
    {"col:", col},
    {"trans:", transpa},
    {"refle:", refle},
    {"pl_va:", pl_va},
    {"pl_vb:", pl_vb},
    {"dec_x:", dec_x},
    {"sci_x:", sci_x},
    {"dec_y:", dec_y},
    {"sci_y:", sci_y},
    {"dec_z:", dec_z},
    {"sci_z:", sci_z},
    {0, 0},
  };


void            fill_empty_obj(t_obj *obj)
{
  obj->xt = 0.0;
  obj->yt = 0.0;
  obj->zt = 0.0;
  obj->ax = 0.0;
  obj->ay = 0.0;
  obj->az = 0.0;
  obj->var = 0.0;
  obj->col = (unsigned long)0;
  obj->trans = 0.0;
  obj->decx_on = 0;
  obj->decy_on = 0;
  obj->decz_on = 0;
  obj->pl_type = 0;
  obj->sci_x_on = 0;
  obj->sci_y_on = 0;
  obj->sci_z_on = (int)0;
}

void		fill(t_list **b, t_coord *t_x, int type)
{
  char		*str;
  int		i;
  t_obj		*obj;

  obj = xmalloc(1 * sizeof(*obj));
  obj->type = type;
  fill_empty_obj(obj);
  while ((str = get_next_line(t_x->fd)))
    {
      i = 0;
      while (gl_parse[i].pars != 0)
	{
	  if (strstr(str, gl_parse[i].pars))
	    gl_parse[i].fct(obj, t_x, str);
	  i++;
	}
      if (!strncmp("******", str, 6))
        {
          my_put_in_list(b, obj);
          break;
        }
    }
}
                                                                         fill_3_space.c                                                                                      000644  214705  000000  00000001234 11016020173 014515  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** fill_3_space.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:13:07 2008 emilien ampe
** Last update Fri May 23 13:52:59 2008 emilien ampe
*/

#include "raytracer.h"

void		fill_3_space(char *str, t_coord *t_x)
{
  int		i;
  int		j;

  t_x->t[0] = 0.0;
  t_x->t[1] = 0.0;
  t_x->t[2] = 0.0;
  for (i = 0, j = 0; str[i]; i++)
    {
      if ((my_isnum(str[i])) || str[i] == '-')
	{
	  t_x->t[j++] = atof(&str[i]);
	  i++;
	  while (my_isnum(str[i]))
	    i++;
	}
      else if (str[i] == '}')
	break;
      else
	continue;
    }
  if (str)
    free(str);
}
                                                                                                                                                                                                                                                                                                                                                                    fill_oeil.c                                                                                         000644  214705  000000  00000001200 11016020173 014121  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                                                                                                                                                                                                                                                                fill_space.c                                                                                        000644  214705  000000  00000001046 11016020174 014275  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** fill_space.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:56:05 2008 emilien ampe
** Last update Fri May 23 00:04:34 2008 emilien ampe
*/

#include "raytracer.h"

int		my_isnum(char c)
{
  if ((c >= '0' && c <= '9') || c == '.')
    return (1);
  return (0);
}

char	*fill_space(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((my_isnum(str[i])) || str[i] == '-')
	return (&str[i]);
      i++;
    }
  return (NULL);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          fill_spot.c                                                                                         000644  214705  000000  00000001232 11016020173 014163  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                                                                                                                                                                                                                                      fill_win_size.c                                                                                     000644  214705  000000  00000001017 11016020174 015027  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** fill_win_size.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:01:38 2008 emilien ampe
** Last update Thu May 22 22:03:48 2008 emilien ampe
*/

#include "raytracer.h"

void	fill_win_size(t_coord *t_x, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (my_isnum(str[i]))
	t_x->t[j++] = atoi(&str[i]);
      while (str[i] && str[i] != ' ' && str[i] != '\t')
	  i++;
      i++;
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 gere.c                                                                                              000644  214705  000000  00000001664 11016020173 013123  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                            get_col.c                                                                                           000644  214705  000000  00000000675 11016020173 013616  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** get_col.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:14:11 2008 emilien ampe
** Last update Fri May 23 14:48:50 2008 emilien ampe
*/

#include "raytracer.h"

unsigned int	get_col(double col[3])
{
  t_color_x	color;

  color.c_color[0] = col[2];
  color.c_color[1] = col[1];
  color.c_color[2] = col[0];
  return (color.color);
}
                                                                   get_next_line.c                                                                                     000644  214705  000000  00000003462 11016020173 015023  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** get_next_line.h for get next line in /u/epitech_2012/ampe_e/cu/rendu/c/get_next_line
**
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
**
** Started on  Mon Nov 19 11:30:01 2007 emilien ampe
** Last update Fri May 23 13:22:47 2008 emilien ampe
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*get_read(t_var *s, int fd)
{
  int		i;

  if (s->pos == 0 || s->pos == BUFF_READ)
    {
      i = 0;
      while (i < BUFF_READ)
	s->buffer[i++] = '\0';
      s->pos = 0;
      if(!(xread(fd, s->buffer, BUFF_READ, s)))
	{
	  s->line[s->j] = '\0';
	  s->ret = 1;
	  return (s->line);
	}
    }
  return (NULL);
}

void		*xmalloc(size_t size)
{
  int		*i;

  i = malloc(size);
  if (i == NULL)
    exit (1);
  return (i);
}

int		xread(int d, void *buf, size_t nbytes, t_var *s)
{
  int		ret;
  static int	ct = 0;

  ret = read(d, buf, nbytes);
  if (ret <= 0)
    {
      if (ct == 1)
	{
	  free(s->line);
	  return (0);
	}
      else
	{
	  ct++;
	  return (0);
	}
    }
  return (ret);
}

void		get_result(t_var *s)
{
  if (s->buffer[s->pos++] == '\n')
    {
      s->line[s->j] = '\0';
      s->ret2 = 1;
      return ;
    }
  else
    if (s->buffer[s->pos] == '\0' || s->j != BUFF_SIZE)
      {
	s->pos = 0;
	if(s->j == BUFF_SIZE)
	  {
	    s->line[s->j] = '\0';
	    s->ret2 = 1;
	    return ;
	  }
      }
}

char		*get_next_line(const int fd)
{
  static t_var		s;

  if (s.inte == 1)
    return (NULL);
  s.j = 0;
  s.line = xmalloc(sizeof(s.line) * (BUFF_SIZE + 1));
  while (s.j < BUFF_SIZE)
    {
      get_read(&s, fd);
      if (s.ret == 1)
	{
	  s.inte = 1;
	  return (s.line);
	}
      while (s.buffer[s.pos] != '\n' && s.buffer[s.pos] != '\0')
	s.line[s.j++] = s.buffer[s.pos++];
      get_result(&s);
      if (s.ret2 == 1)
	{
	  s.ret2 = 0;
	  return (s.line);
	}
    }
  return (NULL);
}
                                                                                                                                                                                                              gl_parse1.c                                                                                         000644  214705  000000  00000001777 11016020173 014063  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** gl_parse1.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:18:01 2008 emilien ampe
** Last update Fri May 23 13:29:55 2008 emilien ampe
*/

#include "raytracer.h"

void	orig(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->xt = t_x->t[0];
  obj->yt = t_x->t[1];
  obj->zt = t_x->t[2];
}

void	rota(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->ax = (t_x->t[0] * M_PI) / 180;
  obj->ay = (t_x->t[1] * M_PI) / 180;
  obj->az = (t_x->t[2] * M_PI) / 180;
}

void	var(t_obj *obj, t_coord *t_x, char *str)
{
  t_x->t[0] = (double)0;
  t_x->t[1] = (double)0;
  t_x->t[2] = (double)0;
  obj->var = atof(fill_space(str));
}

void	col(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->col = get_col(t_x->t);
}

void	transpa(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->trans = t_x->t[0];
  obj->indice_trans = t_x->t[1];
}
 gl_parse2.c                                                                                         000644  214705  000000  00000002267 11016020175 014061  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** gl_parse2.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Fri May 23 13:17:31 2008 emilien ampe
** Last update Fri May 23 13:17:55 2008 emilien ampe
*/

#include "raytracer.h"

void	refle(t_obj *obj, t_coord *t_x, char *str)
{
  t_x->t[0] = (double)0;
  t_x->t[1] = (double)0;
  t_x->t[2] = (double)0;
  obj->refle = atof(fill_space(str));
}

void	dec_x(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->decx_on = (int)(t_x->t[0]);
  obj->dmin_x = (double)(t_x->t[1]);
  obj->dmax_x = (double)(t_x->t[2]);
}

void	sci_x(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->sci_x_on = (int)(t_x->t[0]);
  obj->sci_x_mod = (double)(t_x->t[1]);
  obj->sci_x_pas = (double)(t_x->t[2]);
}

void	dec_y(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->decy_on = (int)(t_x->t[0]);
  obj->dmin_y = (double)(t_x->t[1]);
  obj->dmax_y = (double)(t_x->t[2]);
}

void	sci_y(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->sci_y_on = (int)(t_x->t[0]);
  obj->sci_y_mod = (double)(t_x->t[1]);
  obj->sci_y_pas = (double)(t_x->t[2]);
}
                                                                                                                                                                                                                                                                                                                                         gl_parse3.c                                                                                         000644  214705  000000  00000001670 11016020175 014057  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** gl_parse3.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Fri May 23 13:18:12 2008 emilien ampe
** Last update Fri May 23 13:18:40 2008 emilien ampe
*/

#include "raytracer.h"

void	dec_z(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->decz_on = (int)(t_x->t[0]);
  obj->dmin_z = (double)(t_x->t[1]);
  obj->dmax_z = (double)(t_x->t[2]);
}

void	sci_z(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->sci_z_on = (int)(t_x->t[0]);
  obj->sci_z_mod = (double)(t_x->t[1]);
  obj->sci_z_pas = (double)(t_x->t[2]);
}

void	pl_va(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->pl_type = t_x->t[0];
  obj->pl_vax = t_x->t[1];
  obj->pl_vay = t_x->t[2];
}

void	pl_vb(t_obj *obj, t_coord *t_x, char *str)
{
  fill_3_space(str, t_x);
  obj->pl_vbx = t_x->t[0];
  obj->pl_vby = t_x->t[1];
}
                                                                        init.c                                                                                              000644  214705  000000  00000000705 11016020172 013136  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** init.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:20:46 2008 emilien ampe
** Last update Fri May 23 12:13:20 2008 emilien ampe
*/

#include "raytracer.h"

int		(*tab[])() =
{
  inter_plan,
  inter_sph,
  inter_cone,
  inter_cyl,
  inter_para,
};

int		(*tab1[])() =
{
  sh_inter_plan,
  sh_inter_sph,
  sh_inter_cone,
  sh_inter_cyl,
};
                                                           init_n.c                                                                                            000644  214705  000000  00000002354 11016020173 013456  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** init_n.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:30:38 2008 emilien ampe
** Last update Fri May 23 03:28:32 2008 emilien ampe
*/

#include "raytracer.h"

void		init_n(t_coord *c, t_obj *obj)
{
  double	Scal_VN;

  li_trans(c, obj);

  if (obj->type == PLAN)
    {
      c->Nx = 0;
      c->Ny = 0;
      c->Nz = 100;
      if ((obj->ax != 0) || (obj->ay != 0) || (obj->az != 0))
	{
	  rotation_x(&(c->Ny), &(c->Nz), obj->ax);
	  rotation_y(&(c->Nx), &(c->Nz), obj->ay);
	  rotation_z(&(c->Nx), &(c->Ny), obj->az);
	}
    }
  else if (obj->type == CYLINDR)
    {
      c->Nx = c->Px;
      c->Ny = c->Py;
      c->Nz = 0;
    }
  else if (obj->type == SPHERE)
    {
      c->Nx = c->Px;
      c->Ny = c->Py;
      c->Nz = c->Pz;
    }
  else if (obj->type == CONE)
    {
      c->Nx = c->Px;
      c->Ny = c->Py;
      c->Nz = obj->var * c->Pz;
    }
  else if (obj->type == PARABO)
    {
      c->Nx = c->Px;
      c->Ny = c->Py;
      c->Nz = -(obj->var);
    }
  Scal_VN = c->Nx * c->x1 + c->Ny * c->y1 + c->Nz * c->z1;
  if (Scal_VN > 0)
    {
      c->Nx *= (-1);
      c->Ny *= (-1);
      c->Nz *= (-1);
    }
  de_li_trans(c, obj);
}
                                                                                                                                                                                                                                                                                    init_sX.c                                                                                           000644  214705  000000  00000002225 11016020173 013610  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                                                                                                                                                                                                                                           inter.c                                                                                             000644  214705  000000  00000006247 11016020173 013324  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** inter.c for intersection  in /u/epitech_2012/ampe_e/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 19:53:54 2008 emilien ampe
** Last update Fri May 23 13:57:30 2008 emilien ampe
*/

#include "raytracer.h"

int	inter_cone(t_coord *c, t_obj *b)
{
  calc_delta_cone(c, b);
  if (c->delta >= 0.00001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int	inter_cyl(t_coord *c, t_obj *b)
{
  calc_delta_cyl(c, b);
  if (c->delta >= 0.00001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int	inter_sph(t_coord *c, t_obj *b)
{
  calc_delta_sph(c, b);
  if (c->delta >= 0.000001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int	inter_para(t_coord *c, t_obj *b)
{
  calc_delta_para(c, b);
  if (c->delta >= 0.00001)
    {
      c->lambda = -1;
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((c->lambda_1 < c->lambda_2 && c->lambda_1 > 0.000001) ||
          (c->lambda_2 < 0.000001 && c->lambda_1 > 0.000001))
        c->lambda = c->lambda_1;
      else if ((c->lambda_2 < c->lambda_1 && c->lambda_2 > 0.000001) ||
               (c->lambda_1 < 0.000001 && c->lambda_2 > 0.000001))
        c->lambda = c->lambda_2;
      else
        c->lambda = 0;
      return (1);
    }
  return (0);
}

int             inter_plan(t_coord *c, t_obj *b)
{
  c->lambda = -((c->o_z) / c->Vz);
  if (c->lambda > (double)0)
    {
      if (b->pl_type > 0)
        {
          c->Px = c->o_x + (c->lambda * c->Vx);
          c->Py = c->o_y + (c->lambda * c->Vy);
        }
      if (if_plan_limite(c, b) == 1)
	return (1);
      return (0);
    }
  return (0);
}
                                                                                                                                                                                                                                                                                                                                                         li_trans.c                                                                                          000644  214705  000000  00000001162 11016020173 014005  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                                                                                                                                                                                                                                                                              light.c                                                                                             000644  214705  000000  00000003243 11016020173 013303  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** light.c for light in /u/epitech_2012/ampe_e/public/raytracer/lolo/test/FAIT
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 22 18:03:57 2008 emilien ampe
** Last update Fri May 23 13:20:50 2008 emilien ampe
*/

#include "raytracer.h"

extern int	(*tab1[])();

void	light_calc_p(t_coord *c)
{
  c->Px = c->o_x + (c->lambda * c->x1);
  c->Py = c->o_y + (c->lambda * c->y1);
  c->Pz = c->o_z + (c->lambda * c->z1);
}

void	light_calc_l(t_coord *c, t_spot *tmp)
{
  c->Lx = tmp->x_spot - c->Px;
  c->Ly = tmp->y_spot - c->Py;
  c->Lz = tmp->z_spot - c->Pz;
}

void	light_calc_color(t_coord *c, t_color_x *co)
{
  int   i;

  i= 0;
  while (i < 4)
    {
      co->c_color[i] = MULT_COLOR(co->c_color[i], (double)(c->isf) * (double)(c->cosa) * (double)(c->light_var));
      i++;
    }
}

void	light_calc_tr(t_coord *c, t_list *b, t_list *spot, t_color_x *co, t_obj *obj)
{
  if (obj->trans > 0.0)
    co->color = transparancy(c, b, spot, *co, obj);
  else if (obj->refle > 0.0)
    co->color = reflect(c, b, spot, *co, obj);
}

unsigned long	light(t_coord *c, t_list *b, t_list *spot, t_obj *obj)
{
  t_color_x	co;
  t_list	*sp;
  t_spot	*tmp;

  co.color = obj->col;
  light_calc_p(c);
  init_n(c, obj);
  c->cosa = 0.0;
  c->light_var = 0.0;
  sp = spot;
  while (sp)
    {
      tmp = sp->data;
      (c->light_var) += tmp->var;
      light_calc_l(c, tmp);
      c->cosa = MAX_COSA((c->cosa), calcul_cosa(c));
      sp = sp->next;
    }
  c->light_var = MAX_LIGHT(c->light_var);
  if (obj->trans > 0.0)
    c->isf = 1.0;
  else
    c->isf = shadow(c, b, spot);
  light_calc_color(c, &co);
  light_calc_tr(c, b, spot, &co, obj);
  return (co.color);
}
                                                                                                                                                                                                                                                                                                                                                             load.c                                                                                              000644  214705  000000  00000001553 11016020173 013115  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                     main.c                                                                                              000644  214705  000000  00000000616 11016020173 013121  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** main.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jan 10 13:00:36 2006 emilien ampe
** Last update Fri May 23 06:10:27 2008 emilien ampe
*/

#include "raytracer.h"

int		main(int ac, char **av)
{
  if (ac != 2)
    xerror("Usage: [exe][conf_file]\n");
  else
    init_sX(av);
  return (0);
}
                                                                                                                  my_put_in_list.c                                                                                    000644  214705  000000  00000000762 11016020173 015235  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** my_put_in_list.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Wed Oct 19 15:36:01 2008 emilien ampe
** Last update Fri May 23 13:25:06 2008 emilien ampe
*/

#include "raytracer.h"

void		my_put_in_list(t_list **l, void *d)
{
  t_list	*new_elem;
  t_list	*cur_list;

  cur_list = *l;
  new_elem = xmalloc(1 * sizeof(*new_elem));
  new_elem->data = d;
  new_elem->next = cur_list;
  *l = new_elem;
}
              ombres1.c                                                                                           000644  214705  000000  00000005423 11016020173 013546  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** ombres1.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:46:34 2008 emilien ampe
** Last update Fri May 23 14:44:33 2008 paul bourjac
*/

#include "raytracer.h"

extern int	(*tab1[])();

double		shadow(t_coord *c, t_list *b, t_list *sp)
{
  double	flag;
  t_list	*one;
  t_obj		*obj;
  t_spot	*tmp;

  sh_calc_n(c);
  flag = (double)1;
  while (sp)
    {
      tmp = sp->data;
      sh_calc_lsh(c, tmp);
      one = b;
      while (one)
	{
	  obj = one->data;
	  sh_trans(c, obj);
	  if (obj->type != PLAN)
	    if (((tab1[obj->type - 1](c, obj)) == 1)
		&& (obj->pcs_shadow != c->max_shadow))
	      flag -= c->coef_spot;
	  sh_de_trans(c, obj);
	  one = one->next;
	}
      sp = sp->next;
    }
  if (flag < (double)0)
    return ((double)0);
  return (flag);
}

int		sh_inter_cone(t_coord *c, t_obj *b)
{
  sh_calc_delta_cone(c, b);
  if (c->delta >= 0.0001)
    {
      c->lambda = (double)(-1);
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / ((double)2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / ((double)2 * c->ax);
      if ((MAX_LAMBDA(c->lambda_1, c->lambda_2)) ||
	  (NEG(c->lambda_2) && NO_NEG(c->lambda_1)))
	c->lambda = c->lambda_1;
      else if (MAX_LAMBDA(c->lambda_2, c->lambda_1) ||
	       (NEG(c->lambda_1) && NO_NEG(c->lambda_2)))
	c->lambda = c->lambda_2;
      else
	c->lambda = (double)0;
      if (NO_NEG(c->lambda) && c->lambda < (double)1)
	return (1);
    }
  return (0);
}

int		sh_inter_cyl(t_coord *c, t_obj *b)
{
  sh_calc_delta_cyl(c, b);
  if (c->delta >= 0.0001)
    {
      c->lambda = (double)(-1);
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / ((double)2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / ((double)2 * c->ax);
      if ((MAX_LAMBDA(c->lambda_1, c->lambda_2)) ||
	  (NEG(c->lambda_2) && NO_NEG(c->lambda_1)))
	c->lambda = c->lambda_1;
      else if (MAX_LAMBDA(c->lambda_2, c->lambda_1) ||
	       (NEG(c->lambda_1) && NO_NEG(c->lambda_2)))
	c->lambda = c->lambda_2;
      else
	c->lambda = (double)0;
      if (NO_NEG(c->lambda) && c->lambda < (double)1)
	return (1);
    }
  return (0);
}

int		sh_inter_sph(t_coord *c, t_obj *b)
{
  sh_calc_delta_sph(c, b);
  if (c->delta >= (double)(0))
    {
      c->lambda = (double)(-1);
      c->lambda_1 = ((-c->bx) - sqrt(c->delta)) / (2 * c->ax);
      c->lambda_2 = ((-c->bx) + sqrt(c->delta)) / (2 * c->ax);
      if ((MAX_LAMBDA(c->lambda_1, c->lambda_2)) ||
	  (NEG(c->lambda_2) && NO_NEG(c->lambda_1)))
	c->lambda = c->lambda_1;
      else if (MAX_LAMBDA(c->lambda_2, c->lambda_1) ||
	       (NEG(c->lambda_1) && NO_NEG(c->lambda_2)))
	c->lambda = c->lambda_2;
      else
	c->lambda = (double)0;
      if (NO_NEG(c->lambda) && c->lambda < (double)1)
	return (1);
    }
  return (0);
}
                                                                                                                                                                                                                                             ombres2.c                                                                                           000644  214705  000000  00000002361 11016020173 013545  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** ombres2.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:47:28 2008 emilien ampe
** Last update Fri May 23 14:42:29 2008 paul bourjac
*/

#include "raytracer.h"

int		sh_inter_plan(t_coord *c, t_obj *b)
{
  b = b;
  c->lambda = -((c->Nz) / c->Lsh_z);
  c->lambda_2 = -((c->o_z) / c->Vz);
  if (c->lambda > 0.00001 && c->lambda < 1.0000)
    return (1);
  return (0);
}

void		sh_calc_delta_cone(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) - (b->var * SQ(c->Vz));
  c->bx = 2 * ((c->Nx * c->Vx) + (c->Ny * c->Vy) - (b->var * c->Nz * c->Vz));
  c->cx = SQ(c->Nx) + SQ(c->Ny) - (b->var * SQ(c->Nz));
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void		sh_calc_delta_cyl(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy);
  c->bx = 2 * ((c->Nx * c->Vx) + (c->Ny * c->Vy));
  c->cx = SQ(c->Nx) + SQ(c->Ny) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}

void		sh_calc_delta_sph(t_coord *c, t_obj *b)
{
  c->ax = SQ(c->Vx) + SQ(c->Vy) + SQ(c->Vz);
  c->bx = 2 * ((c->Nx * c->Vx) + (c->Ny * c->Vy) + (c->Nz * c->Vz));
  c->cx = SQ(c->Nx) + SQ(c->Ny) + SQ(c->Nz) - SQ(b->var);
  c->delta = SQ(c->bx) - (4 * c->ax * c->cx);
}
                                                                                                                                                                                                                                                                               parse_conf.c                                                                                        000644  214705  000000  00000002266 11016020173 014317  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** parse_conf.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 15:58:19 2008 emilien ampe
** Last update Fri May 23 14:47:51 2008 emilien ampe
*/

#include "raytracer.h"

t_elem	gl_elem[] =
  {
    {"Oeil", prep_oeil, 0},
    {"Spot", prep_spot, 0},
    {"Plan", fill, 1},
    {"Sphere", fill, 2},
    {"Cone", fill, 3},
    {"Cylindre", fill, 4},
    {"WINDOW", prep_window, 0},
    {"Anti_Aliasing", prep_aa, 0},
    {0, 0, 0},
  };

void   	parse_conf(t_coord *t_x, t_list **b, t_list **spot, char *file)
{
  int		i;
  
  t_x->spot = spot;
  if (!access(file, R_OK))
    {
      *b = NULL;
      open_conf(t_x, file);
      while ((t_x->str = get_next_line(t_x->fd)))
	{
	  if (t_x->str && t_x->str[0] != '*')
	    {
	      if (!strncmp(t_x->str, "FIN_CONF", 3))
		{
		  close(t_x->fd);
		  break;
		}
	      i = 0;
	      while (gl_elem[i].pars != 0)
		{
		  if (!strncmp(gl_elem[i].pars, t_x->str, strlen(gl_elem[i].pars)))
		    gl_elem[i].fct(b, t_x, gl_elem[i].type);
		  i++;
		}
	      free(t_x->str);
	    }
	}
    }
  else
    xerror("Fichier de configuration inexistant\n");
}
                                                                                                                                                                                                                                                                                                                                          plan_limite.c                                                                                       000644  214705  000000  00000000770 11016020173 014473  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** plan_limite.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:23:10 2008 emilien ampe
** Last update Fri May 23 14:45:58 2008 emilien ampe
*/

#include "raytracer.h"

int	if_plan_limite(t_coord *c, t_obj *b)
{
  if (b->pl_type == 2)
    {
      if (((SQ(c->Px) + SQ(c->Py)) < SQ(b->pl_vax))
	  && ((SQ(c->Px) + SQ(c->Py)) > SQ(b->pl_vay)))
	return (1);
      return (0);
    }
  return (1);
}
        prepare.c                                                                                           000644  214705  000000  00000001601 11016020173 013626  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** prepare.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 16:16:47 2008 emilien ampe
** Last update Fri May 23 13:41:29 2008 emilien ampe
*/

#include "raytracer.h"

void	prep_oeil(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  fill_oeil(s);
}

void	prep_window(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  fill_win_size(s, s->str);
  s->winx = s->t[0];
  s->winy = s->t[1];
}

void	prep_spot(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  fill_spot(s->spot, s);
}

void	prep_aa(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  s->aa = atoi(fill_space(s->str));
}

void	open_conf(t_coord *t_x, char *file)
{
  if ((t_x->fd = open(file , 0, O_RDONLY)) < 0)
    xerror("Impossible d'ouvrir le fichier de configuration\n");
}
                                                                                                                               ray1.c                                                                                              000644  214705  000000  00000002662 11016020173 013054  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                              ray2.c                                                                                              000644  214705  000000  00000002336 11016020173 013053  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                                                                                                                                                                  reflection.c                                                                                        000644  214705  000000  00000002115 11016020173 014323  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** reflection.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:33:36 2008 emilien ampe
** Last update Fri May 23 13:34:15 2008 yoann jaspar
*/

#include "raytracer.h"

unsigned long		reflect(t_coord *c, t_list *b, t_list *spot, t_color_x col, t_obj *obj)
{
  int			i;
  static int		nbr_reflect = 0;
  t_color_x		tmp;
  t_reflect_transpa	save;
  
  init_n(c, obj);
  maz(&save);
  save_coord(&save, c);
  calcul_vecteur_unitaire(&save, c);
  save.Rx = REFLECT(save.Normal_x_unit, save.scal_VN_unit, save.Vision_x_unit);
  save.Ry = REFLECT(save.Normal_y_unit, save.scal_VN_unit, save.Vision_y_unit);
  save.Rz = REFLECT(save.Normal_z_unit, save.scal_VN_unit, save.Vision_z_unit);
  remplace_coord(&save, c);
  nbr_reflect++;
  if (nbr_reflect < 10)
    tmp.color = calc(c, b, spot);
  restore_coord(&save, c);
  nbr_reflect--;
  i = 0;
  while (i < 4)
    {
      col.c_color[i] = ((tmp.c_color[i] * obj->refle) + (col.c_color[i] * (1 - obj->refle)));
      i++;
    }
  return (col.color);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                   remplis_image.c                                                                                     000644  214705  000000  00000001564 11016020173 015015  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                            rotation.c                                                                                          000644  214705  000000  00000001733 11016020174 014036  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** rotation.c<2> for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 19:51:05 2008 emilien ampe
** Last update Thu May 22 19:51:22 2008 emilien ampe
*/

#include "raytracer.h"

void	rotation_x(double *y, double *z, double angle_x)
{
  double	y_tmp;
  double	z_tmp;

  y_tmp = *y;
  z_tmp = *z;
  *y = cos(-angle_x) * y_tmp - sin(-angle_x) * z_tmp;
  *z = sin(-angle_x) * y_tmp + cos(-angle_x) * z_tmp;
  return ;
}

void	rotation_y(double *x, double *z, double angle_y)
{
  double	x_tmp;
  double	z_tmp;

  x_tmp = *x;
  z_tmp = *z;
  *x = cos(angle_y) * x_tmp + sin(angle_y) * z_tmp;
  *z = -sin(angle_y) * x_tmp + cos(angle_y) * z_tmp;
  return ;
}

void	rotation_z(double *x, double *y, double angle_z)
{
  double	x_tmp;
  double	y_tmp;

  x_tmp = *x;
  y_tmp = *y;
  *x = cos(angle_z) * x_tmp - sin(angle_z) * y_tmp;
  *y = sin(angle_z) * x_tmp + cos(angle_z) * y_tmp;
  return ;
}
                                     save_coord_ref_trans.c                                                                              000644  214705  000000  00000004062 11016020173 016363  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** save_coord_ref.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 19:10:10 2008 emilien ampe
** Last update Fri May 23 13:23:45 2008 emilien ampe
*/

#include "raytracer.h"

void			save_coord(t_reflect_transpa *save, t_coord *c)
{
  save->save_x_oeil = c->o_x;
  save->save_y_oeil = c->o_y;
  save->save_z_oeil = c->o_z;
  save->save_x1 = c->x1;
  save->save_y1 = c->y1;
  save->save_z1 = c->z1;
}

void			restore_coord(t_reflect_transpa *save, t_coord *c)
{
  c->o_x = save->save_x_oeil;
  c->o_y = save->save_y_oeil;
  c->o_z = save->save_z_oeil;
  c->x1 = save->save_x1;
  c->y1 = save->save_y1;
  c->z1 = save->save_z1;
}

void			calcul_vecteur_unitaire(t_reflect_transpa *save, t_coord *c)
{
  save->Norme_Normal = NORME(c->Nx, c->Ny, c->Nz);
  save->Normal_x_unit = c->Nx / save->Norme_Normal;
  save->Normal_y_unit = c->Ny / save->Norme_Normal;
  save->Normal_z_unit = c->Nz / save->Norme_Normal;
  save->Norme_Vision = NORME(c->x1, c->y1, c->z1);
  save->Vision_x_unit = c->x1 / save->Norme_Vision;
  save->Vision_y_unit = c->y1 / save->Norme_Vision;
  save->Vision_z_unit = c->z1 / save->Norme_Vision;
  save->scal_VN_unit = (save->Normal_x_unit * save->Vision_x_unit) + (save->Normal_y_unit * save->Vision_y_unit) + (save->Normal_z_unit *  save->Vision_z_unit);
}

void			remplace_coord(t_reflect_transpa *save, t_coord *c)
{
  c->o_x = c->Px;
  c->o_y = c->Py;
  c->o_z = c->Pz;
  c->x1 = save->Rx;
  c->y1 = save->Ry;
  c->z1 = save->Rz;
}

void			maz(t_reflect_transpa *save)
{
  save->save_x_oeil = (double)0;
  save->save_y_oeil = (double)0;
  save->save_z_oeil = (double)0;
  save->save_x1 = (double)0;
  save->save_y1 = (double)0;
  save->save_z1 = (double)0;
  save->Norme_Vision = (double)0;
  save->Norme_Normal = (double)0;
  save->Normal_x_unit = (double)0;
  save->Normal_y_unit = (double)0;
  save->Normal_z_unit = (double)0;
  save->Vision_x_unit = (double)0;
  save->Vision_y_unit = (double)0;
  save->Vision_z_unit = (double)0;
  save->scal_VN_unit = (double)0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                              sh_calc.c                                                                                           000644  214705  000000  00000001100 11016020173 013556  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** sh_calc.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:09:00 2008 emilien ampe
** Last update Thu May 22 22:09:46 2008 emilien ampe
*/

#include "raytracer.h"

void		sh_calc_n(t_coord *c)
{
  c->Nx = c->o_x + (c->lambda * c->x1);
  c->Ny = c->o_y + (c->lambda * c->y1);
  c->Nz = c->o_z + (c->lambda * c->z1);
}

void		sh_calc_lsh(t_coord *c, t_spot *tmp)
{
  c->Lsh_x = tmp->x_spot - c->Nx;
  c->Lsh_y = tmp->y_spot - c->Ny;
  c->Lsh_z = tmp->z_spot - c->Nz;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                sh_trans.c                                                                                          000644  214705  000000  00000001331 11016020174 014012  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** sh_trans.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:11:53 2008 emilien ampe
** Last update Thu May 22 22:12:46 2008 emilien ampe
*/

#include "raytracer.h"

void		sh_trans(t_coord *c, t_obj *b)
{
  c->Vx = c->Lsh_x;
  c->Vy = c->Lsh_y;
  c->Vz = c->Lsh_z;
  c->Nx -= b->xt;
  c->Ny -= b->yt;
  c->Nz -= b->zt;
  if (b->ax != (double)0 || b->ay != (double)0 || b->az != (double)0)
    calc_sh_rotation(c, b);
}

void		sh_de_trans(t_coord *c, t_obj *b)
{
  if (b->ax != (double)0 || b->ay != (double)0 || b->az != (double)0)
    calc_sh_rotation_inv(c, b);
  c->Nx += b->xt;
  c->Ny += b->yt;
  c->Nz += b->zt;
}
                                                                                                                                                                                                                                                                                                       trans.c                                                                                             000644  214705  000000  00000001067 11016020173 013325  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                         transparence.c                                                                                      000644  214705  000000  00000003151 11016020173 014657  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** transparence.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:33:07 2008 emilien ampe
** Last update Thu May 22 19:46:20 2008 emilien ampe
*/

#include "raytracer.h"

unsigned long		transparancy(t_coord *c, t_list *b, t_list *spot, t_color_x col, t_obj *obj)
{
  int			i; 
  t_color_x		tmp;
  t_color_x		color;
  t_reflect_transpa	save;

  maz(&save);
  save_coord(&save, c);
  init_n(c, obj);
  if (obj->indice_trans != (double)1)
    refraction(c, obj, &save);
  c->o_x = c->Px;
  c->o_y = c->Py;
  c->o_z = c->Pz;
  tmp.color = calc(c, b, spot);
  i = 0;
  while (i < 4)
    {
      color.c_color[i] = ((tmp.c_color[i] * obj->trans) + (col.c_color[i] * (1 - obj->trans)));
      i++;
    }
  restore_coord(&save, c);
  return (color.color);
}

void			refraction(t_coord *c, t_obj *obj, t_reflect_transpa *save)
{
  double		square;

  c->Px = c->o_x + (c->lambda_2 * c->x1);
  c->Py = c->o_y + (c->lambda_2 * c->y1);
  c->Pz = c->o_z + (c->lambda_2 * c->z1);
  init_n(c, obj);
  calcul_vecteur_unitaire(save, c);
  if ((square = sqrt((1 + (SQ(obj->indice_trans) * (SQ(save->scal_VN_unit) - 1))))) < (double)0)
    square = -square;
  save->Tx = TRANSPA(obj->indice_trans, save->Vision_x_unit, save->scal_VN_unit, square, save->Normal_x_unit);
  save->Ty = TRANSPA(obj->indice_trans, save->Vision_y_unit, save->scal_VN_unit, square, save->Normal_y_unit);
  save->Tz = TRANSPA(obj->indice_trans, save->Vision_z_unit, save->scal_VN_unit, square, save->Normal_z_unit);
  c->x1 = save->Tx;
  c->y1 = save->Ty;
  c->z1 = save->Tz;
}
                                                                                                                                                                                                                                                                                                                                                                                                                       xerror.c                                                                                            000644  214705  000000  00000000511 11016020174 013511  0                                                                                                    ustar 00tissie_s                        wheel                           000000  000000                                                                                                                                                                         /*
** xerror.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Fri May 23 06:06:57 2008 emilien ampe
** Last update Fri May 23 06:07:38 2008 emilien ampe
*/

#include "raytracer.h"

void	xerror(char *str)
{
  my_putstr(str);
  exit(0);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       