/*
** builtins.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 14:21:11 2009 emilien ampe
** Last update Sun Jun 21 16:04:20 2009 yoann jaspar
*/

#include "serveur.h"

typedef struct  s_opers
{
  char          *opers;
  void           (*f)();
}               t_opers;

t_opers gl_tab2[] = {
  {"avance", avance},
  {"droite", droite},
  {"gauche", gauche},
  {"voir", voir},
  {"prend ", prend},
  {"pose", pose},
  {"expulse", expulse},
  {"broadcast ", broadcast},
  {"incantation", incantation},
  {"my_incantation", my_incantation},
  {"inventaire", inventaire},
  {"my_fork", my_fork2},
  {"fork", my_fork},
  {"mort", my_death},
  {"connect_nbr", connect_nbr},
  {0, 0}
};

void	connect_nbr(int fd, char *arg, t_env *env, t_list *list)
{
  char	buf[256];

  arg = arg;
  list = list;
  sprintf(buf, "%i\n", env->fd[fd].team->slot_team);
  write (fd, buf, strlen(buf));
}

void	my_death(int fd, char *arg, t_env *env, t_list *list)
{
  arg = arg;
  xwrite(fd, "mort\n", 5);
  shutdown(fd, 1);
  env->fd[fd].type = 4;
  unaction(list, fd);
  env->fd[fd].team->slot_team ++;
}

void	my_fork2(int fd, char *arg, t_env *env, t_list *list)
{
  arg = arg;
  list = list;
  env->fd[fd].team->slot_team++;
}

void	my_fork(int fd, char *arg, t_env *env, t_list *list)
{
  arg = arg;
  put_in_list(fd, "my_fork", list, env);
  xwrite(fd, "ok\n", 3);
}

void	serveur_exec(int fd, char *buf, t_env *env, t_list *list)
{
  int	i;

  i = 0;
  while (gl_tab2[i].opers != 0)
    {
      if (!strncmp(gl_tab2[i].opers, buf, strlen(gl_tab2[i].opers)))
	gl_tab2[i].f(fd, buf, env, list);
      i++;
    }
}
