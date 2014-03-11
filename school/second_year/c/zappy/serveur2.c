/*
** serveur2.c for serveur2 in /u/all/bizet_v/cu/rendu/c/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Mon Jun 22 16:07:15 2009 virgile bizet
** Last update Mon Jun 22 17:38:01 2009 virgile bizet
*/

#include "serveur.h"
#include "push.h"

void	exec_cmd(int fd, char *cmd, t_env *env, t_list *list)
{
  serveur_exec(fd, cmd, env, list);
  serveur_exec_gr(fd, cmd, env);
  pop_front(list);
}

void	serveur_loop2(t_env *env, t_list *list, struct timeval *time)
{
  int	fd_select;
  int	max_fd;
  fd_set	fd_read;
  fd_set	fd_write;

  max_fd = select_init(env, &fd_read, &fd_write);
  if ((fd_select = select(max_fd + 1, &fd_read,
			  &fd_write, NULL, time)) == -1)
    {
      perror("Error on select()");
      exit(errno);
    }
  serveur_manage(env, &fd_read, &fd_write, list);
  if (fd_select == 0)
    exec_cmd(list->first->fd, list->first->cmd, env, list);
}
