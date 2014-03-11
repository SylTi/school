/*
** bultin.h for bultin  in /u/epitech_2012/jaspar_y/public/42sh
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Thu May 29 16:47:08 2008 sylvain tissier
** Last update Mon Jun  9 19:37:47 2008 maxime dumez
*/

#define AL		"42sh.conf"
#define HI		"histo.hst"
#define MAX_ALIAS	20


typedef struct		s_bultin
{
  int			flag_histo;
  char			**alias;
  char			**histo;
  char			*prompt;

}			t_bultin;
