/*
** my_getenv2.c for my_getenv2 in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell2
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Mar  6 16:22:08 2008 yoann jaspar
** Last update Sat May 31 22:52:25 2008 yoann jaspar
*/

#include "sh.h"

char	*my_getenv2(char *str, char **env)
{
  t_ge	ge;
  int	i;
  int	j;

  i = 0;
  j = 0;
  ge.tmp1 = xmalloc(sizeof(char) * 50);
  ge.tmp2 = xmalloc(sizeof(char) * 50);
  ge.tmp1 = my_getenv(str, env);
  while (ge.tmp1[i] != '=')
    i++;
  i++;
  while (ge.tmp1[i] != '\0')
    {
      ge.tmp2[j] = ge.tmp1[i];
      j++;
      i++;
    }
  ge.tmp2[j] = '\0';
  return (ge.tmp2);
}
