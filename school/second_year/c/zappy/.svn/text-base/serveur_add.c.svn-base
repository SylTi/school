/*
** serveur_add.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 11:46:33 2009 emilien ampe
** Last update Sun Jun 21 17:24:19 2009 virgile bizet
*/

#include "serveur.h"
#include "push.h"

void    display_env(t_env *env)
{
  int   i;

  i = 0;
  printf("xworld::%d\n", env->x_world);
  printf("yworld::%d\n", env->y_world);
  printf("nb_team::%d\n", env->nb_team);
  printf("native_max_team::%d\n", env->native_max_team);
  printf("ports::%d\n", env->port);
  printf("time::%d\n", env->delay);
  while (i < env->nb_team)
    {
      printf("env_team[%d]:%s\n", i, env->team[i].name_team);
      i++;
    }
  i = 0;
  while (i < env->nb_team)
    {
      printf("env_team_[%d]:%s\n", i, env->team_[i]);
      i++;
    }
}

int     xgetprotobyname()
{
  struct protoent       *proto;

  proto = getprotobyname("tcp");
  if (proto == NULL)
    {
      puts("Error on getprotobyname()");
      exit(0);
    }
  return (proto->p_proto);
}

void    client_read(t_env *env, int fd, t_list *list)
{
  int   n;
  char  buf[BUF_RECV];
  int   len;

  len = strlen(buf);
  if ((n = recv(fd, buf, sizeof (buf), 0)) < 0)
    perror("Error on recv()");
  if (n == 0)
    {
      printf("ctrlC at client_read\n");
      shutdown(fd, 2);
      if (env->fd[fd].type == FD_CLIENT)
	env->fd[fd].team->slot_team++;
      env->fd[fd].type = FD_IS_EMPTY;
      unaction(list, fd);

    }
  if ((strcat(env->fd[fd].buf_recv, buf)) == NULL)
    perror("strcat chie");

  put_in_list(fd, env->fd[fd].buf_recv, list, env);
  bzero(env->fd[fd].buf_recv, strlen(env->fd[fd].buf_recv  ));
  bzero(buf, BUF_RECV);
}

void    client_write(t_env *env, int fd)
{
  int   n;
  char  buf[BUF_SEND];

  if ((n = send(fd, buf, sizeof (buf), 0)) < 0)
    perror("Error on send()");
  bzero(buf, BUF_SEND);
  bzero(env->fd[fd].buf_send, BUF_SEND);
}

void    serveur_manage(t_env *env, fd_set *fd_read,
                       fd_set *fd_write, t_list *list)
{
  int   i;

  i = 0;
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, fd_read))
        env->fd[i].f_read(env, i, list);
      else if (FD_ISSET(i, fd_write))
        env->fd[i].f_write(env, i);
      i++;
    }
}
