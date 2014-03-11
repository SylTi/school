/*
** test_key.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:28:12 2008 jean-philippe rey
** Last update Fri May 16 21:28:13 2008 jean-philippe rey
*/

#include "colle.h"

int	test_key(t_term *term, char c)
{
  if (c == term->kustr[2])
    return (UP);
  if (c == term->kdstr[2])
    return (DOWN);
  if (c == term->klstr[2])
    return (LEFT);
  if (c == term->krstr[2])
   return (RIGHT);
 return (0);
}
