/*
** check_exit.c for check_exit in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:46:06 2008 yoann jaspar
** Last update Sat May 31 22:52:15 2008 yoann jaspar
*/

#include "sh.h"

int	check_exit(char *str)
{
  int	i;
  char	exit[] = "exit";

  i = 0;
  while (str[i] != '\0')
    {
      if (exit[i] == str[i])
	i++;
      else
	return (0);
    }
  return (i);
}
