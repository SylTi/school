/*
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
