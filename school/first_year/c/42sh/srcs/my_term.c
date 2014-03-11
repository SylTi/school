/*
** my_term.c for my_term in /u/epitech_2012/jaspar_y/public/62sh
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Mon Jun  9 16:44:06 2008 maxime dumez
** Last update Wed Jun 11 17:32:57 2008 maxime dumez
*/

#include "sh.h"

int	recup_term(struct termios *old)
{
  return (ioctl(0, TIOCGETA, old));
}

void	no_canonical_mode(struct termios old)
{
  old.c_lflag &= ~(ICANON | ISIG | ECHO);
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (ioctl(0, TIOCSETA, &old) < 0)
    my_strerror("ioctl");
}

void	restore_mode(struct termios old)
{
  if (ioctl(0, TIOCSETA, &old) < 0)
    my_strerror("ioctl");
}

char	*cores(char *crstr, char **zone)
{
  char	*str;

  if ((str = tgetstr(crstr, zone)) == NULL)
    exit(1);
  return (str);
}

void    init_keys(t_cstr **act)
{
  char  *term;
  char  bp[1024];
  char  t[4096];
  char  *area;

  if ((term = getenv("TERM")) == NULL)
    aff_error("getenv");
  if (tgetent(bp, term) != 1)
    aff_error("tgetent");
  area = t;
  if (!(*act = malloc(sizeof(**act))))
    aff_error("Couldn't malloc\n");
  (*act)->clstr = cores("cl", &area);
  (*act)->cmstr = cores("cm", &area);
  (*act)->krstr = cores("kr", &area);
  (*act)->kustr = cores("ku", &area);
  (*act)->klstr = cores("kl", &area);
  (*act)->kdstr = cores("kd", &area);
  (*act)->kbstr = cores("kb", &area);
}
