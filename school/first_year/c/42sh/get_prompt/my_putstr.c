/*
** my_putstr.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:27:22 2008 jean-philippe rey
** Last update Fri May 16 21:27:23 2008 jean-philippe rey
*/

#include "colle.h"

void	my_putchar(char c)
{
  xwrite(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  xwrite(1, str, i);
}
