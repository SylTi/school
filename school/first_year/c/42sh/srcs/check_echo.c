/*
** check_echo.c for check_echo in /u/epitech_2012/jaspar_y/cu/public/62sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Wed Jun  4 15:01:12 2008 yoann jaspar
** Last update Wed Jun  4 15:02:35 2008 yoann jaspar
*/

#include "sh.h"

int	check_echo(char *str)
{
    int	i;
  char	echo[] = "echo";

  i = 0;
  while (str[i] != '\0')
    {
      if (echo[i] == str[i])
	i++;
      else
	return (0);
    }
  return (i);
}
