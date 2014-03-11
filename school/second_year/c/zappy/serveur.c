/*
** serveur.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 10:54:05 2009 emilien ampe
** Last update Mon Jun 22 17:47:45 2009 virgile bizet
*/

#include "serveur.h"
#include "push.h"

int	select_init(t_env *env, fd_set *fd_read, fd_set *fd_write)
{
  int	i;
  int	fd_max;

  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  fd_max = 0;
  i = 0;
  while (i < MAX_FD)
    {
      if (env->fd[i].type == FD_SERVEUR || env->fd[i].type == FD_CLIENT||
	  env->fd[i].type == FD_CLIENT_GRAPHIQUE ||
	  env->fd[i].type == FD_CLIENT_UNKNOWN)
	{
	  FD_SET(i, fd_read);
	  fd_max = i;
	  if ((strlen(env->fd[i].buf_send)) > 0)
	    FD_SET(i, fd_write);
	}
      i++;
    }
  return (fd_max);
}

void	serveur_loop(t_env *env, t_list *list)
{
  struct timeval *time;
  struct timeval timetmp;

  time = xmalloc(sizeof(struct timeval));
  while (1 && (winner(env) == 0))
    {
      if (list->first && list->first->cmd)
	{
	  gettimeofday(&timetmp, NULL);
	  timersub(&list->first->time, &timetmp, &timetmp);
	  time = &timetmp;
	  if (time->tv_usec < 0 || time->tv_sec < 0)
	    {
	      exec_cmd(list->first->fd, list->first->cmd, env, list);
	      gettimeofday(&timetmp, NULL);
	      timersub(&list->first->time, &timetmp, &timetmp);
	      time = &timetmp;
	    }
	}
      else
	time = NULL;
      if (time == NULL || (time->tv_usec >= 0 && time->tv_sec >= 0))
	serveur_loop2(env, list, time);
    }
}

int	client_name_check(t_env *env, int socket)
{
  int	cc;
  int	i;
  char	*team_incoming;
  int	len_name_team;

  team_incoming = xmalloc(sizeof (team_incoming) * 1024);
  bzero(team_incoming, 1023);
  cc = xread(socket, team_incoming, 1024);
  len_name_team = strlen(team_incoming);
  i = -1;
  team_incoming[len_name_team] = '\0';
  if ((strncmp(team_incoming, "GRAPHIC\n", 8)) == 0)
    {
      free(team_incoming);
      return (-2);
    }
  team_incoming[len_name_team - 1] = '\0';
  while (++i < env->nb_team)
    if ((strncmp(team_incoming, env->team_[i], (len_name_team ))) == 0)
      {
	free(team_incoming);
	return (i);
      }
  free(team_incoming);
  return (-1);
}

void			serveur_read(t_env *env, int sock, t_list *list)
{
  int			res;
  struct sockaddr_in	client_sin;
  unsigned int		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((res = accept(sock, (struct sockaddr *)&client_sin,
                    &client_sin_len)) < 0)
    {
      perror("Error on accept()");
      exit(0);
    }
  if (res > (MAX_FD - 1))
    {
      shutdown(res, 2);
      perror("Plus de sockets disponnible ");
      perror("pour se connecter, relancez le serveur\n");
    }
  else
    {
      client_init(env, res, list);
    }
}

int	main(int ac, char **av)
{
  t_env		env;
  t_list	list;

  init_list(&list);
  if (!parsinator(av, ac, &env))
    exit(EXIT_FAILURE);
  init_env(&env);
  serveur_init(&env, &list);
  serveur_loop(&env, &list);
  return EXIT_SUCCESS;
}
