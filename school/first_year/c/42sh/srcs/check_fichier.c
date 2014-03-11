/*
** check_fichier.c for check_fichier in /u/epitech_2012/jaspar_y/cu/public/62sh
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Jun  9 12:54:35 2008 yoann jaspar
** Last update Mon Jun  9 15:08:09 2008 yoann jaspar
*/

#include "sh.h"

int	check_fichier(char *fichier, t_sh *sh)
{
  int	i;

  i = 0;
  while (fichier[i] != '\0')
  {
    if (fichier[i] == '<' || fichier[i] == '>' || fichier[i] == ' ')
    {
      printf("Ambigous declaration of file\n");
      my_read(sh);
    }
    i++;
  }
  return (0);
}
