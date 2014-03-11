/*
** menu.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:27:02 2008 jean-philippe rey
** Last update Fri May 16 22:56:41 2008 yoann jaspar
*/

#include <stdlib.h>
#include "colle.h"

void		init_menu(t_menu *menu)
{
  menu[0].var = "Menu dir:\t\t";
  menu[0].smenu = xmalloc(sizeof(*menu[0].smenu) * 5);
  menu[0].smenu[0].var = "->pwd:FROM_HOME\t\t";
  menu[0].smenu[0].opt = "%~";
  menu[0].smenu[1].var = "->pwd:FULL_PATH\t\t";
  menu[0].smenu[1].opt = "%/";
  menu[0].smenu[2].var = "\t\t\t";
  menu[0].smenu[2].opt = "";
  menu[0].smenu[3].var = "\t\t\t";
  menu[0].smenu[3].opt = "";
  menu[1].var = "Menu time:\t\t";
  menu[1].smenu = xmalloc(sizeof(*menu[0].smenu) * 5);
  menu[1].smenu[0].var = "->HH:MM(AMPM)\t\t";
  menu[1].smenu[0].opt = "%t";
  menu[1].smenu[1].var = "->HH:MM(24)\t\t";
  menu[1].smenu[1].opt = "%T";
  menu[1].smenu[2].var = "->HH:MM_dd/mm/yy(24)\t\t";
  menu[1].smenu[2].opt = "%P";
  menu[1].smenu[3].var = "->HH:MM_dd/mm(24)\t\t";
  menu[1].smenu[3].opt = "%p";
  init_menu2(menu);
}

int		move_mkey(int nb_key, int xmenu)
{
  if (nb_key == LEFT)
    {
      if (xmenu == 0)
	return (2);
      return (--xmenu);
    }
  else if (nb_key == RIGHT)
    {
      if (xmenu == 2)
	return (0);
      return (++xmenu);
    }
  return (xmenu);
}

void		free_menu(t_menu *menu)
{
  free(menu[0].smenu);
  free(menu[1].smenu);
  free(menu[2].smenu);
  free(menu);
}

char		*main_menu(t_term *term)
{
  char		buf[3];
  t_menu	*menu;
  int		nb_read;
  int		xmenu;
  int		nb_key;
  char		*str;

  xmenu = 0;
  menu = xmalloc(sizeof(*menu) * 4);
  xtputs(xtgetstr("vi", &term->area), 1, my_outc);
  xtputs(term->clstr, 1, my_outc);
  init_menu(menu);
  while (1)
    {
      show_menu(menu, xmenu, 9, term);
      empty_buf(buf, 3);
      nb_read = xread(0, buf, 3);
      if (nb_read == 1 && (buf[0] == 27))
	break;
      else if ((nb_read == 3) && (nb_key = test_key(term, buf[2])))
	xmenu = move_mkey(nb_key, xmenu);
      else if ((nb_read == 1) && (buf[0] == 32))
	{
	  if ((str = main_smenu(term, xmenu, menu)))
	    {
	      xtputs(xtgetstr("ve", &term->area), 1, my_outc);
	      free_menu(menu);
	      return (str);
	    }
	}
    }
  xtputs(xtgetstr("ve", &term->area), 1, my_outc);
  free_menu(menu);
  return (0);
}
