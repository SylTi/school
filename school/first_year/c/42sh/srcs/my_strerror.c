/*
** my_strerror.c for affiche un message sur la sortie d'erreur in /u/epitech_2012/tissie_s/cu/rendu/c/minishell1
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Tue Feb 26 20:54:02 2008 sylvain tissier
** Last update Sun Jun  1 00:57:15 2008 yoann jaspar
*/

#include "../includes/sh.h"

void	my_putchar_err(char c)
{
  write(2, &c, 1);
  return ;
}

void	my_strerror(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar_err(str[i++]);
  return ;
}
