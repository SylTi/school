/*
** check_exec.c for check_exec in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Wed Apr 23 13:17:31 2008 yoann jaspar
** Last update Thu Jun 12 18:18:47 2008 yoann jaspar
*/

#include "sh.h"

int	check_exec(t_sh *sh)
{
  int	ref;

  sh->pipe = 0;
  gere_redir(sh);
  return (0);
}
