/*
** builtins_gr3.c for 3 in /u/epitech_2012/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Fri Jun 19 16:27:45 2009 sylvain tissier
** Last update Sun Jun 21 17:19:53 2009 virgile bizet
*/

#include "serveur.h"

void	pos_joueur(int fd, char *cmd, t_env *env);
void	ponte(int fd, char *cmd, t_env *env);
void	fin_ponte(int fd, char *cmd, t_env *env);
void	gr_pose(int fd, char *cmd, t_env *env);
void	gr_prend(int fd, char *cmd, t_env *env);
void	gr_broadcast(int fd, char *cmd, t_env *env);
void	send_to_all_graph(char *str, t_env *env);

typedef struct  s_opers
{
  char          *opers;
  void           (*f)();
}               t_opers;

void	pos_joueur(int fd, char *cmd, t_env *env)
{
  int	i;
  char	*buf;

  cmd = cmd;
  buf = xmalloc(100);
  i = 0;
  sprintf(buf, "ppo %d %d %d %d\n",
	  fd,
	  env->fd[fd].x,
	  env->fd[fd].y,
	  env->fd[fd].sens);
  send_to_all_graph(buf, env);
  free(buf);
}

void	fin_ponte(int fd, char *cmd, t_env *env)
{
  fd = fd;
  cmd = cmd;
  env = env;
}

void	my_death_gr(int fd, char *cmd, t_env *env)
{
  char	*buf;

  cmd = cmd;
  buf = xmalloc(10);
  sprintf(buf, "pdi %d\n", fd);
  send_to_all_graph(buf, env);
  free (buf);
}

void	gr_incantation(int fd, char *cmd, t_env *env)
{
  int	i;
  char	*buf;

  i = 0;
  cmd = cmd;
  buf = xmalloc(1000);
  sprintf(buf, "pic %d %d %d",
	  env->fd[fd].x,
	  env->fd[fd].y,
	  env->fd[fd].lvl + 1);
  send_to_all_graph(buf, env);
  while (i < MAX_FD)
    {
/*       if () */
      i++;
    }
  send_to_all_graph("\n", env);
  free(buf);
}
