/*
** my_strcat.c for strcat in /u/epitech_2012/jaspar_y/public/42sh
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Thu May 29 15:50:50 2008 sylvain tissier
** Last update Mon Jun  9 15:06:50 2008 yoann jaspar
*/

#include "sh.h"

char	*my_strcat(char *cont, char *ajout)
{
  int	i;
  int	y;
  char	*ret;

  ret = xmalloc((sizeof(ret)) + (sizeof(ajout) + 1));
  i = 0;
  y = 0;
  while (cont[i] != '\0')
    {
      ret[y] = cont[i];
      y++;
      i++;
    }
  i = 0;
  while (ajout[i] != '\0')
    {
      ret[y] = ajout[i];
      y++;
      i++;
    }
  ret[y] = '\0';
  return (ret);
}
