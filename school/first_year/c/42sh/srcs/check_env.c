/*
** check_env.c for check_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:47:19 2008 yoann jaspar
** Last update Wed Jun  4 15:08:30 2008 yoann jaspar
*/

#include "sh.h"

int	check_env(char *str)
{
  int	i;
  char	env[] = "env";

  i = 0;
  while (str[i] != '\0')
    {
      if (env[i] == str[i])
	i++;
      else
	return (0);
    }
  return (i);
}
