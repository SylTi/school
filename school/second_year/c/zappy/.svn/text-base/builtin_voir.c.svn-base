/*
** builtin_voir.c for zappy in /u/all/jaspar_y/rendu/c/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Wed Jun 10 18:10:26 2009 yoann jaspar
** Last update Sun Jun 21 17:40:29 2009 yoann jaspar
*/

#include "serveur.h"

void	print_ressource(int fd, int ressourcetmp, char *nom_ressource)
{
  char	*buf;

  buf = xmalloc(sizeof(char) * strlen(nom_ressource) + 2);
  while (ressourcetmp)
    {
      xwrite(fd, " ", 1);
      xwrite(fd, nom_ressource, strlen(nom_ressource));
      ressourcetmp--;
    }
  free(buf);
}

void	display_voir(int x, int y, int fd, t_env *env)
{
  int	ressourcetmp;

  ressourcetmp = 0;
  while (ressourcetmp < MAX_FD)
    {
      if (env->fd[ressourcetmp].type == FD_CLIENT &&
	  env->fd[ressourcetmp].x == x &&
	  env->fd[ressourcetmp].y == y)
	xwrite(fd, " joueur", 7);
      ressourcetmp++;
    }
  ressourcetmp = env->map[x][y].linemate;
  print_ressource(fd, ressourcetmp, "linemate");
  ressourcetmp = env->map[x][y].deraumere;
  print_ressource(fd, ressourcetmp, "deraumere");
  ressourcetmp = env->map[x][y].sibur;
  print_ressource(fd, ressourcetmp, "sibur");
  ressourcetmp = env->map[x][y].mendiane;
  print_ressource(fd, ressourcetmp, "mendiane");
  ressourcetmp = env->map[x][y].phiras;
  print_ressource(fd, ressourcetmp, "phiras");
  ressourcetmp = env->map[x][y].thystame;
  print_ressource(fd, ressourcetmp, "thystame");
  ressourcetmp = env->map[x][y].food;
  print_ressource(fd, ressourcetmp, "nourriture");
}

void	voir(int fd, char *arg, t_env *env, t_list *list)
{
  list = list;
  arg = arg;
  if (env->fd[fd].sens == UP)
    voir_up(fd, env);
  else if (env->fd[fd].sens == DOWN)
    voir_down(fd, env);
  else if (env->fd[fd].sens == LEFT)
    voir_left(fd, env);
  else if (env->fd[fd].sens == RIGHT)
    voir_right(fd, env);
}
