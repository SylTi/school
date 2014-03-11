/*
** echo_shell.c for echo_shell.c in /u/epitech_2012/jaspar_y/cu/public/62sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Wed Jun  4 15:02:58 2008 yoann jaspar
** Last update Thu Jun 12 18:17:54 2008 yoann jaspar
*/

#include "sh.h"

void	echo_shell(char *str, t_sh *sh)
{
  char	**sauv;
  int	i;
  int	fd;

  i = 0;
  sauv = NULL;
  if (sh->pipe != 0)
  {
    if (sh->pipe == 1)
      fd = open(sh->fichier, O_WRONLY| O_CREAT);
    else if (sh->pipe == 2)
      fd = open(sh->fichier, O_WRONLY| O_CREAT| O_TRUNC);
    dup2(fd, STDOUT_FILENO);
  }
  sauv = my_wordtab_sep(str, ' ');
  builtin_echo(sauv);
  if (fd)
    close (fd);
  if (sh->flag == 1)
    my_read(sh);
}
