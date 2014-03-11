/*
** serveur_init.c for serveur_init in /u/all/bizet_v/cu/rendu/c/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Mon Jun  8 17:05:58 2009 virgile bizet
** Last update Mon Jun 22 16:49:12 2009 virgile bizet
*/

#include "serveur.h"

void	init_env(t_env *env)
{
  int	i;

  env->team = xmalloc(sizeof(&env->team));
  i = 0;
  while (env->nb_team > i)
    {
      env->team = xmalloc(sizeof (env->team[i]));
      i++;
    }
  i = 0;
  while (env->nb_team > i)
    {
      env->team[i].NUM_CLIENT = xmalloc(sizeof(env->native_max_team) + 1);
      i++;
    }
  i = 0;
  while (env->nb_team > i)
    {
      env->team[i].slot_team = env->native_max_team;
      env->team[i].nbr_max_lvl = 0;
      i++;
    }
  env->map = init(env->x_world, env->y_world, env->native_max_team);
}

void	serveur_verif(int sock, struct sockaddr_in sin)
{
  if ((bind(sock, (struct sockaddr *)&sin, sizeof (sin))) < 0)
    {
      perror("Error on bind()");
      exit(0);
    }
  if ((listen(sock, MAX_FD)) < 0)
    {
      perror("Error on listen()");
      exit(0);
    }
}

void			serveur_init(t_env *env, t_list *list)
{
  struct sockaddr_in	sin;
  int			sock;
  int			i;

  list = list;
  if ((sock = socket(PF_INET, SOCK_STREAM, xgetprotobyname())) < 0)
    {
      perror("Error on socket()");
      exit(0);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(env->port);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  serveur_verif(sock, sin);
  i = 0;
  while (i < MAX_FD)
    env->fd[i++].type = FD_IS_EMPTY;
  env->fd[sock].type = 0;
  env->fd[sock].f_write = NULL;
  env->fd[sock].f_read = serveur_read;
}

void	init_pos(t_env *env, int socket)
{
  char	*str;

  str = NULL;
  env->fd[socket].x = my_random(env->x_world - 1);
  env->fd[socket].y = my_random(env->y_world - 1);
  env->fd[socket].sens = UP;
  env->fd[socket].lvl = 1;
  str = xmalloc(100);
  sprintf(str, "%d %d\n", env->x_world, env->y_world);
  xwrite(socket, str, strlen(str));
  free(str);
}

void	client_init2(t_env *env, int socket, t_list *list, int num_team)
{
  char	*str;

  env->team[num_team].slot_team--;
  my_putstr(socket, env->team[num_team].NUM_CLIENT);
  my_putstr(1, env->team[num_team].NUM_CLIENT);
  put_in_list(socket, "mort\n", list, env);
  init_pos(env, socket);
  env->fd[socket].inventaire.linemate  = 0;
  env->fd[socket].inventaire.deraumere = 0;
  env->fd[socket].inventaire.sibur = 0;
  env->fd[socket].inventaire.mendiane = 0;
  env->fd[socket].inventaire.phiras = 0;
  env->fd[socket].inventaire.thystame  = 0;
  env->fd[socket].inventaire.food = 10;
  env->fd[socket].f_read = client_read;
  env->fd[socket].f_write = client_write;
  env->fd[socket].type = FD_CLIENT;
  str = xmalloc(100);
  sprintf(str, "pnw %d %d %d %d %d %s\n",
	  socket, env->fd[socket].x,
	  env->fd[socket].y, env->fd[socket].sens, env->fd[socket].lvl,
	  env->team_[atoi(env->fd[socket].team->NUM_CLIENT)]
	  );
  send_to_all_graph(str, env);
  free(str);
}

void	client_init(t_env *env, int socket, t_list *list)
{
  int	num_team;

  list = list;
  xwrite(socket, "BIENVENUE\n", 10);
  num_team = client_name_check(env, socket);
  if (num_team == -1)
    xclose(socket);
  else if (num_team == -2)
    {
      client_graphic(env, socket);
      env->fd[socket].f_read = client_read;
      env->fd[socket].f_write = client_write;
    }
  else if (num_team > -1)
    {
      env->fd[socket].team = &env->team[num_team];
      if (env->team[num_team].slot_team == 0)
	{
	  xclose(socket);
	  return ;
	}
      client_init2(env, socket, list, num_team);
    }
  return ;
}
