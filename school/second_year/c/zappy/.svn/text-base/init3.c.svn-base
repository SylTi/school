/*
** init3.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 17:43:31 2009 yoann jaspar
** Last update Sun Jun 21 17:44:23 2009 yoann jaspar
*/

#include "serveur.h"
#include "push.h"

void	set_linemate(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	linemate;
  int	x;
  int	y;

  linemate = 0;
  while (linemate < (DEF_LINEMATE * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].linemate += 1;
	  linemate++;
	}
    }
}

void	set_deraumere(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	deraumere;
  int	x;
  int	y;

  deraumere = 0;
  while (deraumere < (DEF_DERAUMERE * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].deraumere += 1;
	  deraumere++;
	}
    }
}

void	set_thystame(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	thystame;
  int	x;
  int	y;

  thystame = 0;
  while (thystame < (DEF_THYSTAME * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].thystame += 1;
	  thystame++;
	}
    }
}

void	set_phiras(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	phiras;
  int	x;
  int	y;

  phiras = 0;
  while (phiras < (DEF_PHIRAS * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].phiras += 1;
	  phiras++;
	}
    }
}
