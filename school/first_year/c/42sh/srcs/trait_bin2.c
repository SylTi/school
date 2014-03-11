/*
** trait_bin2.c for trait_bin2 in /u/epitech_2012/jaspar_y/cu/public/62sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Jun  9 12:33:59 2008 yoann jaspar
** Last update Mon Jun  9 12:41:19 2008 yoann jaspar
*/

#include "sh.h"

void	recup_exec2(char *str, t_cmd *to_exec)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '/')
      if (check_next_slash(str, i) == 0)
	to_exec->tab[0] = cpy_tab(str, i);
    i++;
  }
}

void	replace_dot2(char *str, t_cmd *to_exec)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  recup_exec(str, to_exec);
  str = trait_str_for_cat(str);
  to_exec->path[0] = strcat(my_getenv2("PWD", environ), str);
}

void	replace_slash2(char *str, t_cmd *to_exec)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  temp = xmalloc(sizeof(char) * 100);
  to_exec->path[0] = str;
  recup_exec2(str, to_exec);
}

char	*trait_bin2(t_cmd *to_exec)
{
  if (to_exec->tab[0][0] == '.')
  {
    replace_dot2(to_exec->tab[0], to_exec);
    return (to_exec->path[0]);
  }
  else if (to_exec->tab[0][0] == '/')
  {
    replace_slash2(to_exec->tab[0], to_exec);
    return (to_exec->path[0]);
  }
  return (NULL);
}
