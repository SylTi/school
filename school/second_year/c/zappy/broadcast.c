/*
** broadcast.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 14:29:09 2009 emilien ampe
** Last update Sun Jun 21 16:07:10 2009 yoann jaspar
*/

#include "serveur.h"

void	send_broadcast(int fd, int k, char *arg)
{
  char	*buf;

  buf = xmalloc(sizeof(char) * 20 + strlen(&arg[9]) + 1);
  sprintf(buf, "message %i,%s\n", k, &arg[10]);
  xwrite(fd, buf, strlen(buf));
  xwrite(1, buf, strlen(buf));
  free(buf);
}

void	check_flag(int flag, int fd)
{
  if (flag != 0)
    xwrite(fd, "ok\n", 3);
  else
    xwrite(fd, "ok\n", 3);

}
void	broadcast(int fd, char *arg, t_env *env, t_list *list)
{
  int	i;
  int	ret;
  int	flag;
  char	*buf;

  buf = NULL;
  i = 0;
  flag = 0;
  list = list;
  while (i < MAX_FD)
    {
      if (i != fd && env->fd[i].type == FD_CLIENT)
	{
	  if ((ret = my_broadcast(fd, env, i)))
	    {
	      flag++;
	      send_broadcast(i, ret, arg);
	    }
	}
      i++;
    }
  check_flag(flag, fd);
}
