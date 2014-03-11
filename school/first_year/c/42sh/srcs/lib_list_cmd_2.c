/*
** lib_list_cmd_2.c for lib_list_cmd in /u/epitech_2012/jaspar_y/public/62sh
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Sun Jun  1 00:31:58 2008 maxime dumez
** Last update Mon Jun  9 18:47:49 2008 nicolas bonsall
*/

#include "sh.h"

void	cmd_aff_list(t_cmd *cmd)
{
  while (cmd)
  {
    aff_tab(cmd->tabl);
    cmd = cmd->next;
  }
}

void	cmd_rev_list(t_cmd **cmd)
{
  t_cmd	*tmp;

  tmp = NULL;
  while (*cmd)
    {
      cmd_put_in_list(&tmp, (*cmd)->tabl, (*cmd)->type);
      *cmd = (*cmd)->next;
    }
  cmd_free_list(*cmd, 0);
  *cmd = tmp;
}
