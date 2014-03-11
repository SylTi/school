/*
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
