/*
** trait_pipe.c for trait_pipe in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell3
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Mar 24 10:38:14 2008 yoann jaspar
** Last update Sun Jun  1 00:26:01 2008 yoann jaspar
*/

#include "sh.h"

char	**second_boucle(char *buf, char **args, int i, int j, int k)
{
  int	f;

  f = 0;
  while (buf[i++] != '|')
    ;
  i++;
  while (buf[i] != '\0')
  {
    if (buf[i] == '"')
    {
      if (f == 0)
	f = 1;
      else
	f = 0;
    }
    if (buf[i] == ' ' && f == 0)
    {
      args[j][k] = '\0';
      i++;
      k = 0;
      j++;
    }
    args[j][k++] = buf[i++];
  }
  args[++j] = NULL;
  return (args);
}

char	**first_boucle(char *buf, char **args, int i; int j, int k)
{
  int	f;

  f = 0;
  while (buf[i] != '|')
  {
    if (buf[i] == '"')
    {
      if (f == 0)
	f = 1;
      else
	f = 0;
    }
    if (buf[i] == ' ' && f == 0)
    {
      args[j][k] = '\0';
      i++;
      k = 0;
      j++;
    }
    if (buf[i] == '|')
    {
      args[j] = NULL;
      break;
    }
    args[j][k++] = buf[i++];
  }
  args[++j] = NULL;
  return (args);
}

char	**set_args(char **args, char *buf, int ref)
{
  int	i;
  int	j;
  int	k;

  k = 0;
  j = 0;
  i = 0;
  args = xmalloc(sizeof(char *) * (5));
  while (i < (5))
    args[i++] = xmalloc(sizeof(char) * 200);
  if (ref == 1)
    args = first_boucle(buf, args, i, j, k);
  else if (ref == 2)
    args = second_boucle(buf, args, i, j, k);
  return (args);
}
