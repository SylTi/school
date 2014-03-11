/*
** check_env_var.c for check_env_var in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:56:06 2008 yoann jaspar
** Last update Wed Apr 23 15:53:50 2008 yoann jaspar
*/

#include "sh.h"

int	check_env_var(char **environ, char *str)
{
  int	i;
  int	j;
  int	k;
  int	l;

  i = 0;
  while (environ[i] != NULL)
    {
      k = 0;
      j = 0;
      l = 0;
      while (environ[i][j] != '=')
	{
	  if (str[k] == environ[i][j])
	    l++;
	  k++;
	  j++;
	}
      if (my_strlen(str) == l && (my_strlen(str) == my_strlen2(environ[i])))
	return (i);
      i++;
    }
  return (-1);
}
