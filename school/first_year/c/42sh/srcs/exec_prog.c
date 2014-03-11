/*
** exec_prog.c for Exec prog minishell1 in /u/epitech_2012/tissie_s/cu/rendu/c/minishell1
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Wed Feb  6 15:56:55 2008 sylvain tissier
** Last update Sun Jun  1 06:32:28 2008 yoann jaspar
*/

#include "sh.h"

int	check_point(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '.')
      return (1);
    i++;
  }
  return (0);
}

char	*fuck_point2(char *str)
{
  char	*sauv;
  int	i;
  int	y;

  i = 0;
  y = 0;
  sauv = xmalloc(sizeof(*str) + 1);
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	i++;
      else
	{
	  sauv[y] = str[i];
	  y++;
	  i++;
	}
    }
  free(str);
  return (sauv);
}

char	*fuck_point(char *str)
{
  char	*sauv;
  int	i;
  int	y;

  i = 0;
  y = 0;
  sauv = xmalloc(sizeof(*str) + 1);
  while (str[i] != '\0')
    {
      if (str[i] == '.')
	i++;
      else
	{
	  sauv[y] = str[i];
	  y++;
	  i++;
	}
    }
  free(str);
  return (sauv);
}

char		*exec_prog2(char **av)
{
  char		*path;
  char		*sauv;

  path = xmalloc(sizeof(av[0]) + sizeof(path) * 42 + 15);
  if (av[0][0] == '/')
    {
      path = av[0];
    }
  if ((av[0][0] == '.') && (av[0][1] == '/'))
    {
      path = strdup(getenv("PWD"));
      sauv = fuck_point(av[0]);
      path = my_strcat(path, sauv);
      return (path);
    }
  return(NULL);
}
