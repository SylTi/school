/*
** my_aff_line.c for my_aff_line in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 16:02:07 2008 yoann jaspar
** Last update Wed Apr 16 18:07:09 2008 yoann jaspar
*/

#include "sh.h"

void	my_aff_line(int b)
{
  my_putchar('.');
  my_put_nbr(b);
  my_putchar('.');
  my_putchar('|');
}
