/*
** put.c for put in /u/epitech_2012/jaspar_y/public/62sh/builtins
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Wed Jun  4 17:49:48 2008 sylvain tissier
** Last update Fri Jun 13 14:33:51 2008 nicolas bonsall
*/

#include "sh.h"

/*void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
  return ;
}
*/
int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);;
}
