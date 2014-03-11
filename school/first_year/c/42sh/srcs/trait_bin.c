/*
** trait_bin.c for trait_bin in /u/epitech_2012/jaspar_y/cu/public/62sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Tue Jun  3 18:20:35 2008 yoann jaspar
** Last update Mon Jun  9 19:26:19 2008 nicolas bonsall
*/

#include "sh.h"

char	*cpy_tab(char *str, int i)
{
  char	*temp;
  int	j;

  j = 0;
  temp = xmalloc(sizeof(char) * 100);
  while (str[i] != '\0')
    temp[j++] = str[i++];
  return (temp);
}

int	check_next_slash(char *str, int ref)
{
  while (str[ref] != '\0')
  {
    ref++;
    if (str[ref] == '/')
      return (1);
  }
  return (0);
}

void	recup_exec(char *str, t_cmd *cmd)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '/')
      if (check_next_slash(str, i) == 0)
	cmd->tabl[0] = cpy_tab(str, i);
    i++;
  }
}

char	*trait_str_for_cat(char *str)
{
  int	i;
  int	j;
  char	*temp;

  i = 0;
  j = 0;
  temp = xmalloc(sizeof(char) * 100);
  temp = strcpy(temp, str);
  str[i] = '/';
  i++;
  while (temp[j] != '\0')
    str[i++] = temp[j++];
  return (str);
}

void	replace_dot(char *str, t_cmd *cmd)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  recup_exec(str, cmd);
  str = trait_str_for_cat(str);
  cmd->path[0] = strcat(my_getenv2("PWD", environ), str);
}

void	replace_slash(char *str, t_cmd *cmd)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  temp = xmalloc(sizeof(char) * 100);
  cmd->path[0] = str;
  recup_exec(str, cmd);
}

char	*trait_bin(t_cmd *cmd)
{
  if (cmd->tabl[0][0] == '.')
  {
    replace_dot(cmd->tabl[0], cmd);
    return (cmd->path[0]);
  }
  else if (cmd->tabl[0][0] == '/')
  {
    replace_slash(cmd->tabl[0], cmd);
    return (cmd->path[0]);
  }
  return (NULL);
}
