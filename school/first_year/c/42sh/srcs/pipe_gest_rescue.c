/*
** pipe_gest.c for pipe_gest in /u/epitech_2012/jaspar_y/public/42sh/srcs
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Tue May 27 12:49:11 2008 maxime dumez
** Last update Fri Jun 13 15:20:54 2008 nicolas bonsall
*/

#include "sh.h"

void		gere_redir(t_sh *sh)
{
  t_cmd		*cmd;
  int		ref;

  cmd = NULL;
  ref = check_redir(sh->temp, sh);
  if (ref == 1)
    r_redir(sh, 1, cmd);
  else if (ref == 2)
    r_redir(sh, 2, cmd);
  else if (ref == 3)
    l_redir(sh, cmd);
  else if (ref > 3)
    {
      printf("Wrong use of '>'\n");
      my_read(sh);
    }
  else if (ref == 0)
    {
      if ((ref = my_recode(sh)) == 1)
	return ;
      my_putstr("\033[1;34m");
      make_my_list_cmd(sh, &cmd);
      cmd_rev_list(&cmd);
      cmd_finish_tab(cmd);
      make_my_list_with_alias(sh, cmd);
      exec_cmd_line(sh, cmd);
      cmd_free_list(cmd, 1);
    }
  cmd = NULL;
  
}

void	make_my_list_with_alias(t_sh *sh, t_cmd *cmd)
{
  char	*tmp;

  while (cmd)
    {
      if (cmd->tabl[0])
	{
	  tmp = remplace_alias(cmd->tabl[0], sh->bult->alias);
	  cmd->tabl = tabcat(tmp, cmd->tabl);
	}
      cmd = cmd->next;
    }
}

char	**tabcat(char *begin, char **dst)
{
  char	**sauv;
  char	**tabl;
  int	i;
  int	y;

  tabl = my_wordtab_sep(begin, ' ');
  i = 0;
  y = 0;
  sauv = xmalloc(sizeof(sauv) * (count_tab(tabl) + count_tab(dst)) + 1);
  while (tabl[i] != NULL)
    {
      sauv[y] = strdup(tabl[i]);
      free(tabl[i]);
      y++;
      i++;
    }
  i = 1;
  while (dst[i] != NULL)
    {
      sauv[y] = strdup(dst[i]);
      free(dst[i]);
      y++;
      i++;
    }
  tabl[y] = NULL;
  free(tabl);
  free(dst);
  return (sauv);
}

void		exec_cmd_line(t_sh *sh, t_cmd *cmd)
{
  int		id[2];
  int		i;
  int		pid;

  i = 0;
  my_putstr("\033[1;34m");
  while (cmd)
    {
      if (cmd)
	{
	  cmd->pipe = sh->pipe;
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
		aff_error("error in fork()");
	      passe_pipe(&cmd);
	    }
	}
      if (cmd)
	{
	  cmd->pipe = sh->pipe;
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
    }
  return;
}

void            my_checkpipe(t_sh *sh, t_cmd *cmd)
{
  static int    i = 0;
  int           q;

  q = 0;
  i++;
  printf("je passe ici %i\n", i);
  if (sh->temp[q])
    {
      if ((sh->temp[q] == '|') && (sh->temp[q + 1] == '|')      \
          && (sh->temp[q + 2] == '|'))
        {
          my_putstr("Invalid null command (To Much Pipes !)\n");
	  /*cmd->type = 0;*/
          my_read(sh);
        }
      else if (sh->temp[q] == '|' && (sh->temp[q + 1] == '|'))
        my_putstr("double pipe\n");
      q++;
    }
  if ((cmd->type == T_PIPE && cmd->next == NULL) ||	\
      (cmd->type == T_DPIPE && cmd->next == NULL))
    {
      aff_error("Broken pipe");
      /*cmd->type = 0;*/
      my_read(sh);
    }
}

void		gere_pipe(t_sh *sh, t_cmd *cmd, int id[2])
{
  int		i;
  int		pid;
  int		fd;

  i = 0;
  fd = 0;
  pipe(id);
  my_checkpipe(sh, cmd);
  if (cmd)
  if (cmd->type == T_PIPE && cmd->next == NULL)
    {
      aff_error("Broken pipe\n");
      my_read(sh);
    }
  while (sh->hard_path[i] != '=' && sh->hard_path[i] != '\0')
    i++;
  cmd->path = set_path(cmd->path, sh->hard_path + i + 1);
  cmd->path = set_exec_path(cmd->path, cmd->tabl);
  trait_bin(cmd);
  my_putstr("\033[1;34m");
  pid = fork();
  if (cmd->pipe != 0)
  {
    if (cmd->pipe == 1)
      fd = xopen(cmd->file_out, O_WRONLY| O_CREAT);
    else if (cmd->pipe == 2)
      fd = xopen(cmd->file_out, O_WRONLY| O_CREAT| O_TRUNC);
    dup2(fd, STDOUT_FILENO);
  }
  if (pid == 0)
    {
      if (my_recode2(cmd->tabl[0], sh) != 1)
	{
	  close(id[1]);
	  dup2(id[0], STDOUT_FILENO);
	  close(id[0]);
	  i = 0;
	  while (cmd->path[i])
	    execve(cmd->path[i++], cmd->tabl, environ);
	}
      exit(EXIT_FAILLURE);
    }
  else if (pid < 0)
    aff_error("error in fork()");
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
      cmd->path = set_exec_path(cmd->path, cmd->tabl);
      trait_bin(cmd);
      if (my_recode2(cmd->tabl[0], sh) != 1)
	{
	  xclose(id[0]);
	  dup2(id[1], STDIN_FILENO);
	  xclose(id[1]);
	  i = 0;
	  while (cmd->path[i])
	    execve(cmd->path[i++], cmd->tabl, environ);
	}
      exit(EXIT_FAILLURE);
    }
    if (fd)
   xclose(fd);
  xclose(id[0]);
  xclose(id[1]);
  wait(NULL);
  sleep(10);
}

void		passe_pipe(t_cmd **cmd)
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
  char		**tabl;

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
	  tabl = my_wordtab_sep(poz, ' ');
	  if (j)
	    poz[i] = tmp[0];
	  cmd_put_in_list(cmd, tabl, j);
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

int		is_a_sep(char c)
{
  int		j;

  j = 0;
  while (SEP_S[j])
  {
    if (c == SEP_S[j])
      return (j);
    j++;
  }
  return (-1);
}

void		aff_error(char *str)
{
  my_putstr("Error : ");
  my_putstr(str);
  my_putchar('\n');
  exit(EXIT_FAILLURE);
}
