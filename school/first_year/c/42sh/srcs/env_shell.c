/*
** env_shell.c for env_shell in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:47:00 2008 yoann jaspar
** Last update Thu Jun 12 18:28:28 2008 yoann jaspar
*/

#include "sh.h"

void	env_shell(char **environ, t_sh *sh)
{
  int	i;
  int	j;
  int	fd;

  fd = 0;
  i = 0;
  my_putstr("\033[1;34m");
  if (sh->pipe != 0)
  {
    if (sh->pipe == 1)
      fd = open(sh->fichier, O_WRONLY| O_CREAT);
    else if (sh->pipe == 2)
      fd = open(sh->fichier, O_WRONLY| O_CREAT| O_TRUNC);
    dup2(fd, STDOUT_FILENO);
  }
  if (environ)
    while (environ[i] != NULL)
    {
      j = 0;
      while (environ[i][j] != '\0')
	my_putchar(environ[i][j++]);
      i++;
      my_putchar('\n');
    }
  my_putstr("\e[0m");
  if (fd)
    close (fd);
  if (sh->flag != 2)
    return;
}
