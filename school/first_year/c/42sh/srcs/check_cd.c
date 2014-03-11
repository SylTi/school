/*
** check_cd.c for check_cd in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:58:02 2008 yoann jaspar
** Last update Wed Apr 23 14:21:35 2008 yoann jaspar
*/

#include "sh.h"

int	check_cd(char *str)
{
  char	mycd[] = "cd";
  int	i;
  int	j;

  i = j = 0;
  while (str[i] != '\0' && mycd[i] != '\0' && str[i] != ' ')
    {
      if (mycd[i] == str[i])
	j++;
      i++;
    }
  return (j);
}
