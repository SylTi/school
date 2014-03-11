/*
** check_r_redir.c for check_r_redir in /u/epitech_2012/jaspar_y/cu/public/52sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu May 29 14:48:39 2008 yoann jaspar
** Last update Thu Jun 12 19:05:46 2008 yoann jaspar
*/

#include "sh.h"

char	*trait_temp(char *temp)
{
  return (temp);
}

void	check_good_redir(char *temp, t_sh *sh)
{
  int	i;
  int	ref1;
  int	ref2;

  i = 0;
  ref1 = 0;
  ref2 = 0;
  while (temp[i] != '\0')
  {
    if (temp[i] == '<')
      ref2++;
    if (temp[i] == '>')
      ref1++;
    i++;
  }
  if (ref1 > 2)
  {
    printf ("Bad using for redirect\n");
    my_read(sh);
  }
  if (ref2 > 1)
  {
    printf ("Bad using for redirect\n");
    my_read(sh);
  }
  if (ref1 > 0 && ref2 > 0)
  {
    printf ("Bad using for redirect\n");
    my_read(sh);
  }
  return;
}

void	exec_r_redir(char *file, t_sh *sh, t_cmd *cmd)
{
  int	ex;
  int	i;

  i = 0;
  check_fichier(file, sh);
  to_flech_r(sh->temp, &i);
  sh->temp[i] = '\0';
  sh->temp = trait_str(sh->temp);
  sh->flag = 2;
  file = trait_str(file);
  sh->fichier = strdup(file);
  if ((ex = my_recode(sh)) == 1)
    ;
  else
  {
    make_my_list_cmd(sh, &cmd);
    cmd_rev_list(&cmd);
    cmd_finish_tab(cmd);
    make_my_list_with_alias(sh, cmd);
    cmd->flag = 1;
    cmd->file_out = strdup(file);
    exec_cmd_line(sh, cmd);
  }
}

void	to_flech_r(char *s, int *i)
{
  while (s[*i] != '>' && s[*i])
    *i = *i + 1;
}

char	*reduce_temp(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '>')
    i++;
  str[i] = '\0';
  str = trait_str(str);
  return (str);
}

void	r_redir(t_sh *sh, int ref, t_cmd *cmd)
{
  char	*str;
  char	*fichier;
  int	i;
  int	j;

  i = 0;
  str = xmalloc(sizeof(char) * 5);
  fichier = xmalloc(sizeof(char) * 200);
  if (ref == 1)
  {
    sh->pipe = 2;
    to_flech_r(sh->temp, &i);
    i++;
  }
  else if (ref == 2)
  {
    sh->pipe = 1;
    to_flech_r(sh->temp, &i);
    i += 2;
  }
  j = 0;
  while (sh->temp[i] != '\0')
    fichier[j++] = sh->temp[i++];
  fichier = trait_str(fichier);
  sh->temp = reduce_temp(sh->temp);
  exec_r_redir(fichier, sh, cmd);
}

int	check_redir(char *ex, t_sh *sh)
{
  int	i;
  int	ref;

  i = 0;
  ref = 0;
  check_good_redir(ex, sh);
  while (ex[i] != '\0')
  {
    if (ex[i] == '>')
      ref++;
    if (ex[i] == '<')
      return (3);
    i++;
  }
  return (ref);
}
