/*
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
