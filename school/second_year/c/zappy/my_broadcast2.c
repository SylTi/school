/*
** my_broadcast2.c for broadcast2 in /u/epitech_2012/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Sat Jun 20 12:42:07 2009 sylvain tissier
** Last update Sun Jun 21 16:04:45 2009 yoann jaspar
*/

#include "serveur.h"

typedef struct	s_broadcast
{
  int		haut;
  int		bas;
  int		gauche;
  int		droite;
  int		samex;
  int		samey;
}		t_broad;

int	*my_broad_up(int y, int *champ)
{
  int	i;

  i = 0;
  y = 1;
  while (i <= 8)
    {
      champ[i] = y;
      i++;
      y++;
    }
  return (champ);
}

int	*my_broad_down(int y, int *champ)
{
  int	i;

  i = 0;
  y = 5;
  while (i <= 8)
    {
      champ[i] = y;
      i++;
      if (y == 8)
	y = 1;
      else
	y++;
    }
  return (champ);
}

int	*my_broad_right(int y, int *champ)
{
  int	i;

  i = 0;
  y = 3;
  while (i <= 8)
    {
      champ[i] = y;
      i++;
      if (y == 8)
	y = 1;
      else
	y++;
    }
  return (champ);
}

int	*my_broad_left(int y, int *champ)
{
  int	i;

  i = 0;
  y = 7;
  while (i <= 8)
    {
      champ[i] = y;
      i++;
      if (y == 8)
	y = 1;
      else
	y++;
    }
  return (champ);
}

int		*my_angle(int dir)
{
  int		y;
  int		*champ;

  y = 0;
  champ = xmalloc(sizeof(champ) * 9 + 1);
  if (dir == UP)
      champ = my_broad_up(y, champ);
  else if (dir == LEFT)
      champ = my_broad_left(y, champ);
  else if (dir == DOWN)
      champ = my_broad_down(y, champ);
  else if (dir == RIGHT)
      champ = my_broad_right(y, champ);
  return (champ);
}

