/*
** parse_conf.c for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer/lolo/test
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu May 22 15:58:19 2008 emilien ampe
** Last update Fri May 23 14:47:51 2008 emilien ampe
*/

#include "raytracer.h"

t_elem	gl_elem[] =
  {
    {"Oeil", prep_oeil, 0},
    {"Spot", prep_spot, 0},
    {"Plan", fill, 1},
    {"Sphere", fill, 2},
    {"Cone", fill, 3},
    {"Cylindre", fill, 4},
    {"WINDOW", prep_window, 0},
    {"Anti_Aliasing", prep_aa, 0},
    {0, 0, 0},
  };

void   	parse_conf(t_coord *t_x, t_list **b, t_list **spot, char *file)
{
  int		i;
  
  t_x->spot = spot;
  if (!access(file, R_OK))
    {
      *b = NULL;
      open_conf(t_x, file);
      while ((t_x->str = get_next_line(t_x->fd)))
	{
	  if (t_x->str && t_x->str[0] != '*')
	    {
	      if (!strncmp(t_x->str, "FIN_CONF", 3))
		{
		  close(t_x->fd);
		  break;
		}
	      i = 0;
	      while (gl_elem[i].pars != 0)
		{
		  if (!strncmp(gl_elem[i].pars, t_x->str, strlen(gl_elem[i].pars)))
		    gl_elem[i].fct(b, t_x, gl_elem[i].type);
		  i++;
		}
	      free(t_x->str);
	    }
	}
    }
  else
    xerror("Fichier de configuration inexistant\n");
}
