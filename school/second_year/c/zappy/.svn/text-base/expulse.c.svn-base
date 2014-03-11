/*
** expulse.c for zappy expulse joueur in /u/epitech_2012/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Fri Jun  5 16:18:48 2009 sylvain tissier
** Last update Fri Jun 19 15:17:06 2009 emilien ampe
*/

#include "serveur.h"

int	check_expulse(int fd_p, int fd, t_env *env)
{
  char	*buf;

  if (env->fd[fd_p].type == FD_CLIENT &&
      env->fd[fd_p].x == env->fd[fd].x &&
      env->fd[fd_p].y == env->fd[fd].y &&
      fd_p != fd)
    {
      buf = xmalloc(sizeof(char) * 30);
      if (env->fd[fd].sens == UP)
	expulse_up(env, fd_p);
      else if (env->fd[fd].sens == RIGHT)
	expulse_right(env, fd_p);
      else if (env->fd[fd].sens == DOWN)
	expulse_down(env, fd_p);
      else if (env->fd[fd].sens == LEFT)
	expulse_left(env, fd_p);
      sprintf(buf, "deplacement %d\n", env->fd[fd].sens);
      xwrite(fd_p, buf, strlen(buf));
      free(buf);
      return (1);
    }
  return (0);
}

void	expulse(int fd, char *arg, t_env *env, t_list *list)
{
  int	fd_p;
  int	flag;

  list = list;
  arg =arg;
  fd_p = 0;
  flag = 0;
  while (fd_p < MAX_FD)
    {
      flag += check_expulse(fd_p, fd, env);
      fd_p++;
    }
  if (flag == 0)
    xwrite(fd, "ko\n", 3);
  else
    xwrite(fd, "ok\n", 3);
}
