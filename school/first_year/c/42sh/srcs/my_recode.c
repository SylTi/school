/*
** my_recode.c for my_recode in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:58:42 2008 yoann jaspar
** Last update Thu Jun 12 18:44:55 2008 sylvain tissier
*/

#include "sh.h"

int	my_recode2(char *str, t_sh *sh)
{
  int	i;

  i = 0;
  if ((i = check_exit(str)) == 4)
    exit_shell(sh);
  else if ((i = check_cd(str)) == 2)
    all_cd2(str, sh);
  else if ((i = check_setenv(str)) == 6)
    setenv_shell2(environ, str, sh);
  else if ((i = check_unsetenv(str)) == 8)
    unsetenv_shell2(environ, sh, str);
  if (i > 0)
    i = 1;
  return (i);
}

int	my_recode(t_sh *sh)
{
  int	i;

  i = 0;

  if ((i = check_exit(sh->temp)) == 4)
    exit_shell(sh);
  else if ((i = strncmp(sh->temp, "history", 7)) == 0)
    {
      print_tab(sh->bult->histo);
      i = 1;
    }
  else if ((i = strncmp(sh->temp, "echo", 4)) == 0)
  {
    echo_shell(sh->temp, sh);
    i = 1;
  }
  else if ((i = check_pipe(sh->temp)) == 42)
    return (42);
  else if ((i = check_env(sh->temp)) == 3)
    env_shell(environ, sh);
  else if ((i = check_cd(sh->temp)) == 2)
    all_cd(sh);
  else if ((i = check_setenv(sh->temp)) == 6)
    setenv_shell(environ, sh);
  else if ((i = check_unsetenv(sh->temp)) == 8)
    unsetenv_shell(environ, sh);
  if (i > 0)
    i = 1;
  return (i);
}
