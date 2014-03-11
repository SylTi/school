/*
** get_col.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:14:11 2008 emilien ampe
** Last update Fri May 23 14:48:50 2008 emilien ampe
*/

#include "raytracer.h"

unsigned int	get_col(double col[3])
{
  t_color_x	color;

  color.c_color[0] = col[2];
  color.c_color[1] = col[1];
  color.c_color[2] = col[0];
  return (color.color);
}
