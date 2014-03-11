/*
** rm_good_env.c for rm_good_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:56:29 2008 yoann jaspar
** Last update Tue Jun  3 17:55:49 2008 yoann jaspar
*/

#include "sh.h"

char	**rm_good_env(char **environ, int ref_env)
{
  int	i;

  i = 0;
  while (environ[ref_env][i++] != '=')
    ;
  environ[ref_env][i] = '\0';
  i = 0;
  my_putstr("\e[1;34m");
  while (environ[ref_env][i] != '=')
    my_putchar(environ[ref_env][i++]);
  my_putstr("\e[1;32m : Has been deleted\n\n\e[0m");
  return (environ);
}
