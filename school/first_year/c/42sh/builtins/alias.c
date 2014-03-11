/*
** alias.c for alias in /u/epitech_2012/jaspar_y/public/42sh
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Mon May 26 19:44:11 2008 sylvain tissier
** Last update Sun Jun  8 17:39:54 2008 sylvain tissier
*/

#include "../includes/sh.h"

void	print_alias(char **alias)
{
  print_tab(alias);
  return ;
}

int	check_alias(char *cmd, char **alias)
{
  char	*sauv;
  int	i;

  i = 0;
  if ((strncmp(cmd, "alias", 5)) == 0)
    print_tab(alias);
  else
    while (alias[i] != NULL)
      {

	sauv = my_strcat("alias ", cmd);
	if ((strncmp(sauv, alias[i], strlen(sauv))) == 0)
	  return (i);
	i++;
      }
  return (-1);
}

char	*remplace_alias(char *cmd, char **alias)
{
  char	**wordtab;
  int	a;

  if ((a = check_alias(cmd, alias)) != -1)
    {
      wordtab = my_wordtab_sep(alias[a], '"');
      return (wordtab[1]);
    }
  else
    return (cmd);
}

