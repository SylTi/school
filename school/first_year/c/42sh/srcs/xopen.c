/*
** xopen.c for Gestion erreur open in /u/epitech_2012/tissie_s/cu/rendu/c/minishell1/bultins
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Sat Jan 26 16:34:50 2008 sylvain tissier
** Last update Mon Jun  9 11:32:24 2008 yoann jaspar
*/

#include "../includes/sh.h"

int	xopen(const char *path, int flags)
{
  int	fd;
  char	*sauv;

  sauv = strdup(path);
  fd = open(path, flags);
  if (fd == -1)
  {
    printf("%s : No such file or directory\n", path);
    return (0);
  }
  return (fd);
}
