/*
** rotation.c<2> for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 19:51:05 2008 emilien ampe
** Last update Thu May 22 19:51:22 2008 emilien ampe
*/

#include "raytracer.h"

void	rotation_x(double *y, double *z, double angle_x)
{
  double	y_tmp;
  double	z_tmp;

  y_tmp = *y;
  z_tmp = *z;
  *y = cos(-angle_x) * y_tmp - sin(-angle_x) * z_tmp;
  *z = sin(-angle_x) * y_tmp + cos(-angle_x) * z_tmp;
  return ;
}

void	rotation_y(double *x, double *z, double angle_y)
{
  double	x_tmp;
  double	z_tmp;

  x_tmp = *x;
  z_tmp = *z;
  *x = cos(angle_y) * x_tmp + sin(angle_y) * z_tmp;
  *z = -sin(angle_y) * x_tmp + cos(angle_y) * z_tmp;
  return ;
}

void	rotation_z(double *x, double *y, double angle_z)
{
  double	x_tmp;
  double	y_tmp;

  x_tmp = *x;
  y_tmp = *y;
  *x = cos(angle_z) * x_tmp - sin(angle_z) * y_tmp;
  *y = sin(angle_z) * x_tmp + cos(angle_z) * y_tmp;
  return ;
}
