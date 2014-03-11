/*
** my_getenv.c for my_getenv in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:42:49 2008 yoann jaspar
** Last update Mon Jun  9 17:48:41 2008 sylvain tissier
*/

#include "../includes/sh.h"

char	*my_getenv(char *str, char **env)
{
  int	i;
  int	j;
  int	k;
  int	l;

  i = 0;
  while (env[i] != NULL)
    {
      j = 0;
      k = 0;
      l = 0;
      while (str[k] != '\0')
	{
	  if (env[i][j++] == str[k++])
	    l++;
	  if (my_strlen(env[i]) == my_strlen(str))
	    if (l == my_strlen(str))
	      return (env[i]);
	}
      i++;
    }
  return (NULL);
}
