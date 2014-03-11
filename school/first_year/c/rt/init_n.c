/*
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
