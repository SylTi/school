/*
** xterm.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:28:27 2008 jean-philippe rey
** Last update Fri May 16 21:28:28 2008 jean-philippe rey
*/

#include <stdlib.h>
#include <term.h>
#include <ncurses.h>
#include "colle.h"

char		*xgetenv(char *str)
{
  char		*res;

  if ((res = getenv(str)) == NULL)
    {
      my_putstr("cannot determine terminal\n");
      exit(0);
    }
  return (res);
}

int		xtgetent(char *bp, char *term)
{
  if (tgetent(bp, term) != 1)
    {
      my_putstr("cannot tgetent\n");
      exit(0);
    }
  return (0);
}

char		*xtgetstr(char *cap, char **area)
{
  char		*capstr;

  if ((capstr = tgetstr(cap, area)) == NULL)
    {
      my_putstr("cannot get area\n");
      exit(0);
    }
  return (capstr);
}

void		xtputs(char *str, int affcnt, int (*putc)(int))
{
  if (tputs(str, affcnt, putc)== ERR)
    {
      my_putstr("cannot execute termcaps\n");
      exit(0);
    }
}

int		my_outc(int c)
{
  my_putchar(c);
  return (0);
}
