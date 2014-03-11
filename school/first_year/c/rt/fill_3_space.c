/*
** fill_3_space.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 22:13:07 2008 emilien ampe
** Last update Fri May 23 13:52:59 2008 emilien ampe
*/

#include "raytracer.h"

void		fill_3_space(char *str, t_coord *t_x)
{
  int		i;
  int		j;

  t_x->t[0] = 0.0;
  t_x->t[1] = 0.0;
  t_x->t[2] = 0.0;
  for (i = 0, j = 0; str[i]; i++)
    {
      if ((my_isnum(str[i])) || str[i] == '-')
	{
	  t_x->t[j++] = atof(&str[i]);
	  i++;
	  while (my_isnum(str[i]))
	    i++;
	}
      else if (str[i] == '}')
	break;
      else
	continue;
    }
  if (str)
    free(str);
}
