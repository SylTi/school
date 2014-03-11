/*
** match.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:26:48 2008 jean-philippe rey
** Last update Fri May 16 21:26:49 2008 jean-philippe rey
*/

#include "colle.h"

int	matchn(char *to_find, char *here)
{
  int	i;
  int	ii;

  i = 0;
  if (to_find[0] != here[0])
    return (0);
  while (here[i] != '\0' || here[i] == '=')
    {
      ii = 0;
      while (to_find[ii] == here[i])
	{
	  ii++;
	  i++;
	}
      if (to_find[ii] == 0 && here[i] == '=')
	return (1);
      i++;
    }
  return (0);
}
