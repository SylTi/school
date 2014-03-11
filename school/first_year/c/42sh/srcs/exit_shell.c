/*
** exit_shell.c for exit_shell in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:47:57 2008 yoann jaspar
** Last update Fri Jun 13 13:40:47 2008 yoann jaspar
*/

#include "sh.h"

void	exit_shell(t_sh *sh)
{
  my_putstr("\e[1;32m");
  my_putstr("### \e[1;33mFermeture du Minishell Version 1.2 \e[1;31m###\n");
  my_putstr("\e[0m");
  free(sh->cmd);
  free(sh->temp);
  free(sh);
  exit(0);
}
