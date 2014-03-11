/*
** usual.c for classic in /u/all/cebovi_n/cu/rendu/c/zappy
** 
** Made by nikola cebovic
** Login   <cebovi_n@epitech.net>
** 
** Started on  Wed Jun  3 13:07:49 2009 nikola cebovic
** Last update Wed Jun  3 15:39:42 2009 nikola cebovic
*/

#include "serveur.h"

void	my_putstr(int fd, char *str)
{
  int	i;

  for (i = 0; str[i] != '\0'; i++)
    xwrite(fd, &str[i], 1);
}
