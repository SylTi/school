/*
** get_conf.c for get fichier de conf in /u/epitech_2012/jaspar_y/public/62sh/builtins
**
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
**
** Started on  Wed Jun  4 17:22:27 2008 sylvain tissier
** Last update Fri Jun 13 13:47:26 2008 yoann jaspar
*/

#include "sh.h"

t_bultin	*get_conf()
{
  t_bultin	*bult;
  char		**tabl;
  char		*line;
  int		i;
  int		y;
  int		fd;

  i = 0;
  y = 0;
  tabl = 0;
  fd = xopen(AL, O_RDONLY);
  bult = malloc(sizeof(*bult));
  bult->alias = xmalloc(sizeof(*bult->alias) * MAX_ALIAS + 1);
  while ((line = get_next_line(fd)) != NULL)
    {
      if (strncmp("alias", line, 5) == 0)
	bult->alias[i++] = strdup(line);
      else if (strncmp("set prompt=", line, 11) == 0)
	{
	  tabl = my_wordtab_sep(line, '"');
	  bult->prompt = strdup(tabl[1]);
	}
      else
	continue;
    }
  bult->alias[i + 1] = NULL;
  free(tabl);
  free(line);
  xclose(fd);
  return (bult);
}
