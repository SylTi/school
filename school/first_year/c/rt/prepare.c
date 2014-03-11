/*
** prepare.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 16:16:47 2008 emilien ampe
** Last update Fri May 23 13:41:29 2008 emilien ampe
*/

#include "raytracer.h"

void	prep_oeil(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  fill_oeil(s);
}

void	prep_window(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  fill_win_size(s, s->str);
  s->winx = s->t[0];
  s->winy = s->t[1];
}

void	prep_spot(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  fill_spot(s->spot, s);
}

void	prep_aa(t_list *b, t_coord *s, int type)
{
  b = b;
  type = type;
  s->aa = atoi(fill_space(s->str));
}

void	open_conf(t_coord *t_x, char *file)
{
  if ((t_x->fd = open(file , 0, O_RDONLY)) < 0)
    xerror("Impossible d'ouvrir le fichier de configuration\n");
}
