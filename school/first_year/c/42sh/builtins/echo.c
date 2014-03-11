/*
** echo.c for echo* in /u/epitech_2012/jaspar_y/public/42sh
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 29 19:49:08 2008 sylvain tissier
** Last update Mon Jun  9 17:43:19 2008 sylvain tissier
*/

#include <stdlib.h>

char	*rm_doll(char *str)
{
  char	*sauv;
  int	i;
  int	y;

  i = 1;
  y = 0;
  while (str[i] != 0)
    {
      sauv[y] = str[i]; 
      y++;
      i++;
    }
  sauv[y] = '\0';
  return (sauv);
}

char	*check_doll(char *str)
{
  char	*sauv;
  char	*str2;
  

  if (str[0] == '$')
    {
      str2 = rm_doll(str);
      if ((sauv = my_getenv(str2)) != NULL)
	return (sauv);
      else
	return ("La variable n'existe pas");
    }
  else
    return (str);

}

void	builtin_echo(char **str)
{
  int   i;
  int   j;
  char	*sauv;
  
  i = 1;
  j = 0;
  if ((str[i]) && (!strcmp(str[i], "-n")))
    {
      i++;
      j = 1;
    }
  while (str[i])
    {
      sauv = check_doll(str[i]);
      my_putstr(sauv);
      if (str[i + 1])
        my_putstr(" ");
      i++;
    }
  if (!j)
    my_putstr("\n");
  return ;
}

int	main(int ac, char **av)
{
  char	**sauv;
  int	i;

  i = 1;
  sauv = malloc(sizeof(sauv) * 42);
  sauv[2] = malloc(sizeof(sauv[0]) * 42 + 1);
  sauv[0] = strdup(av[0]);
  sauv[1] = strdup(av[1]);
  sauv[2] = NULL;
  builtin_echo(sauv);
  return (0);
}
