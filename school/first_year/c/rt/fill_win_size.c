/*
** fill_win_size.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:01:38 2008 emilien ampe
** Last update Thu May 22 22:03:48 2008 emilien ampe
*/

#include "raytracer.h"

void	fill_win_size(t_coord *t_x, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (my_isnum(str[i]))
	t_x->t[j++] = atoi(&str[i]);
      while (str[i] && str[i] != ' ' && str[i] != '\t')
	  i++;
      i++;
    }
}
