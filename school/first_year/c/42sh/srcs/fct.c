/*
** fct.c for fct in /u/epitech_2012/jaspar_y/public/52sh
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Sat May 31 16:22:43 2008 maxime dumez
** Last update Sat May 31 23:07:45 2008 yoann jaspar
*/

#include <unistd.h>
#include "sh.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
