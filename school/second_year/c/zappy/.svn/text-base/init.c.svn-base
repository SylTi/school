/*
** init.c for init_map in /u/all/jaspar_y/rendu/c/zappy
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Wed Jun  3 14:43:44 2009 yoann jaspar
** Last update Mon Jun 22 16:01:19 2009 nikola cebovic
*/

#include "serveur.h"
#include "push.h"

void	display_ressources(t_ressources **ressources, int l_x, int l_y)
{
  int	x;
  int	y;

  x = 0;
  while (x < l_x)
    {
      y = 0;
      while (y < l_y)
	{
	  printf("ressource[%d][%d]::\nlinemate:%d\nderaumere:%d\nsibur:%d\nmendiane:%d\nphiras:%d\nthystame:%d\nFood:%d\n\n", 
		 x, y, ressources[x][y].linemate, ressources[x][y].deraumere, 
		 ressources[x][y].sibur, ressources[x][y].mendiane, 
		 ressources[x][y].phiras, ressources[x][y].thystame, 
		 ressources[x][y].food);
	  y++;
	}
      x++;
    }
}

void	set_ressources(t_ressources **ressources, int x, int y, int team)
{
  set_linemate(ressources, x, y, team);
  set_deraumere(ressources, x, y, team);
  set_sibur(ressources, x, y, team);
  set_mendiane(ressources, x, y, team);
  set_phiras(ressources, x, y, team);
  set_thystame(ressources, x, y, team);
  set_food(ressources, x, y, team);
}

t_ressources	**init(int x, int y, int team)
{
  t_ressources	**ressources;
  int	i;
  int	j;

  ressources = xmalloc(sizeof(t_ressources) * x);
  i = 0;
  while (i < x)
    {
      ressources[i] = xmalloc(sizeof(t_ressources) * y);
      j = 0;
      while (j < y)
	{
	  ressources[i][j].linemate = 0;
	  ressources[i][j].deraumere = 0;
	  ressources[i][j].sibur = 0;
	  ressources[i][j].mendiane = 0;
	  ressources[i][j].phiras = 0;
	  ressources[i][j].thystame = 0;
	  j++;
	}
      i++;
    }
  set_ressources(ressources, x, y, team);
  return (ressources);
}
