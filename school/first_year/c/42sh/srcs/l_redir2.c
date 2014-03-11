/*
** l_redir.c for l_redir in /u/epitech_2012/jaspar_y/cu/public/52sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Fri May 30 16:11:34 2008 yoann jaspar
** Last update Thu Jun 12 23:28:02 2008 yoann jaspar
*/

#include "sh.h"

void	gere_pipe2(t_sh *sh, t_cmd *cmd, int id[2], char *file)
{
  int	i;

  i = 0;
  pipe(id);
  while (sh->hard_path[i] != '=' && sh->hard_path[i] != '\0')
    i++;
  cmd->path = set_path(cmd->path, sh->hard_path + i + 1);
  cmd->path = set_exec_path(cmd->path, cmd->tabl);
  my_putstr("\033[1;34m");
  if (fork() == 0)
  {
    close(id[1]);
    dup2(id[0], STDIN_FILENO);
    close(id[0]);
    i = 0;
    while (cmd->path[i])
      execve(cmd->path[i++], cmd->tabl, environ);
    exit(EXIT_FAILLURE);
  }
  exec_pipe2(sh, cmd, id, file);
}

void	exec_cmd_line3(t_sh *sh, t_cmd *cmd, char *file)
{
  int	i;

  i = 0;
  if (cmd)
    {
      if (cmd->type == T_CMD_N)
	{
	  while (sh->hard_path[i] != '=' && sh->hard_path[i] != '\0')
	    i++;
	  cmd->path = my_wordtab_sep(&(sh->hard_path[i + 1]), ':');
	  my_exec2(sh, cmd, file);
	}
    }
  if (cmd)
    cmd = cmd->next;
}

void	exec_cmd_line2(t_sh *sh, t_cmd *cmd, char *file)
{
  my_putstr("\033[1;34m");
  while (cmd)
  {
    if (cmd)
    {
      if (cmd->type == T_PIPE)
      {
	printf("Ambigous input redirect.\n");
	my_read(sh);
      }
    }
    exec_cmd_line3(sh, cmd, file);
  }
}

char	*trait_temp_for_l(char *temp)
{
  int	i;

  i = 0;
  while (temp[i] != '<')
    i++;
  temp[i] = '\0';
  temp = trait_str(temp);
  return (temp);
}

void	exec_l_redir(char *file, t_sh *sh, t_cmd *cmd)
{
  sh->temp = trait_temp_for_l(sh->temp);
  make_my_list_cmd(sh, &cmd);
  cmd_rev_list(&cmd);
  cmd_finish_tab(cmd);
  make_my_list_with_alias(sh, cmd);
  exec_cmd_line2(sh, cmd, file);
}

void	l_redir(t_sh *sh, t_cmd *cmd)
{
  char	*fichier;
  int	i;
  int	j;
  int	fd;

  i = 0;
  fichier = xmalloc(sizeof(char) * 150);
  while (sh->temp[i] != '<' && sh->temp[i] != NULL)
    i++;
  i++;
  j = 0;
  while (sh->temp[i] != '\0')
    fichier[j++] = sh->temp[i++];
  fichier = trait_str(fichier);
  fd = xopen(fichier, O_RDONLY);
  if (!fd)
    my_read(sh);
  else if (fd)
  {
    close(fd);
    exec_l_redir(fichier, sh, cmd);
  }
}
