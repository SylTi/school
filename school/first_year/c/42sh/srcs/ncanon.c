/*
** ncanon.c for ncanon in /u/epitech_2012/dumez_m/cu/rendu/c/my_select/work
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Mon Jan  7 18:58:24 2008 maxime dumez
** Last update Sat May 31 23:08:43 2008 yoann jaspar
*/

#include "confrt.h"

int	recup_term(struct termios *old)
{
  return (ioctl(0, TIOCGETA, old));
}

void	no_canonical_mode(struct termios old)
{
  old.c_lflag &= ~(ICANON | ECHO);
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (ioctl(0, TIOCSETA, &old) < 0)
    aff_error("ioctl");
}

void	restore_mode(struct termios old)
{
  if (ioctl(0, TIOCSETA, &old) < 0)
    aff_error("ioctl");
}

char	*recup_saisie(const int fd, int to_line)
{
  char	*buf;
  int	lu;

  if (!(buf = xmalloc(sizeof(*buf) * BUFF_MAX)))
    aff_error(NO_MAL);
  lu = 0;
  if (!to_line)
    {
      lu = read(fd, buf, BUFF_MAX);
      buf[lu] = '\0';
      my_putchar('\n');
    }
  else
    {
      do
	{
	  lu += read(fd, &buf[lu], BUFF_MAX);
	  buf[lu] = '\0';
	  my_putstr(&buf[lu - 1]);
	}
      while (buf[lu - 1] != '\n');
      buf[lu - 1] = '\0';
    }
  return (buf);
}

