/*
** empty_buf.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:25:18 2008 jean-philippe rey
** Last update Fri May 16 21:25:19 2008 jean-philippe rey
*/

#include "colle.h"

void	empty_buf(char *buf, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      buf[i] = 0;
      i++;
    }
}
