/*
** my_prompt.c for my_prompt in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 16:02:21 2008 yoann jaspar
** Last update Fri Jun 13 15:40:38 2008 nicolas bonsall
*/

#include "sh.h"

void	my_aff_line(int b)
{
  my_putchar('.');
  my_put_nbr(b);
  my_putchar('.');
  my_putchar('|');
}

void		my_prompt(char **environ, int new, char *prompt)
{
  static int	b = 0;

  if (new)
    {
      b++;
      my_putchar('\n');
      my_aff_line(b);
      /*
	if (my_getenv("USER", environ) != NULL)
	my_putstr_env(my_getenv("USER", environ));
	my_putchar('@');
	if (my_getenv("HOST", environ) != NULL)
	my_putstr_env(my_getenv("HOST", environ));
	my_putstr(" > ");
      */
      /*      my_putstr(ret_prompt(prompt));
    }
  else
    {
      my_aff_line(b);
      /*
	if (my_getenv("USER", environ) != NULL)
	 my_putstr_env(my_getenv("USER", environ));
	 my_putchar('@');
	 if (my_getenv("HOST", environ) != NULL)
	 my_putstr_env(my_getenv("HOST", environ));
	 my_putstr(" > ");
      */
      my_putstr(ret_prompt(prompt));
    }
}
