/*
** init.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:20:46 2008 emilien ampe
** Last update Fri May 23 12:13:20 2008 emilien ampe
*/

#include "raytracer.h"

int		(*tab[])() =
{
  inter_plan,
  inter_sph,
  inter_cone,
  inter_cyl,
  inter_para,
};

int		(*tab1[])() =
{
  sh_inter_plan,
  sh_inter_sph,
  sh_inter_cone,
  sh_inter_cyl,
};
