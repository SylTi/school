/*
** pipe_gest.c for pipe_gest in /u/epitech_2012/jaspar_y/public/42sh/srcs
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Tue May 27 12:49:11 2008 maxime dumez
** Last update Thu Jun 12 16:29:58 2008 maxime dumez
*/

#include "sh.h"

void	gere_redir(t_sh *sh)
{
  t_cmd	*cmd;
  int	ref;

  cmd = NULL;
  ref = check_redir(sh->temp);
  if (ref == 1)
    r_redir(sh, 1, cmd);
  else if (ref == 2)
    r_redir(sh, 2, cmd);
  else if (ref == 3)
    l_redir(sh, cmd);
  else if (ref > 3)
  {
    my_putstr("Wrong use of '>'\n");
    my_read(sh);
  }
  else if (ref == 0)
  {
    my_putstr("\033[1;34m");
    make_my_list_cmd(sh, &cmd);
    cmd_rev_list(&cmd);
    cmd_finish_tab(cmd);
    exec_cmd_line(sh, cmd);
    cmd_free_list(cmd, 1);
  }
}

void	exec_cmd_line1(t_sh *sh, t_cmd *cmd)
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
	  my_exec(cmd);
	}
    }
  if (cmd)
    cmd = cmd->next;
  my_putstr("\e[0m");
}

void	exec_cmd_line(t_sh *sh, t_cmd *cmd)
{
  int	id[2];
  int	i;
  int	pid;

  i = 0;
  my_putstr("\033[1;34m");
  while (cmd)
  {
    if (cmd)
    {
      if (cmd->type == T_PIPE)
      {
	pid = fork();
	if (pid == 0)
	  {
	    gere_pipe(sh, cmd, id);
	    exit(0);
	  }
	else if (pid > 0)
	  wait(NULL);
	else if (pid < 0)
	  my_putstr("error in fork()");
	passe_pipe(&cmd);
      }
    }
    exec_cmd_line1(sh, cmd);
  }
}

void	gere_pipe1(t_sh *sh, t_cmd *cmd, int id[2])
{
  int	i;
  int	pid;

  i = 0;
  pipe(id);
  if (cmd->type == T_PIPE && cmd->next == NULL)
    my_strerror("Broken pipe\n");
  while (sh->hard_path[i] != '=' && sh->hard_path[i] != '\0')
    i++;
  cmd->path = set_path(cmd->path, sh->hard_path + i + 1);
  cmd->path = set_exec_path(cmd->path, cmd->tab);
  my_putstr("\033[1;34m");
  pid = fork();
  if (pid == 0)
    {
      if (my_recode2(cmd->tab[0], sh) != 1)
        {
          close(id[1]);
          dup2(id[0], STDOUT_FILENO);
          close(id[0]);
          i = 0;
          while (cmd->path[i])
            execve(cmd->path[i++], cmd->tab, environ);
        }
      exit(EXIT_FAILLURE);
    }
  else if (pid < 0)
    my_putstr("error in fork()");
}

void	gere_pipe3(t_sh *sh, t_cmd *cmd, int id[2])
{
  int	i;

  if (my_recode2(cmd->tab[0], sh) != 1)
    {
      close(id[0]);
      dup2(id[1], STDIN_FILENO);
      close(id[1]);
      i = 0;
      while (cmd->path[i])
	execve(cmd->path[i++], cmd->tab, environ);
    }
}

void	gere_pipe(t_sh *sh, t_cmd *cmd, int id[2])
{
  int	i;
  int pid;

  if (cmd->next->type == T_PIPE)
    {
      close(id[0]);
      dup2(id[1], STDIN_FILENO);
      close(id[1]);
      gere_pipe(sh, cmd->next, id);
    }
  else if (cmd->next->type == 0)
    {
      cmd = cmd->next;
      i = 0;
      while (sh->hard_path[i] != '=' && sh->hard_path[i] != '\0')
	i++;
      cmd->path = set_path(cmd->path, sh->hard_path + i + 1);
      cmd->path = set_exec_path(cmd->path, cmd->tab);
      gere_pipe3(sh, cmd, id);
      exit(EXIT_FAILLURE);
    }
  close(id[0]);
  close(id[1]);
  wait(NULL);
}

void	passe_pipe(t_cmd **cmd)
{
  while ((*cmd)->type == T_PIPE && *cmd)
    *cmd = (*cmd)->next;
  if (*cmd)
    *cmd = (*cmd)->next;
}

void		make_my_list_cmd(t_sh *sh, t_cmd **cmd)
{
  char		tmp[2];
  char		*poz;
  unsigned int	i;
  int		j;
  char		**tab;

  i = 0;
  poz = sh->temp;
  while (poz[i])
  {
    if ((j = is_a_sep(poz[i])) >= 0 || poz[i + 1] == '\0')
    {
      if (poz[i + 1] == '\0')
	j = T_CMD_N;
      else
      {
	tmp[0] = poz[i];
	poz[i] = '\0';
      }
      tab = my_wordtab_sep(poz, ' ');
      print_tab(tab);
      if (j)
	poz[i] = tmp[0];
      cmd_put_in_list(cmd, tab, j);
      if (poz[i])
      {
	poz = poz + i + 1;
	i = 0;
      }
      if (is_a_sep(*poz))
	poz++;
    }
    i++;
  }
}

int	is_a_sep(char c)
{
  int	j;

  j = 0;
  while (SEP_S[j])
  {
    if (c == SEP_S[j])
      return (j);
    j++;
  }
  return (-1);
}


void	aff_error(char *str)
{
  my_putstr("Error : ");
  my_putstr(str);
  my_putchar('\n');
  exit(EXIT_FAILLURE);
}

