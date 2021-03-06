/*
** sh.h for sh in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh/srcs
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Wed Apr 16 13:58:26 2008 yoann jaspar
** Last update Fri Jun 13 15:16:24 2008 nicolas bonsall
*/

#ifndef __SH_H__
#define __SH_H__

/*--Includes & Macros--*/

#include <termcap.h>

char            *tgetstr();


#include <term.h>
#include <ncurses.h>

char            *getenv();
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"
#include <dirent.h>


#ifndef EXIT_FAILLURE
#define EXIT_FAILLURE	-1
#endif	/*EXIT_FAILLURE*/
#define	BUFF_DEF	100
#define	BUFF_MIN	8
#define	SEP_S		";|<>"
#define	PRIO_S		"()\"'"
#define	PARA_LEFT	0
#define	PARA_RIGHT	1
#define	QUOTE_DOUBLE	2
#define	QUOTE_SIMPLE	3
#define	T_CMD_N		0
#define	T_PIPE		1
#define	T_DPIPE		9
#define	T_REDIR_IN	2
#define	T_REDIR_OUT	3
/*--------------------*/

#define AL		"./42sh.conf"
#define HI		"./histo.hst"
#define MAX_ALIAS	20
#define MAX_HISTO	50

/*Struct getenv*/
typedef struct		s_ge
{
  char			*tmp1;
  char			*tmp2;
}			t_ge;

/*Struct Bultin*/
typedef struct	s_bultin
{
  int		flag_histo;
  char		**alias;
  char		**histo;
  char		*prompt;
}		t_bultin;

/*Struct shell*/
typedef	struct	s_cstr
{
  char		*clstr;
  char		*cmstr;
  char		*krstr;
  char		*kustr;
  char		*klstr;
  char		*kdstr;
  char		*kbstr;
}		t_cstr;

typedef struct	s_sh
{
  char		*cmd;
  char		*temp;
  t_cstr	*cst;
  char		**temp2;
  char		*prev_dir;
  char		**path;
  char		*hard_path;
  char		*home;
  char		*fichier;
  char		*str2;
  int		 flag;
  int		pipe;
  struct termios old_term;
  t_bultin	*bult;
}		t_sh;

typedef	struct	s_cmd
{
  struct s_cmd	*next;
  char		**tabl;
  char		**path;
  int		type;
  int		flag;
  char		*file_out;
  int		pipe;
}		t_cmd;

typedef	struct	s_auto
{
  struct dirent	*data;
  struct s_auto	*next;
}		t_auto;

typedef struct	s_pp
{
  int		fds[2];
  char		**cmd1;
  char		**cmd2;
  char		**args1;
  char		**args2;
}		t_pp;


/*---Environ---*/
extern char	**environ;
/*-------------*/

void    *xmalloc(int size);
int     recup_term(struct termios *old);



/*--Fonctions--*/

int	main(void);
void	my_discribe(char **environ);

void	my_present(t_sh *sh);
int	xread(int d, void *buf, int nbytes);
int	xwrite(int d, const void *buf, size_t nbytes);
int	xclose(int fd);
char	*my_getenv2(char *str, char **env);
char	*my_getenv(char *str, char **env);
char	*trait_str(char *ref);
void    my_putstr_env(char *str);
void	my_prompt(char **environ, int new, char *prompt);
void	my_aff_line(int b);
void	my_read(t_sh *sh);
void	trait_cmd(t_sh *sh);
int	check_exec(t_sh *sh);
void	print_tab(char **tabl);
int	count_tab(char **tabl);
char	**tabcat(char *begin, char **dst);

/*--My_recode--*/
int	my_recode(t_sh *sh);
int	check_exit(char *str);
void	exit_shell();
int	check_env(char *str);
void	env_shell(char **environ, t_sh *sh);
int	check_cd(char *str);
void	all_cd(t_sh *sh);
void	cd_shell_tilde(char *ref, char *str, int flag, t_sh *sh);
void	cd_shell(char *str, int flag, t_sh *sh);
int	check_setenv(char *str);
int	verif_ref(char **ref);
int	check_var_to_env(char *str, char **env);
void	add_to_env(char **ref, char **environ);
void	change_env(char **ref, char **env, int ref_env);
void	setenv_shell(char **environ, t_sh *sh);
char	**set_temp2(char **temp2, char *temp);
int	check_echo(char *str);
void	echo_shell(char *str, t_sh *sh);
/**/
int	check_unsetenv(char *str);
char	**my_rm_all_env(char **environ);
void	unsetenv_shell(char **environ, t_sh *sh);
char	**my_check_rm_env(char **environ, char *ref);
int	check_env_var(char **environ, char *str);
char	**rm_good_env(char **environ, int ref_env);
/*#############*/
int     my_strlen2(char *str);
int     my_strlen(char *str);
void	simple_exec(t_sh *sh);
/*-------------*/
int	args_len(char *str, int	ref);
char	**set_args(char **args, char *buf, int ref);
char	**check_tilde(char **temp2, char *home);
void	exec_simple(t_sh *sh);
void    exec_pipe2(t_sh *sh, t_cmd *cmd, int id[2], char *file);
int	my_exec_cmd(char *path, char **cmd);
char	**set_exec_path(char **path, char **temp2);
char	**set_path(char **path, char *temp);
/*#############*/
/*-------------*/
int	is_a_sep(char c);
/*void	make_my_list_cmd(t_sh *sh, t_cmd **cmd);*/
char	**my_wordtab_sep(char *str, char sep);
void	cmd_aff_list(t_cmd *cmd);
void	cmd_rev_list(t_cmd **cmd);
/*#############*/
void	gere_redir(t_sh *sh);
void	exec_cmd_line(t_sh *sh, t_cmd *cmd);
void	gere_pipe(t_sh *sh, t_cmd *cmd, int id[2]);
void	passe_pipe(t_cmd **cmd);
void	make_my_list_cmd(t_sh *sh, t_cmd **cmd);
/*int	is_a_sep(char c);*/
void	aff_error(char *str);
/*-------------*/
void	cmd_put_in_list(t_cmd **cmd, char **data, int type);
void	cmd_free_list(t_cmd *cmd, int freetab);
void	free_tab(char **tabl);
void	aff_tab(char **tabl);
void	cmd_finish_tab(t_cmd *cmd);
/*void	cmd_aff_list(t_cmd *cmd);*/
/*void	cmd_rev_list(t_cmd **cmd);*/
/*#############*/
char	*format(char *path, char *file);
void	my_exec(t_cmd *to_exec);
void	fork_me(char *file, char **command, char *fl, int pipe);
int	my_access(char *file);
/*-------------*/
void	exec_r_redir(char *file, t_sh *sh, t_cmd *cmd);
void	r_redir(t_sh *sh, int ref, t_cmd *cmd);
int	check_r_redir(char *ex);
/*#############*/
void	all_cd2(char *str, t_sh *sh);
void	setenv_shell2(char **environ,char *str, t_sh *sh);
void	unsetenv_shell2(char **environ, t_sh *sh, char *str);
int	check_pipe(char *str);
void	save_the_last(t_sh *sh, char *str);
void	its_cd_moins(t_sh *sh, char **str);
int	check_redir(char *ex, t_sh *sh);
void	fork_me2(char *file, char **command, char *fichier, t_sh *sh);
int	my_recode2(char *str, t_sh *sh);
void	gere_pipe2(t_sh *sh, t_cmd *cmd, int id[2], char *file);
void	exec_cmd_line2(t_sh *sh, t_cmd *cmd, char *file);
char	*trait_temp_for_l(char *temp);
void	exc_l_redir(char *file, t_sh *sh, t_cmd *cmd);
void	l_redir(t_sh *sh, t_cmd *cmd);
void	my_putstr(char *str);
void	my_putchar(char c);
void	cd_fct(t_sh *sh);
void	to_flech_r(char *s, int *i);
void	my_putchar_err(char c);
void	my_strerror(char *str);
int	xopen(const char *path, int flags);
char	*my_strcat(char *cont, char *ajout);
void	*xmalloc(int size);
void	my_exec2(t_sh *sh, t_cmd *to_exec, char *file);
char	*trait_bin(t_cmd *cmd);
void	replace_slash(char *str, t_cmd *cmd);
void	replace_dot(char *str, t_cmd *cmd);
char	*trait_str_for_cat(char *str);
void	recup_exec(char *str, t_cmd *cmd);
int	check_next_slash(char *str, int ref);
char	*cpy_tab(char *str, int i);
char	**copy_tab(char **tabl, char **tab_cp);
int	check_fichier(char *fichier, t_sh *sh);
char    *find_slash(char *str);
char	*add_str_end(char *cmd, char *buff, int *len, int print);
char	*remplace_alias(char *cmd, char **alias);
int	check_alias(char *cmd, char **alias);
void	print_alias(char **alias);

int     recup_term(struct termios *old);
void    no_canonical_mode(struct termios old);
void    init_keys(t_cstr **act);
char    *cores(char *crstr, char **zone);
void    restore_mode(struct termios old);
t_bultin        *get_conf();
char    **get_history();
void    make_my_list_with_alias(t_sh *sh, t_cmd *cmd);
char    *auto_complet(char *str);
void    builtin_echo(char **str);
int     check_term_cap(t_sh *sh, char *buff, int *len);
int     check_synt(char *cmd);
char    *ret_prompt(char *prompt);


#endif /*!MYSH_H */
