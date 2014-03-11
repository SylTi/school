/*
** get_conf.c for get fichier de conf in /u/epitech_2012/jaspar_y/public/62sh/builtins
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Wed Jun  4 17:22:27 2008 sylvain tissier
** Last update Sun Jun  8 17:41:34 2008 sylvain tissier
*/

#include "../includes/sh.h"

t_bultin	*get_conf()
{
  t_bultin	*bult;
  char		**tab;
  char		*line;
  int		i;
  int		y;
  int		fd;

  i = 0;
  y = 0;
  fd = xopen(AL, O_RDONLY);
  bult->alias = xmalloc(sizeof(bult->alias) * MAX_ALIAS + 1); 
  while ((line = get_next_line(fd)) != NULL)
    {
      if (strncmp("alias", line, 5) == 0)
	bult->alias[i++] = strdup(line);
      else if (strncmp("set prompt=", line, 11) == 0)
	{
	  tab = my_wordtab_sep(line, '"');
	  bult->prompt = strdup(tab[1]);
	}
      else
	continue;
    }
  bult->alias[i + 1] = NULL;
  free(tab);
  free(line);  
  xclose(fd);
  return (bult);
}

int	main(int ac, char **av)
{
  t_bultin	*bult;
  char		*str;
  char		*alias_rp;

  my_putstr(av[1]);
  bult = get_conf();
  print_tab(bult->alias);
  my_putstr(bult->prompt);
  str = ret_prompt(bult->prompt);
  my_putstr(str);
  printf("av[1] = %s\n", av[1]);
  alias_rp = remplace_alias(av[1], bult->alias);
  my_putstr(av[1]);
  my_putstr("=");
  my_putstr(alias_rp);
  my_putchar('\n');
  return (0);
}
