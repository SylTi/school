/*
** xverifs.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:28:37 2008 jean-philippe rey
** Last update Fri May 16 21:29:22 2008 jean-philippe rey
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "colle.h"

void	*xmalloc(int size)
{
  void	*tmp;

  if ((tmp = malloc(size)) == NULL)
      exit(-1);
  return (tmp);
}

int	xwrite(int output, void *buffer, int to_write)
{
  int	nb_write;

  nb_write = write(output, buffer, to_write);
  if (nb_write < 0)
    {
      my_putstr("cannot write anymore\n");
      return (0);
    }
  return (nb_write);
}

int	xread(int d, void *buf, int nbyte)
{
  int	nb_read;

  nb_read = read(d, buf, nbyte);
  if (nb_read == -1)
    {
      my_putstr("cannot read\n");
      return (0);
    }
  return (nb_read);
}

int	xopen(char *path, int more)
{
  int	fd;

  fd = open(path, more);
  if (fd == -1)
    {
      my_putstr("open error\n");
      return (1);
    }
  return (fd);
}

int	xlseek(int fd, int pos, int next)
{
  int	nb_seek;

  if ((nb_seek = lseek(fd, pos, next)) == -1)
    {
      my_putstr("LSEEK erros\n");
      exit(-1);
    }
  return (nb_seek);
}
