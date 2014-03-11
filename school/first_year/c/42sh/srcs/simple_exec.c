/*
** simple_exec.c for simple_exec in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Fri Apr 25 14:12:27 2008 yoann jaspar
** Last update Sun Jun  1 00:32:47 2008 sylvain tissier
*/

#include "sh.h"

char	**set_path(char **path, char *temp)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  path = xmalloc(sizeof(char *) * 11);
  while (i < 10)
    path[i++] = xmalloc(sizeof(char) * 100);
  i = 0;
  while (temp[i] != '\0')
    {
      if (temp[i] == ':')
	{
	  path[j][k] = '\0';
	  j++;
	  k = 0;
	  i++;
	}
      path[j][k++] = temp[i++];
    }
  path[++j] = NULL;
  return (path);
}

char	**set_exec_path(char **path, char **temp2)
{
  int	i;
  int	j;
  int	k;

  k = 0;
  while (path[k])
    {
      j = 0;
      while (path[k][j++] != '\0')
	;
      path[k][--j] = '/';
      j += 1;
      i = 0;
      while (temp2[0][i] != '\0')
	path[k][j++] = temp2[0][i++];
      k++;
    }
  return (path);
}
