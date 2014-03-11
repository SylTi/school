/*
** xread.c for xread in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:44:26 2008 yoann jaspar
** Last update Thu Jun 12 16:25:27 2008 maxime dumez
*/

#include "sh.h"

int	xread(int d, void *buf, int nbytes)
{
  int	ret;

  ret = read(d, buf, nbytes);
  if (ret == -1)
    {
      my_putstr("\nReading error\n");
      exit(-1);
    }
  return (ret);
}
