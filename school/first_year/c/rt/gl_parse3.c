/*
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
