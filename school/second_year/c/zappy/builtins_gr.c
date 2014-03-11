/*
** builtins_gr.c for builtins_gr in /u/all/bizet_v/cu/rendu/c/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Thu Jun 18 11:46:32 2009 virgile bizet
** Last update Sun Jun 21 17:19:35 2009 virgile bizet
*/

#include "serveur.h"

void	pos_joueur(int fd, char *cmd, t_env *env);
void	ponte(int fd, char *cmd, t_env *env);
void	fin_ponte(int fd, char *cmd, t_env *env);
void	gr_pose(int fd, char *cmd, t_env *env);
void	gr_prend(int fd, char *cmd, t_env *env);
void	gr_broadcast(int fd, char *cmd, t_env *env);
void	send_to_all_graph(char *str, t_env *env);
void	my_death_gr(int fd, char *cmd, t_env *env);
void	gr_incantation(int fd, char *cmd, t_env *env);
/* void	gr_my_incantation(int fd, char *cmd, t_env *env) */

typedef struct  s_opers
{
  char          *opers;
  void           (*f)();
}               t_opers;

t_opers gl_tab_gr[] = {
  {"avance", pos_joueur},
  {"droite", pos_joueur},
  {"gauche", pos_joueur},
/*   {"my_fork", fin_ponte}, */
/*   {"fork", ponte}, */
  {"prend ", gr_prend},
  {"pose", gr_pose},
  {"broadcast", gr_broadcast},
/*   {"expulse", expulse}, */
  {"incantation", gr_incantation},
/*   {"my_incantation", gr_my_incantation}, */
  {"mort", my_death_gr},
  {0, 0}
};

void	gr_pose(int fd, char *cmd, t_env *env)
{
  if (!strncmp(" linemate", &cmd[4], strlen(" linemate")))
    gr_pose2(fd, env, 1);
  else if (!strncmp(" deraumere", &cmd[4], strlen(" deraumere")))
    gr_pose2(fd, env, 2);
  else if (!strncmp(" sibur", &cmd[4], strlen(" sibur")))
    gr_pose2(fd, env, 3);
  else if (!strncmp(" mendiane", &cmd[4], strlen(" mendiane")))
    gr_pose2(fd, env, 4);
  else if (!strncmp(" phiras", &cmd[4], strlen(" phiras")))
    gr_pose2(fd, env, 5);
  else if (!strncmp(" thystame", &cmd[4], strlen(" thystame")))
    gr_pose2(fd, env, 6);
  else if (!strncmp(" nourriture", &cmd[4], strlen(" nourriture")))
    gr_pose2(fd, env, 0);
}

void	gr_prend2(int fd, t_env *env, int res)
{
  char	*buf;

  buf = xmalloc(100);
  sprintf(buf, "pgt %d %d\n", fd, res);
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

void	gr_prend(int fd, char *cmd, t_env *env)
{
  if (!strncmp(" linemate", &cmd[5], strlen(" linemate")))
    gr_prend2(fd, env, 1);
  else if (!strncmp(" deraumere", &cmd[5], strlen(" deraumere")))
    gr_prend2(fd, env, 2);
  else if (!strncmp(" sibur", &cmd[5], strlen(" sibur")))
    gr_prend2(fd, env, 3);
  else if (!strncmp(" mendiane", &cmd[5], strlen(" mendiane")))
    gr_prend2(fd, env, 4);
  else if (!strncmp(" phiras", &cmd[5], strlen(" phiras")))
    gr_prend2(fd, env, 5);
  else if (!strncmp(" thystame", &cmd[5], strlen(" thystame")))
    gr_prend2(fd, env, 6);
  else if (!strncmp(" nourriture", &cmd[5], strlen(" nourriture")))
    gr_prend2(fd, env, 0);
}

void	ponte(int fd, char *cmd, t_env *env)
{
  char	*buf;
  cmd = cmd;
  buf = xmalloc(100);
  sprintf(buf, "pfk %d\n", fd);
  send_to_all_graph(buf, env);
  free(buf);
}

void	serveur_exec_gr(int fd, char *cmd, t_env *env)
{
  int	i;

  i = 0;
  while (gl_tab_gr[i].opers != 0)
    {
      if (!strncmp(gl_tab_gr[i].opers, cmd, strlen(gl_tab_gr[i].opers)))
	gl_tab_gr[i].f(fd, cmd, env);
      i++;
    }
}
