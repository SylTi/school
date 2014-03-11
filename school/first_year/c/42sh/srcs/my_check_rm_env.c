/*
** my_check_rm_env.c for my_check_rm_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:56:58 2008 yoann jaspar
** Last update Thu Jun 12 16:27:45 2008 maxime dumez
*/

#include "sh.h"

char	**my_check_rm_env(char **environ, char *ref)
{
  int	ref_env;

  if ((ref_env = check_env_var(environ, ref)) != (-1))
    environ = rm_good_env(environ, ref_env);
  else if (ref_env == (-1))
  {
    my_putstr("\e[1;32m");
    my_putstr(ref);
    my_putstr(" : Variable eronee.\n\e[1;34mTapez env dans le shell pour voir les variables d'environement.\e[0m\n\n");
  }
  return (environ);
}
