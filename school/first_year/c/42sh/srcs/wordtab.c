/*
** wordtab.c for wordtab in /u/epitech_2012/dumez_m/cu/rendu/c/minishell1/wordtab
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Wed Feb 27 19:06:02 2008 maxime dumez
** Last update Mon Jun  9 17:07:45 2008 maxime dumez
*/

#include "../includes/sh.h"

typedef struct	s_count
{
  int		j;
  int		i;
  int		k;
  int		l;
}		t_count;

int	count_part(char *str, char sep)
{
  int	count;

  count = 0;
  while (*str != '\0')
    {
      while (*str != sep && *str != '\0')
	str++;
      if (*str == sep || *str == '\0')
	count++;
      while (*str == sep && *str != '\0')
	str++;
    }
  return (count);
}

char	**mk_tab(int size)
{
  char	**tabl;

  if ((tabl = xmalloc(sizeof(*tabl) * size)) == 0)
    return (0);
  return (tabl);
}

char	*mk_line(int size)
{
  char	*line;

  if ((line = xmalloc(sizeof(*line) * size)) == 0)
    return (0);
  return (line);
}

char	**my_wordtab_sep(char *str, char sep)
{
  char	**wordtab;
  int	nb_part;
  t_count	c;

  nb_part = count_part(str, sep);
  wordtab = mk_tab(nb_part + 1);
  c.i = 0;
  c.j = 0;
  c.k = 0;
  while (str[c.j] != '\0')
    {
      while (str[c.j] == sep && str[c.j] != '\0')
	c.j++;
      c.i = c.j;
      while (str[c.i] != '\0' && str[c.i] != sep)
	c.i++;
      wordtab[c.k] = mk_line(c.i - c.j + 1);
      c.l = 0;
      while (c.j < c.i)
	wordtab[c.k][c.l++] = str[c.j++];
      wordtab[c.k][c.l] = '\0';
      c.k++;
    }
  wordtab[c.k] = NULL;
  return (wordtab);
}
