/*
** gere_char.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:25:41 2008 jean-philippe rey
** Last update Fri May 16 21:25:41 2008 jean-philippe rey
*/

#include <stdlib.h>
#include <term.h>

#include "colle.h"

void	insert_char(t_allpr *lpr, char c, t_term *term, int flag)
{
  ins_elm(lpr->cur, c);
  if ((flag == 1) && (lpr->cur->list))
    delete_all(lpr->cur);
  if (flag == 0)
    {
      lpr->cur->x++;
      lpr->cur->lim_x++;
    }
  xtputs(term->clstr, 1, my_outc);
  aff_prompt(lpr->pr, lpr->rpr);
  xtputs(tgoto(term->cmstr, lpr->cur->x, (lpr->cur->type - 1)), 1, my_outc);
}

void	del_char(t_allpr *lpr, t_term *term)
{
  if (lpr->cur->x > 0)
    {
      del_elm(lpr->cur);
      lpr->cur->x--;
      if (lpr->cur->lim_x > 0)
	lpr->cur->lim_x--;
      xtputs(term->lestr, 1, my_outc);
      xtputs(term->dcstr, 1, my_outc);
    }
  else
    my_putchar('\a');
}

void	del_elm(t_list *list)
{
  int	pos;

  pos = list->x;
  list->list = list->first;
  while ((list->list) && (pos > 1))
    {
      pos--;
      list->list = list->list->next;
    }
  if (list->list)
    delete_all(list);
}

void	ins_elm(t_list *list, char c)
{
  int	pos;

  pos = list->x;
  list->list = list->first;
  while ((list->list) && (pos > 0))
    {
      pos--;
      list->list = list->list->next;
    }
  my_add_in_list(list, c);
}

void	add_str_to_list(char *str, t_allpr *lpr, t_term *term, int flag)
{
  int	i;

  i = 0;
  while ((str) && (str[i]))
    {
      ins_elm(lpr->cur, str[i]);
      if ((flag == 1) && (lpr->cur->list))
	delete_all(lpr->cur);
      if (flag == 0)
	{
	  lpr->cur->x++;
	  lpr->cur->lim_x++;
	}
      i++;
    }
  xtputs(term->clstr, 1, my_outc);
  aff_prompt(lpr->pr, lpr->rpr);
  xtputs(tgoto(term->cmstr, lpr->cur->x, (lpr->cur->type - 1)), 1, my_outc);
}
