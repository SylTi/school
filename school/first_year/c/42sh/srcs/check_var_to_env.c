/*
** check_var_to_env.c for check_var_to_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:52:23 2008 yoann jaspar
** Last update Wed Apr 23 15:41:16 2008 yoann jaspar
*/

#include "sh.h"

int	check_var_to_env(char *str, char **environ)
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
