/*
** init2.c for init2 in /u/epitech_2012/cebovi_n/public/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Thu Jun  4 16:47:09 2009 virgile bizet
** Last update Sun Jun 21 17:44:22 2009 yoann jaspar
*/

#include "serveur.h"
#include "push.h"

void	set_mendiane(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	mendiane;
  int	x;
  int	y;

  mendiane = 0;
  while (mendiane < (DEF_MENDIANE * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].mendiane += 1;
	  mendiane++;
	}
    }
}

void	set_sibur(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	sibur;
  int	x;
  int	y;

  sibur = 0;
  while (sibur < (DEF_SIBUR * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].sibur += 1;
	  sibur++;
	}
    }
}

void	set_food(t_ressources **ressources, int l_x, int l_y, int team)
{
  int	food;
  int	x;
  int	y;

  food = 0;
  while (food < (DEF_FOOD * team))
    {
      x = my_random(l_x);
      y = my_random(l_y);
      if (x < l_x && y < l_y)
	{
	  ressources[x][y].food += 1;
	  food++;
	}
    }
}
