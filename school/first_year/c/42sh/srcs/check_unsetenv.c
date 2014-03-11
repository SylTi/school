/*
** check_unsetenv.c for check_unsetenv in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:58:24 2008 yoann jaspar
** Last update Sat May 31 23:00:51 2008 yoann jaspar
*/

#include "sh.h"

int	check_unsetenv(char *str)
{
  int	i;
  char	unsetenv[] = "unsetenv";

  i = 0;
  while (str[i] != ' ')
    {
      if (unsetenv[i] == str[i])
	i++;
      else
	return (0);
    }
  return (i);
}
