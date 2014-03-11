/*
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
