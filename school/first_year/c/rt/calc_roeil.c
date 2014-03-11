/*
** calc_roeil.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 18:04:08 2008 emilien ampe
** Last update Fri May 23 11:39:58 2008 emilien ampe
*/

#include "raytracer.h"

void   	calc_rotation_oeil(t_coord *c)
{
  if ((MAX_ANGLES(c->o_rx) == 0) && (MIN_ANGLES(c->o_rx) == 0))
    rotation_x(&(c->y1), &(c->z1), c->o_rx);
  if ((MAX_ANGLES(c->o_ry) == 0) && (MIN_ANGLES(c->o_ry) == 0))
    rotation_y(&(c->x1), &(c->z1), c->o_ry);
  if ((MAX_ANGLES(c->o_rz) == 0) && (MIN_ANGLES(c->o_rz) == 0))
    rotation_z(&(c->x1), &(c->y1), c->o_rz);
}
