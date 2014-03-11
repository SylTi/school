/*
** main.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jan 10 13:00:36 2006 emilien ampe
** Last update Fri May 23 06:10:27 2008 emilien ampe
*/

#include "raytracer.h"

int		main(int ac, char **av)
{
  if (ac != 2)
    xerror("Usage: [exe][conf_file]\n");
  else
    init_sX(av);
  return (0);
}
