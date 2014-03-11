/*
** print_tab.c for imprime tableau in /u/epitech_2012/jaspar_y/public/42sh
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Tue May 27 15:10:26 2008 sylvain tissier
** Last update Thu Jun 12 19:23:02 2008 sylvain tissier
*/

#include "sh.h"

void	print_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i++;
    }
}

void	print_tab_to_file(char **str, FILE *fd)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      fprintf(fd, "%s\n", str[i]);
      i++;
    }
}


int	count_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      i++;
    }
  return (i);
}

char	**copy_tab(char **tabl, char **tab_cp)
{
  int	i;

  i = 0;
  while (tabl[i] != NULL)
    {
      tab_cp[i] = strdup(tabl[i]);
      free(tabl[i]); 
     i++;
    }
  i++;
  tab_cp[i] = NULL;
  free(tabl);
  return (tab_cp);
}
