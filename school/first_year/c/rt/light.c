/*
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
