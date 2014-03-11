/*
** xwrite.c for xwrite.c in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:44:07 2008 yoann jaspar
** Last update Sat May 31 22:53:00 2008 yoann jaspar
*/

#include "sh.h"

int	xwrite(int d, const void *buf, size_t nbytes)
{
  int	value;

  value = write(d, buf, nbytes);
  if (value == -1)
    {
      my_putstr("Writting error\n");
      exit (-1);
    }
  return (value);
}
