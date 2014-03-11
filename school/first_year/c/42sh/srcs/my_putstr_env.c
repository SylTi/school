/*
** my_putstr_env.c for my_putstr_env in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:44:53 2008 yoann jaspar
** Last update Wed Apr 16 18:00:51 2008 yoann jaspar
*/

#include "sh.h"

void    my_putstr_env(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '=')
    i++;
  i++;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
