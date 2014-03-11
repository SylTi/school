/*
** my_rm_all_env.c for my_rm_all_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:55:34 2008 yoann jaspar
** Last update Tue Jun  3 17:54:57 2008 yoann jaspar
*/

#include "sh.h"

char	**my_rm_all_env(char **environ)
{
  int	i;

  i = 0;
  while (environ[i] != NULL)
    environ[i++] = NULL;
  return (environ);
}
