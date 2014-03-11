/*
** mais_lol.c for mais_lol in /u/epitech_2012/jaspar_y/cu/public/collissimo
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Fri May 16 22:44:58 2008 yoann jaspar
** Last update Fri May 16 22:50:17 2008 yoann jaspar
*/

#include "colle.h"

int	mais_lol(int flag, t_term *term, t_allpr *lpr)
{
  char	buf[3];
  int	nb_key;
  int	nb_read;

  while (1)
    {
      empty_buf(buf, 3);
      nb_read = xread(0, buf, 3);
      if (nb_read == 1 && (buf[0] == 27))
	return (0);
      else if ((nb_read == 3) && (nb_key = test_key(term, buf[2])))
	move_key(term, nb_key, lpr);
      else if ((nb_read == 1) && (buf[0] == 24))
	add_str_to_list(main_menu(term), lpr, term, flag);
      else if ((nb_read == 1) && (buf[0] == 8))
	del_char(lpr, term);
      else if ((nb_read == 3) && (buf[2] == HOME))
	move_curs(0, lpr, term);
      else if ((nb_read == 3) && (buf[2] == END))
	move_curs(lpr->cur->lim_x, lpr, term);
      else if ((nb_read == 1) && (buf[0] == '~'))
	flag = INSERT(flag);
      else if ((nb_read == 1))
	insert_char(lpr, buf[0], term, flag);
    }
  return (flag);
}
