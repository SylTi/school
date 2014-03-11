/*
** check_setenv.c for check_setenv in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:57:43 2008 yoann jaspar
** Last update Sat May 31 22:59:44 2008 yoann jaspar
*/

#include "sh.h"

int	check_setenv(char *str)
{
  int	i;
  char	setenv[] = "setenv";

  i = 0;
  while (str[i] != ' ')
    {
      if (setenv[i] == str[i])
	i++;
      else
	return (0);
    }
  return (i);
}
