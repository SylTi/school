/*
** unsetenv_shell.c for unsetenv_shell in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:57:23 2008 yoann jaspar
** Last update Sat May 31 21:30:57 2008 maxime dumez
*/

#include "sh.h"

void	unsetenv_shell2(char **environ, t_sh *sh, char *str)
{
  int	i;

  i = 0;
  sh->temp2 = xmalloc(sizeof(char *) * 3);
  while (i < 3)
    sh->temp2[i++] = xmalloc(sizeof(char) * 100);
  sh->temp2 = set_temp2(sh->temp2, str);
  i = 0;
  if (sh->temp2[1] == NULL)
    my_putstr("\e[1;32mSytaxe error\n\e[1;34m>> man unsetenv <<\e[0m\n\n");
  if (sh->temp2[1][0] == '*')
    {
      environ = my_rm_all_env(environ);
      my_putstr("\e[1;34mEnviron has been deleted\e[1;34m\n\e[1;32mEnjoy !\n\n\e[0m");
    }
  if (sh->temp2[1][0] != '\0')
    {
      if (environ[0] != NULL)
	while (sh->temp2[i] != NULL)
	  environ = my_check_rm_env(environ, sh->temp2[i++]);
      else
	my_putstr("\e[1;34mVariable(s) deja supprimmee(s)\n\e[1;32mEnjoy\e[0m\n\n");
    }
}

void	unsetenv_shell(char **environ, t_sh *sh)
{
  int	i;

  i = 0;
  sh->temp2 = xmalloc(sizeof(char *) * 3);
  while (i < 3)
    sh->temp2[i++] = xmalloc(sizeof(char) * 100);
  sh->temp2 = set_temp2(sh->temp2, sh->temp);
  i = 0;
  if (sh->temp2[1] == NULL)
    my_putstr("\e[1;32mSytaxe error\n\e[1;34m>> man unsetenv <<\e[0m\n\n");
  if (sh->temp2[1][0] == '*')
    {
      environ = my_rm_all_env(environ);
      my_putstr("\e[1;34mEnviron has been deleted\e[1;34m\n\e[1;32mEnjoy !\n\n\e[0m");
    }
  if (sh->temp2[1][0] != '\0')
    {
      if (environ[0] != NULL)
	while (sh->temp2[i] != NULL)
	  environ = my_check_rm_env(environ, sh->temp2[i++]);
      else
	my_putstr("\e[1;34mVariable(s) deja supprimmee(s)\n\e[1;32mEnjoy\e[0m\n\n");
    }
  if (sh->flag == 1)
    my_read(sh);
}
