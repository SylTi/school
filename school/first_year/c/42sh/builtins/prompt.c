/*
** prompt.c for prompt 42 in /u/epitech_2012/jaspar_y/public/42sh/bultins
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Fri May 30 16:29:44 2008 sylvain tissier
** Last update Wed Jun  4 18:42:37 2008 sylvain tissier
*/

#include "../includes/sh.h"

char		*do_time(char t)
{
  struct tm	*today;
  char		tmpbuf[2048];
  time_t	ltime;
  char		*str;

  time(&ltime);
  today = localtime(&ltime);
  bzero(tmpbuf, sizeof(tmpbuf));
  if (t == 'a')
    {
      strftime(tmpbuf, 2048, "%R", today);
      str = strdup(tmpbuf);
      return (str);
    }
  if (t == 'b')
    {
      strftime(tmpbuf, 2048, "%I:%M", today);
      str = strdup(tmpbuf);
      return (str);
    }
  if (t == 'c')
    {
      strftime(tmpbuf, 2048, "%I:%M:%S%p", today);
      str = strdup(tmpbuf);
      return (str);
    }
  return (NULL);
}

char	*check_mod(char	c)
{
  if (c == 'M')
    return (getenv("HOST"));
  if (c == 'n')
    return (getenv("USER"));
  if (c == '/')
    return (getenv("PATH"));
  if (c == '~')
    return (getenv("PWD"));
  if (c == 'T')
    return (do_time('a'));
  if (c == 't')
    return (do_time('b'));
  if (c == 'p')
    return (do_time('c'));
  else
    return (NULL);
 }

char	*ret_prompt(char *prompt)
{
  char	*ret;
  char	*prompt_final;
  int	i;
  int	y;

  prompt_final = xmalloc(sizeof(*prompt) * 42);
  i = 0;
  if (environ[0] != NULL)
    {
      while (prompt[i] != '\0')
	{
	  if (prompt[i] == '%')
	    {
	      i++;
	      if ((ret = check_mod(prompt[i])) != NULL)
		{
		  prompt_final = strcat(prompt_final, ret);
		}
	      else
		my_putstr("NOT-DISPO");
	    }
	  else
	    {
	      y = strlen(prompt_final);
	      prompt_final[y] = prompt[i];
	    }
	  i++;
	}
    return (prompt_final);
    }
  else
    return ("NO-ENV ?>");
}
