/*
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
