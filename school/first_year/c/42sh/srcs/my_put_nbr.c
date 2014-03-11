/*
** my_putnbr_base.c for my_putnbr_base in /u/epitech_2012/dumez_m/cu/rendu/piscine/Jour_06
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Tue Oct  9 08:46:54 2007 maxime dumez
** Last update Sat May 31 16:35:51 2008 maxime dumez
*/

#include "sh.h"

int	my_put_nbr(int nb)
{
  int	bdix;

  bdix = -1000000000;
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  if (nb >= 0)
    nb = -nb;
  else
    my_putchar('-');
  while (bdix < nb)
    bdix /= 10;
  while (bdix < 0)
    {
      my_putchar('0' + (nb / bdix));
      nb %= bdix;
      bdix /= 10;
    }
  return (0);
}
