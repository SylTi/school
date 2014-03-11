/*
** builtins_gr2.c for 2 in /u/epitech_2012/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Fri Jun 19 16:23:50 2009 sylvain tissier
** Last update Sun Jun 21 16:08:09 2009 yoann jaspar
*/

#include "serveur.h"

void	pos_joueur(int fd, char *cmd, t_env *env);
void	ponte(int fd, char *cmd, t_env *env);
void	fin_ponte(int fd, char *cmd, t_env *env);
void	gr_pose(int fd, char *cmd, t_env *env);
void	gr_prend(int fd, char *cmd, t_env *env);
void	gr_broadcast(int fd, char *cmd, t_env *env);

typedef struct  s_opers
{
  char          *opers;
  void           (*f)();
}               t_opers;

void	send_to_all_graph(char *str, t_env *env)
{
  int	i;

  i = 0;
  while (i < MAX_FD)
    {
      if (env->fd[i].type == FD_CLIENT_GRAPHIQUE)
	{
	  write(1, str, strlen(str));
	  write(i, str, strlen(str));
	}
      i++;
    }
}

void	gr_expulse(int fd, char *cmd, t_env *env)
{
  char	*buf;
  int	fd_p;

  cmd = cmd;
  buf = xmalloc(100);
  sprintf(buf, "pex %d\n", fd);
  send_to_all_graph(buf, env);
  fd_p = 0;
  while (fd_p < MAX_FD)
    {
      if (env->fd[fd_p].type == FD_CLIENT &&
	  env->fd[fd_p].x == env->fd[fd].x &&
	  env->fd[fd_p].y == env->fd[fd].y &&
	  fd_p != fd)
	{
	  sprintf(buf,
		   "ppo %d %d %d %d\n",
		   fd_p, env->fd[fd_p].x,
		   env->fd[fd_p].y,
		   env->fd[fd_p].sens);
	  send_to_all_graph(buf, env);
	}
      fd_p++;
    }
}

void	gr_broadcast(int fd, char *cmd, t_env *env)
{
  char	*str;

  str = xmalloc(strlen(cmd) * sizeof(char *));
  sprintf(str, "pbc %d %s\n", fd, &cmd[10]);
  send_to_all_graph(str, env);
  free(str);
}

void	print_bct(t_env *env, char *buf, int fd)
{
  sprintf(buf, "bct %d %d %d %d %d %d %d %d %d\n",
	  env->fd[fd].x,
	  env->fd[fd].y,
	  env->map[env->fd[fd].x][env->fd[fd].y].food,
	  env->map[env->fd[fd].x][env->fd[fd].y].linemate,
	  env->map[env->fd[fd].x][env->fd[fd].y].deraumere,
	  env->map[env->fd[fd].x][env->fd[fd].y].sibur,
	  env->map[env->fd[fd].x][env->fd[fd].y].mendiane,
	  env->map[env->fd[fd].x][env->fd[fd].y].phiras,
	  env->map[env->fd[fd].x][env->fd[fd].y].thystame);
  send_to_all_graph(buf, env);

}

void	gr_pose2(int fd, t_env *env, int res)
{
  char	*buf;

  buf = xmalloc(100);
  sprintf(buf, "pdr %d %d\n", fd, res);
  send_to_all_graph(buf, env);
  sprintf(buf, "pin %d %d %d %d %d %d %d %d %d %d\n",
	  fd,
	  env->fd[fd].x,
	  env->fd[fd].y,
	  env->fd[fd].inventaire.food,
	  env->fd[fd].inventaire.linemate,
	  env->fd[fd].inventaire.deraumere,
	  env->fd[fd].inventaire.sibur,
	  env->fd[fd].inventaire.mendiane,
	  env->fd[fd].inventaire.phiras,
	  env->fd[fd].inventaire.thystame);
  send_to_all_graph(buf, env);
  print_bct(env, buf, fd);
  free(buf);
}
