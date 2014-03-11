/*
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
