/*
** end.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:25:28 2008 jean-philippe rey
** Last update Wed May 21 15:14:06 2008 yoann jaspar
*/

#include <term.h>
#include "colle.h"

void		aff_end(t_term *term, int nb)
{
  xtputs(tgoto(term->cmstr, 0, 0), 1, my_outc);
  my_putstr(CSI);
  my_putstr("\033[1;34m");
  my_putstr("Voulez vous sauvegarder votre nouveau prompt ?\n\t");
  if (nb == 0)
    xtputs(term->sostr, 1, my_outc);
  my_putstr(FGREEN);
  my_putstr(BBLACK);
  my_putstr("Yes\t");
  xtputs(term->sestr, 1, my_outc);
  if (nb == 1)
    xtputs(term->sostr, 1, my_outc);
  my_putstr("Nop");
  xtputs(term->sestr, 1, my_outc);
  my_putstr(STANDARD);
}

int		accept(t_term *term)
{
  int		acp;
  char		buf[3];
  int		nb_read;
  int		nb_key;

  acp = 0;
  nb_read = 0;
  nb_key = 0;
  xtputs(xtgetstr("vi", &term->area), 1, my_outc);
  xtputs(term->clstr, 1, my_outc);
  while (1)
    {
      aff_end(term, acp);
      empty_buf(buf, 3);
      nb_read = xread(0, buf, 3);
      if ((nb_read == 1) && (buf[0] == 32))
	break;
      else if ((nb_read == 3) && (nb_key = test_key(term, buf[2])))
	acp = INSERT(acp);
    }
  xtputs(xtgetstr("ve", &term->area), 1, my_outc);
  return (acp);
}
