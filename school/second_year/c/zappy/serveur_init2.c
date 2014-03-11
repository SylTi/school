/*
** serveur_init2.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 17:31:23 2009 yoann jaspar
** Last update Mon Jun 22 17:53:10 2009 virgile bizet
*/

#include "serveur.h"

void	client_graphic4(t_env *env, int fd, int x)
{
  char	*str;

  str = xmalloc(200);
  if (env->fd[x].type == FD_CLIENT)
    {
      sprintf(str, "pnw %d %d %d %d %d %s\n",
	      x,
	      env->fd[x].x,
	      env->fd[x].y,
	      env->fd[x].sens,
	      env->fd[x].lvl,
	      env->team_[atoi(env->fd[x].team->NUM_CLIENT)]
	      );
      xwrite(fd, str, strlen(str));
    }
}

void	client_graphic3(t_env *env, int fd, int x)
{
  char	*str;

  str = xmalloc(200);
  if (env->team_[x][0])
    {
      sprintf(str, "tna %s\n", env->team_[x]);
      xwrite(1, str, strlen(str));
      xwrite(fd, str, strlen(str));
    }
  free(str);
}

void	client_graphic2(t_env *env, int fd, int x)
{
  int	y;
  char	*str;

  y = 0;
  str = xmalloc(200);
  while (y < env->y_world)
    {
      sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n",
	      x,
	      y,
	      env->map[x][y].food,
	      env->map[x][y].linemate,
	      env->map[x][y].deraumere,
	      env->map[x][y].sibur,
	      env->map[x][y].mendiane,
	      env->map[x][y].phiras,
	      env->map[x][y].thystame);
      xwrite(fd, str, strlen(str));
      y++;
    }
}

void	client_graphic(t_env *env, int fd)
{
  char	*str;
  int	x;

  x = 0;
  env->fd[fd].type = FD_CLIENT_GRAPHIQUE;
  str = xmalloc(200);
  sprintf(str, "msz %d %d\n", env->x_world, env->y_world);
  xwrite(fd, str, strlen(str));
  sprintf(str, "sgt %d\n", env->delay);
  xwrite(fd, str, strlen(str));
  while (x < env->x_world)
    client_graphic2(env, fd, x++);
  x = 0;
  while (x < env->nb_team)
    client_graphic3(env, fd, x++);
  x= 0;
  while (x < MAX_FD)
    client_graphic4(env, fd, x++);
  return ;
}
