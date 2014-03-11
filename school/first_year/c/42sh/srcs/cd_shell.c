/*
** cd_shell.c for cd_shell in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:49:32 2008 yoann jaspar
** Last update Fri May 30 16:52:44 2008 yoann jaspar
*/

#include "sh.h"

int	check_the_env(char **env, char *str)
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
	  if (my_strlen2(env[i]) == my_strlen(str))
	    if (l == my_strlen(str))
	      return (i);
	}
      i++;
    }
  return (-1);
}

char	*refresh_pwd(char *str)
{
  int	i;
  int	k;
  int	j;
  char	*prev;

  j = 0;
  i = 0;
  k = check_the_env(environ, "PWD");
  if (k == (-1))
    exit (0);
  while (environ[k][j] != '=')
    j++;
  j++;
  prev = strdup(&environ[k][j]);
  while (str[i] != '\0')
    environ[k][j++] = str[i++];
  environ[k][j] = '\0';
  return (prev);
}

void	cd_shell(char *str, int flag, t_sh *sh)
{
  int	i;

  i = 0;
  if (*str == '-')
    its_cd_moins(sh, &str);
  if (chdir(str) != 0)
    {
      my_putstr("\e[1;32m");
      my_putstr(str);
      my_putstr("\e[1;34m");
      my_putstr(" : No such file or directory.\n");
      my_putstr("\e[0m");
    }
  else
    {
      save_the_last(sh, refresh_pwd(str));
    }
  if (flag == 1)
    my_read(sh);
}
