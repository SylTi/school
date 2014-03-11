/*
** smenu.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:27:58 2008 jean-philippe rey
** Last update Fri May 16 21:33:49 2008 jean-philippe rey
*/

#include "colle.h"

int	move_mskey(int nb_key, int xsmenu, int xmenu)
{
  if (nb_key == UP || nb_key == LEFT)
    {
      if (xmenu == 1 && xsmenu == 0)
	return (3);
      else if (xmenu != 1 && xsmenu == 0)
	return (1);
      return (--xsmenu);
    }
  else if (nb_key == DOWN || nb_key == RIGHT)
    {
      if (xmenu == 1 && xsmenu == 3)
	return (0);
      else if (xmenu != 1 && xsmenu == 1)
	return (0);
      return (++xsmenu);
    }
  return (0);
}

char	*main_smenu(t_term *term, int xmenu, t_menu *menu)
{
  char	buf[3];
  int	nb_read;
  int	nb_key;
  int	xsmenu;

  xsmenu = 0;
  while (42152)
    {
      empty_buf(buf, 3);
      nb_read = xread(0, buf, 3);
      show_menu(menu, xmenu, xsmenu, term);
      if (nb_read == 1 && (buf[0] == 27))
	return (0);
      else if ((nb_read == 3) && (nb_key = test_key(term, buf[2])))
	xsmenu = move_mskey(nb_key, xsmenu, xmenu);
      else if ((nb_read == 1) && (buf[0] == 32))
	return (menu[xmenu].smenu[xsmenu].opt);
    }
  return (0);
}
