/*
** add_to_env.c for add_to_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:53:48 2008 yoann jaspar
** Last update Sun Jun  1 00:54:35 2008 nicolas bonsall
*/

#include "sh.h"

void	add_to_env(char **ref, char **environ)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (environ[i] != NULL)
    i++;
  environ[i] = xmalloc(sizeof(environ) * 120);
  k = 0;
  j = 0;
  while (ref[1][k] != '\0')
    {
      environ[i][j] = ref[1][k];
      j++;
      k++;
    }
  environ[i][j] = '=';
  j++;
  k = 0;
  while (ref[2][k] != '\0')
    {
      environ[i][j] = ref[2][k];
      j++;
      k++;
    }
  environ[i][j] = '\0';
  environ[++i] = NULL;
  my_putstr("\e[1;32mVos variables ont ete ajoute avec succes !\n\e[0m");
}
