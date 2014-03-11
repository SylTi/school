/*
** xclose.c for xclose in /u/epitech_2012/jaspar_y/public/42sh
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Tue May 27 14:57:31 2008 sylvain tissier
** Last update Wed Jun  4 17:47:00 2008 sylvain tissier
*/

#include "../includes/sh.h"

int	xclose(int fd)
{
  if ((close(fd) != 0))
    {
      my_strerror("Impossible de fermer le fd\n");
      return (-1);
    }
  return (0);
}

