/*
** random.c for random in /u/epitech_2012/cebovi_n/public/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Thu Jun  4 16:49:16 2009 virgile bizet
** Last update Mon Jun  8 16:40:11 2009 virgile bizet
*/

#include <stdlib.h>

int 	rdtsc()
{
  __asm__ __volatile__("rdtsc");
}

int	my_random(int mod)
{
  int	nb;

  srandom(rdtsc());
  nb = (random() % mod);
  return (nb);
}
