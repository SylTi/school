/*
** show_menu.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:27:34 2008 jean-philippe rey
** Last update Wed May 21 15:13:08 2008 yoann jaspar
*/

#include <term.h>
#include "colle.h"

void		how_use(void)
{
  my_putstr("+\t\t\t\t\t\t+\n");
  my_putstr("Bienvenu(e) dans le menu :\n");
  my_putstr("Pour vous deplacer dans le menu utilisez -> et <-\n");
  my_putstr("Pour selection utilisez la touche : espace\n");
  my_putstr("+\t\t\t\t\t\t+\n\n");
}

void	enjoy(t_term *term, t_menu *menu, int xmenu, int xsmenu)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      if (i == xmenu && xsmenu == 9)
	xtputs(term->sostr, 1, my_outc);
      my_putstr(CSI);
      my_putstr(BBLACK);
      my_putstr("\033[1;34m");
      my_putstr(menu[i++].var);
      xtputs(term->sestr, 1, my_outc);
      my_putstr(STANDARD);
    }
}

void		show_menu(t_menu *menu, int xmenu, int xsmenu, t_term *term)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  xtputs(tgoto(term->cmstr, 0, 0), 1, my_outc);
  how_use();
  enjoy(term, menu, xmenu, xsmenu);
  while (j < 4)
    {
      i = 0;
      while (i < 3)
	{
	  if (j == xsmenu && i == xmenu)
	    xtputs(term->sostr, 1, my_outc);
	  my_putstr(CSI);
	  my_putstr(FGREEN);
	  my_putstr(BBLACK);
	  my_putstr(menu[i++].smenu[j].var);
	  xtputs(term->sestr, 1, my_outc);
	  my_putstr(STANDARD);
	}
      j++;
    }
}
