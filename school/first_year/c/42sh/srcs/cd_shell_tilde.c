/*
** cd_shell_tilde.c for cd_shell_tilde in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:50:47 2008 yoann jaspar
** Last update Sun Jun  1 00:55:41 2008 nicolas bonsall
*/

#include "sh.h"

void	cd_shell_tilde(char *ref, char *str, int flag, t_sh *sh)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  sh->str2 = xmalloc(sizeof(char) * 100);
  while (str[i] != '\0')
    {
      sh->str2[i] = str[i];
      i++;
    }
  sh->str2[i++] = '/';
  j = 2;
  while (ref[j] != '\0')
    sh->str2[i++] = ref[j++];
  sh->str2[i] = '\0';
  cd_shell(sh->str2, flag, sh);
}
