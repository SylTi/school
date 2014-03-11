/*
** xmalloc.c for xmalloc in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell2
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Mar  6 12:31:56 2008 yoann jaspar
** Last update Fri Jun 13 14:09:44 2008 nicolas bonsall
*/

#include "sh.h"

void	*xmalloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      my_putstr("Cannot allocat memory\n");
      exit(0);
    }
  return (ptr);
}
