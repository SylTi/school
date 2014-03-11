/*
** trait_ref.c for trait_ref in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell2
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Mar  6 11:19:49 2008 yoann jaspar
** Last update Sun Jun  1 00:45:57 2008 maxime dumez
*/

#include "sh.h"

char	*decoup_relou(char *ref, int i, int j, int i_save, char *lol)
{
  while (ref[i] != '\0')
  {
    if (ref[i] == ' ' || ref[i] == '\t')
    {
      i_save = i;
      while (ref[i] == ' ' || ref[i] == '\t')
	i++;
      if (ref[i] != '\0')
      {
	if (i_save != 0)
	{
	  lol[j] = ' ';
	  j++;
	}
      }
    }
    lol[j] = ref[i];
    j++;
    lol[j] = '\0';
    i++;
  }
  ref = lol;
  return (ref);
}

char	*trait_str(char *ref)
{
  int	i;
  int	j;
  int	i_save;
  char	*lol;

  i = 0;
  j = 0;
  i_save = 0;
  lol = xmalloc(sizeof(*lol) * 150);
  ref = decoup_relou(ref, i, j, i_save, lol);
  return (ref);
}
