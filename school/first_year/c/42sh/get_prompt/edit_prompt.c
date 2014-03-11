/*
** main.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:26:40 2008 jean-philippe rey
** Last update Wed May 21 15:18:11 2008 yoann jaspar
*/

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "colle.h"

void	init_cano(struct termios *conf)
{
  if (ioctl(0, TIOCGETA, conf) == -1)
    my_putstr("cannot ioctl\n");
  conf->c_lflag &= ~(ICANON | ECHOE | ISIG | ECHO);
  conf->c_cc[VMIN] = 1;
  conf->c_cc[VTIME] = 0;
  if (ioctl(0, TIOCSETA, conf) == -1)
    my_putstr("cannot ioctl\n");
}

void	init_term(t_term *term)
{
  term->area = term->t;
  term->term = xgetenv("TERM");
  xtgetent(term->bp, term->term);
  term->clstr = xtgetstr("cl", &term->area);
  term->kustr = xtgetstr("ku", &term->area);
  term->kdstr = xtgetstr("kd", &term->area);
  term->klstr = xtgetstr("kl", &term->area);
  term->krstr = xtgetstr("kr", &term->area);
  term->lestr = xtgetstr("le", &term->area);
  term->ndstr = xtgetstr("nd", &term->area);
  term->cmstr = xtgetstr("cm", &term->area);
  term->sostr = xtgetstr("so", &term->area);
  term->sestr = xtgetstr("se", &term->area);
  term->dcstr = xtgetstr("dc", &term->area);
}

int			edit_prompt(void)
{
  t_allpr		lpr;
  t_term		*term;
  struct termios	conf;
  t_prompt		*prompt;

  term = xmalloc(sizeof(*term));
  prompt = xmalloc(sizeof(*prompt));
  init_term(term);
  init_cano(&conf);
  get_prompt(prompt);
  lpr.pr = init_list(lpr.pr, prompt->fd, PR);
  lpr.rpr = init_list(lpr.rpr, prompt->fd, RPR);
  put_prompt_to_list(lpr.pr, prompt->prompt);
  put_prompt_to_list(lpr.rpr, prompt->rprompt);
  lpr.cur = lpr.pr;
  main_move(&lpr, term);
  if (accept(term) == 0)
    cpy_to_tcsh(&lpr);
  xtputs(term->clstr, 1, my_outc);
  free_list(lpr.pr);
  free_list(lpr.rpr);
  free(prompt->prompt);
  free(prompt->rprompt);
  free(prompt);
  return (0);
}
