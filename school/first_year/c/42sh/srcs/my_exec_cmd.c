/*
** my_exec.c for my_exec in /u/epitech_2012/dumez_m/cu/rendu/c/minishell1
**
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
**
** Started on  Mon Feb 25 16:07:10 2008 maxime dumez
** Last update Thu Jun 12 16:48:14 2008 yoann jaspar
*/

#include "sh.h"

char	*format(char *path, char *file)
{
  char	*p;
  int	k;

  k = 0;
  if (!(p = xmalloc(sizeof(*p) * (strlen(path) + strlen(file) + 2))))
    return (0);
  while (path[k++])
    p[k - 1] = path[k - 1];
  k--;
  if (p[k - 1] != '/')
  {
    p[k] = '/';
    p[k + 1] = '\0';
  }
  p = strcat(p, file);
  return (p);
}

char	*set_tabl(char *str)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  temp = xmalloc(sizeof(char) * 100);
  while ((str[i] <= 48 && str[i] >= 57) ||
	 (str[i] <= 65 && str[i] >= 90) ||
	 (str[i] <= 97 && str[i] >= 122))
    i++;
  j = 0;
  while (str[i] != ' ')
    temp[j] = str[i];
  str = trait_str(str);
  return (str);
}

void	my_exec(t_cmd *to_exec)
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
    fork_me(ptr, to_exec->tabl, ((to_exec->flag == 1) ? to_exec->file_out : 0), to_exec->pipe);
  else
    printf("%s : Command not found\n", to_exec->tabl[0]);
}

void	fork_me(char *file, char **command, char *file_o, int pipe)
{
  int	father_pid;
  int	son_pid;
  int	fd;

  father_pid = getpid();
  if ((son_pid = fork()) <= 0)
  {
    if (file_o)
    {
      if (pipe == 1)
	fd = xopen(file_o, O_WRONLY| O_CREAT);
      else if (pipe == 2)
	fd = xopen(file_o, O_WRONLY| O_CREAT| O_TRUNC);
      dup2(fd, STDOUT_FILENO);
    }
    execve(file, command, environ);
    exit (0);
  }
  else
    while (son_pid != wait(0));
  if (fd)
    close(fd);
}
