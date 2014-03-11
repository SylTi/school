/*
** check_liste_size.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 16:19:03 2008 emilien ampe
** Last update Fri May 23 13:30:15 2008 yoann jaspar
*/

#include "raytracer.h"

int		check_list_size(t_list *l)
{
  int	i;
  
  i = 0;
  while (l)
    {
      l = l->next;
      i++;
    }
  return (i);
}
