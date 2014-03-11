/*
** parsinator.c for parsinator in /u/all/jaspar_y/rendu/c/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Jun  4 11:48:57 2009 yoann jaspar
** Last update Mon Jun 22 17:39:09 2009 nikola cebovic
*/

#include "serveur.h"

struct option	my_options[]=
  {
    {"add_port", 1, NULL, 'p'},
    {"x_world", 1, NULL, 'x'},
    {"y_world", 1, NULL, 'y'},
    {"team", 1, NULL, 'n'},
    {"delay", 2, NULL, 't'},
    {"client_max", 1, NULL, 'c'},
    {NULL, 0, NULL, 0}
  };

typedef struct	s_function
{
  char		option;
  void		(*f)();
}		t_function;

t_function	opt_tab[] = {
  {'p', add_port},
  {'x', x_world},
  {'y', y_world},
  {'c', client_max},
  {'t', delay_exec},
  {'n', team},
  {'?', error},
  {0, 0}
};

void	client_max(char *optarg, int optind, char **argv, t_env *env)
{
  optind = optind;
  argv = argv;
  env->native_max_team = atoi(optarg);
  if (env->native_max_team <= 2)
    {
      puts("Nombre de clients doit etre au minimum de 2");
      display_syno();
    }
}

void	delay_exec(char *optarg, int optind, char **argv, t_env *env)
{
  optind = optind;
  argv = argv;
  env->delay = atoi(optarg);
  if (env->delay == 0)
    {
      puts("Delais d'execution trop court (comme la bite a mimile): Doit etre compris entre 1 et 1000\n");
      display_syno();
    }
}

void	team(char *optarg, int optind, char **argv, t_env *env)
{
  int	i;
  int	nb_team;

  i = optind - 1;
  nb_team = 1;
  env->team_ = xmalloc(sizeof(char) * (nb_team + 1));
  env->team_[0] = xmalloc(sizeof(char) * strlen(optarg));
  env->team_[0] = "\0";
  while (argv[i] != NULL)
    {
      if (argv[i][0] == '-')
	break;
      env->team_[nb_team] = xmalloc(sizeof(char) * strlen(argv[nb_team]));
      env->team_[nb_team] = strcpy(env->team_[nb_team], argv[i]);
      nb_team++;
      i++;
    }
  env->nb_team = nb_team;
  return;
}

int	verif_env_delay(t_env *env)
{
  int	i;

  i = 0;
  if (!env->delay)
    env->delay = DELAY_DEFAULT;
  else if (env->delay <= DELAY_MIN)
    {
      puts("Delais d'execution trop court : Compris entre 1 et 1000\n");
      display_syno();
    }
  else if (env->delay > DELAY_MAX)
    {
      puts("Delais d'execution trop long (un peu comme ma bite) : Compris entre 1 et 1000\n");
      display_syno();
    }
  while (i < env->nb_team)
    i++;
  if (i < 2)
    display_syno();
  return (1);
}

int	verif_env(t_env *env)
{
  if (!env->native_max_team)
    env->native_max_team = CLIENT_DEFAULT;
  if (!env->x_world)
    env->x_world = X_DEFAULT;
  if (!env->y_world)
    env->y_world = Y_DEFAULT;
  if (env->port < 0)
    display_syno();
  return (verif_env_delay(env));
}

int	parsinator(char **argv, int argc, t_env *env)
{
  int	c;
  int	i;
  int	option;

  c = 0;
  env->port = -1;
  env->native_max_team = 0;
  env->delay = 0;
  env->x_world = 0;
  env->y_world = 0;
  while (c != -1)
    {
      option = 0;
      c = getopt_long(argc, argv, "p:x:y:c:t:n:", my_options, &option);
      i = 0;
      while (opt_tab[i].option != 0)
	{
	  if (opt_tab[i].option == c)
	    opt_tab[i].f(optarg, optind, argv, env);
	  i++;
	}
    }
  return (verif_env(env));
}
