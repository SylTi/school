/*
** change_env.c for change_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:54:21 2008 yoann jaspar
** Last update Wed Apr 23 15:38:36 2008 yoann jaspar
*/

#include "sh.h"

void	change_env(char **ref, char **env, int ref_env)
{
  int	i;
  int	j;

  i = 0;
  while (env[ref_env][i] != '=')
    i++;
  i++;
  j = 0;
  while (ref[2][j] != '\0')
    {
      env[ref_env][i] = ref[2][j];
      j++;
      i++;
    }
  env[ref_env][i] = '\0';
  my_putstr("\e[1;32mVos variables ont ete ajoute avec succes !\n\n\e[0m");
}
