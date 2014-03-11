/*
** init_menu2.c for init_menu2 in /u/epitech_2012/jaspar_y/cu/public/collissimo
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Fri May 16 22:03:47 2008 yoann jaspar
** Last update Fri May 16 22:05:27 2008 yoann jaspar
*/

#include "colle.h"

void	init_menu2(t_menu *menu)
{
  menu[2].var = "Menu name:\n";
  menu[2].smenu = xmalloc(sizeof(*menu[0].smenu) * 5);
  menu[2].smenu[0].var = "->var:HOST\n";
  menu[2].smenu[0].opt = "%M";
  menu[2].smenu[1].var = "->var:USER\n";
  menu[2].smenu[1].opt = "%n";
  menu[2].smenu[2].var = "\n";
  menu[2].smenu[2].opt = "";
  menu[2].smenu[3].var = "\n";
  menu[2].smenu[3].opt = "";
  menu[3].var = 0;
}
