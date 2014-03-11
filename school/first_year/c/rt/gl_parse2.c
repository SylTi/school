/*
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
