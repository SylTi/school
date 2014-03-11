/*
** func.c for func in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Apr 28 17:01:21 2008 yoann jaspar
** Last update Wed Jun  4 17:49:28 2008 sylvain tissier
*/

#include "../includes/sh.h"

int	args_len(char *str, int	ref)
{
  int	i;
  int	ref2;

  i = 0;
  ref2 = 0;
  ref = 1;
  if (ref == 1)
    while (str[i] != '|')
      {
	if (str[i] == ' ')
	  ref2++;
	i++;
      }
  else if (ref == 2)
    {
      while (str[i] != '|')
	i++;
      i++;
      while (str[i] != '\0')
	{
	  if (str[i] == ' ')
	    ref2++;
	  i++;
	}
    }
  return (ref2);
}
