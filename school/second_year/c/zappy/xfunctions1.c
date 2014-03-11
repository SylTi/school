/*
** xfunctions1.c for xfunc in /u/all/cebovi_n/cu/rendu/c/zappy
** 
** Made by nikola cebovic
** Login   <cebovi_n@epitech.net>
** 
** Started on  Wed Jun  3 13:06:37 2009 nikola cebovic
** Last update Mon Jun 22 17:31:24 2009 virgile bizet
*/

#include "serveur.h"

int	xwrite(int fd, char *str, int length)
{
  int	lu;
  int	ret;

  lu = 0;
  ret = 0;
  while (lu < length)
    {
      if ((ret = write(fd, str + lu, length - lu)) == -1)
	{
	  write(2, "write error.\n", 13);
	  return (ret);
	}
      else
	{
	  lu += ret;
	}
    }
  return (length);
}

int	xread(int fd, char *str, int length)
{
  int	ret;

  if ((ret = read(fd, str, length)) == -1)
    my_putstr(2, "read error.\n");
  return (ret);
}

int	xclose(int fd)
{
  int	ret;

  if ((ret = close(fd)) == -1)
    my_putstr(2, "Close error\n");
  return (ret);
}

int	xselect(int nfds, fd_set *readfds, fd_set *writefds,
		fd_set *exceptfds, struct timeval *timeout)
{
  int	ret;

  if ((ret = select(nfds, readfds, writefds, exceptfds, timeout)) == -1)
    {
      my_putstr(2, "Select error.\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	*xmalloc(int size)
{
  void	*m;

  if ((m = malloc(size)) == NULL)
    {
      my_putstr(2, "Malloc error.\n");
      exit(EXIT_FAILURE);
    }
  return (m);
}

