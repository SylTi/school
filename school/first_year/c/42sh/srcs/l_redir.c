/*
** l_redir.c for l_redir in /u/epitech_2012/jaspar_y/cu/public/52sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Fri May 30 16:11:34 2008 yoann jaspar
** Last update Mon Jun  9 18:48:38 2008 nicolas bonsall
*/

#include "sh.h"

void	my_exec2(t_sh *sh, t_cmd *to_exec, char *file)
{
  char	*ptr;
  int	exec_fl;
  int	i;

  i = 0;
  exec_fl = 0;
  while (to_exec->path[i] && !exec_fl)
  {
    if ((ptr = trait_bin(to_exec)) == NULL)
      ptr = format(to_exec->path[i], to_exec->tabl[0]);
    exec_fl = my_access(ptr);
    if (!exec_fl)
      free(ptr);
    i++;
  }
  if (exec_fl)
    fork_me2(ptr, to_exec->tabl, file, sh);
  else
    printf("%s : Command not found\n", to_exec->tabl[0]);
}

void	fork_me2(char *file, char **command, char *fichier, t_sh *sh)
{
  int	son_pid;
  int	fd;

  fd = 0;
  check_fichier(fichier, sh);
  fd = xopen(fichier, O_RDONLY);
  if (fd < 0)
    {
      close(fd);
      my_read(sh);
    }
  if ((son_pid = fork()) == 0)
    {
      dup2(fd, STDIN_FILENO);
      execve(file, command, environ);
      exit (0);
    }
  wait(NULL);
  close(fd);
  my_read(sh);
}

void	exec_pipe2(t_sh *sh, t_cmd *cmd, int id[2], char *file)
{
  id[0] = 0;
  id[1] = 0;
  trait_bin(cmd);
  id[0] = xopen(file, O_RDONLY);
  if (id[0] < 0)
    {
      close (id[0]);
      my_read(sh);
    }
  if (cmd->next)
    {
      close(id[0]);
      dup2(id[1], STDIN_FILENO);
      close(id[1]);
      gere_pipe(sh, cmd->next, id);
    }
  else
    wait(NULL);
  close(id[0]);
  close(id[1]);
}
