/*
** cal_rot2.c for  in /u/epitech_2012/ampe_e/public/raytracer/lolo/test/FAIT
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 22 17:37:27 2008 sylvain tissier
** Last update Thu May 22 17:46:07 2008 sylvain tissier
*/

#include "raytracer.h"

void	calc_rotation(t_coord *c, t_obj *b)
{
  if ((MAX_ANGLES(b->ax) == 0) && (MIN_ANGLES(b->ax) == 0))
    {
      rotation_x(&(c->o_y), &(c->o_z), -b->ax);
      rotation_x(&(c->Vy), &(c->Vz), -b->ax);
    }
  if ((MAX_ANGLES(b->ay) == 0) && (MIN_ANGLES(b->ay) == 0))
    {
      rotation_y(&(c->o_x), &(c->o_z), -b->ay);
      rotation_y(&(c->Vx), &(c->Vz), -b->ay);
    }
  if ((MAX_ANGLES(b->az) == 0) && (MIN_ANGLES(b->az) == 0))
    {
      rotation_z(&(c->o_x), &(c->o_y), -b->az);
      rotation_z(&(c->Vx), &(c->Vy), -b->az);
    }
}

void	calc_rotation_inv(t_coord *c, t_obj *b)
{
  if ((MAX_ANGLES(b->az) == 0) && (MIN_ANGLES(b->az) == 0))
    {
      rotation_z(&(c->Vx), &(c->Vy), b->az);
      rotation_z(&(c->o_x), &(c->o_y), b->az);
    }
  if ((MAX_ANGLES(b->ay) == 0) && (MIN_ANGLES(b->ay) == 0))
    {
      rotation_y(&(c->Vx), &(c->Vz), b->ay);
      rotation_y(&(c->o_x), &(c->o_z), b->ay);
    }
  if ((MAX_ANGLES(b->ax) == 0) && (MIN_ANGLES(b->ax) == 0))
    {
      rotation_x(&(c->Vy), &(c->Vz), b->ax);
      rotation_x(&(c->o_y), &(c->o_z), b->ax);
    }
}
