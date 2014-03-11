/*
** move.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:27:12 2008 jean-philippe rey
** Last update Fri May 16 22:56:06 2008 yoann jaspar
*/

#include <term.h>
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>

#include "colle.h"

void	move_prompt(t_allpr *lpr, t_term *term)
{
  if (lpr->cur->type == PR)
    {
      lpr->cur = lpr->rpr;
      lpr->cur->x = lpr->cur->lim_x;
      xtputs(tgoto(term->cmstr, lpr->cur->x, 1), 1, my_outc);
    }
  else if (lpr->cur->type == RPR)
    {
      lpr->cur = lpr->pr;
      lpr->cur->x = lpr->cur->lim_x;
      xtputs(tgoto(term->cmstr, lpr->cur->x, 0), 1, my_outc);
    }
}

void	move_key(t_term *term, int nb_key, t_allpr *lpr)
{
  if ((nb_key == UP) || (nb_key == DOWN))
    move_prompt(lpr, term);
  else if ((nb_key == LEFT) && (lpr->cur->x > 0))
    {
      lpr->cur->x--;
      xtputs(term->lestr, 1, my_outc);
    }
  else if ((nb_key == RIGHT) && (lpr->cur->x < lpr->cur->lim_x))
    {
      lpr->cur->x++;
      xtputs(term->ndstr, 1, my_outc);
    }
  else
    my_putchar('\a');
}

void	move_curs(int x, t_allpr *lpr, t_term *term)
{
  lpr->cur->x = x;
  xtputs(tgoto(term->cmstr, lpr->cur->x, (lpr->cur->type - 1)), 1, my_outc);
}

void		aff_prompt(t_list *pr, t_list *rpr)
{
  view_list(pr);
  view_list(rpr);
}

int		main_move(t_allpr *lpr, t_term *term)
{
  int		flag;

  flag = 0;
  xtputs(term->clstr, 1, my_outc);
  aff_prompt(lpr->pr, lpr->rpr);
  xtputs(tgoto(term->cmstr, lpr->cur->x, 0), 1, my_outc);
  flag = mais_lol(flag, term, lpr);
  return (0);
}
