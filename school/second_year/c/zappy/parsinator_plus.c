/*
** parsinator_plus.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 12:00:32 2009 emilien ampe
** Last update Mon Jun 22 15:41:45 2009 yoann jaspar
*/

#include "serveur.h"

void	add_port(char *optarg, int optind, char **argv, t_env *env)
{
  optind = optind;
  argv = argv;
  env->port = atoi(optarg);
  if (env->port < 0)
    {
      puts("Nombre de clients nul");
      display_syno();
    }
}

void	y_world(char *optarg, int optind, char **argv, t_env *env)
{
  optind = optind;
  argv = argv;
  env->y_world = atoi(optarg);
  if (env->y_world <= 0)
    {
      puts("Hauteur de la map invalide!\n");
      display_syno();
    }
  else if (env->y_world > Y_MAX)
    {
      puts("Hauteur superieur au maximum autorise!\n");
      display_syno();
    }
  else if (env->y_world < Y_MIN)
    {
      puts("Hauteur inferieur au minimum autorise!\n");
      display_syno();
    }
}

void	x_world(char *optarg, int optind, char **argv, t_env *env)
{
  optind = optind;
  argv = argv;
  env->x_world = atoi(optarg);
  if (env->x_world <= 0)
    {
      puts("Largeur de la map invalide!\n");
      display_syno();
    }
  else if (env->x_world > X_MAX)
    {
      puts("Largeur superieur au maximum autorise!\n");
      display_syno();
    }
  else if (env->x_world < X_MIN)
    {
      puts("Largeur inferieur au minimum autorise!\n");
      display_syno();
    }
}
