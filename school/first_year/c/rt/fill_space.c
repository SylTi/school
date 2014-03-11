/*
** fill_space.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 21:56:05 2008 emilien ampe
** Last update Fri May 23 00:04:34 2008 emilien ampe
*/

#include "raytracer.h"

int		my_isnum(char c)
{
  if ((c >= '0' && c <= '9') || c == '.')
    return (1);
  return (0);
}

char	*fill_space(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((my_isnum(str[i])) || str[i] == '-')
	return (&str[i]);
      i++;
    }
  return (NULL);
}
