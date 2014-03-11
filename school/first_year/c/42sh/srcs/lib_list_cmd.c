/*
** lib_list_cmd.c for li_list_cmd in /u/epitech_2012/jaspar_y/public/42sh/srcs
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Tue May 27 12:55:15 2008 maxime dumez
** Last update Fri Jun 13 13:44:01 2008 yoann jaspar
*/

#include "sh.h"

void	cmd_put_in_list(t_cmd **cmd, char **data, int type)
{
  t_cmd	*snext;
  t_cmd	*tmp;

  tmp = *cmd;
  if (!(snext = xmalloc(sizeof(*snext))))
    aff_error("Couldn't malloc");
  snext->tabl = data;
  snext->type = type;
  snext->next = *cmd;
  *cmd = snext;
}

void	cmd_free_list(t_cmd *cmd, int freetab)
{
  t_cmd	*tmp;

  tmp = cmd;
  if (!tmp)
    return ;
  while (tmp->next)
    {
      cmd = tmp;
      tmp = tmp->next;
      if (freetab)
	free_tab(cmd->tabl);
      free(cmd);
    }
}

void	free_tab(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i])
    {
      free(tabl[i]);
      i++;
    }
  free(tabl);
}

void	aff_tab(char **tabl)
{
  int	i;

  i = 0;
  while (tabl[i])
    {
      my_putstr(tabl[i]);
      my_putchar('\n');
      i++;
    }
}

void	cmd_finish_tab(t_cmd *cmd)
{
  unsigned int	i;

  while (cmd)
  {
    i = 0;
    while (cmd->tabl[i])
    {
      if (strlen(cmd->tabl[i]) == 0)
	cmd->tabl[i] = NULL;
      i++;
    }
    cmd = cmd->next;
  }
}
