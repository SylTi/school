/*
** my_strlen2.c for my_strlen2 in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:42:25 2008 yoann jaspar
** Last update Wed Apr 23 15:36:13 2008 yoann jaspar
*/

#include "sh.h"

int     my_strlen2(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '=')
    i++;
  return (i);
}
