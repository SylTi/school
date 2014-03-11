/*
** check_pipe.c for check_pipe in /u/epitech_2012/jaspar_y/cu/public/52sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Sat May 31 18:20:27 2008 yoann jaspar
** Last update Sat May 31 18:31:49 2008 yoann jaspar
*/

#include "sh.h"

int	check_pipe(char *str)
{
  int	i;
  int	ref;

  i = 0;
  ref = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '|')
      ref++;
    i++;
  }
  if (ref > 0)
    ref = 42;
  return (ref);
}
