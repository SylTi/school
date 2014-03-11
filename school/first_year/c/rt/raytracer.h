/*
** raytracer.h for raytracer in /u/epitech_2012/ampe_e/cu/public/raytracer
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Fri May 12 16:55:24 2006 emilien ampe
** Last update Fri May 23 14:50:36 2008 emilien ampe
*/

#ifndef			RT_H__
# define		RT_H__

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define	ESC	65307
#define OEIL	0
#define PLAN	1
#define SPHERE	2
#define CONE	3
#define CYLINDR	4
#define PARABO	5

#define SQ(x) ((x) * (x))

#define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

#define SAT(Value) (((Value) > 255) ? 255 : (Value))

#define MAX_COSA(v1, v2) (((v1) > (v2) ? v1 : v2))

#define MAX_LAMBDA(v1, v2) ((((v1) < (v2) && (v1) > (double)0.000001) ? 1 : 0))

#define NO_NEG(v1) (((v1) > (double)0.000001) ? 1 : 0)

#define NEG(v1) (((v1) < (double)0.000001) ? 1 : 0)

#define MAX_LIGHT(Value) (((Value) > (double)1) ? (double)1 : (Value))

#define MIN_LIGHT(Value) (((Value) < 0) ? 0 : (Value))

#define	MAX_ANGLES(Value) (((Value) == ((double)2 * M_PI) || (Value) == ((double)(-2) * M_PI)) ? 1 : 0)

#define	MIN_ANGLES(Value) (((Value) == ((double)0) || (Value) == ((double)(-0))) ? 1 : 0)

#define ADD_COLOR(col1, col2) (((col1 + col2) > 255) ? 255 : (col1 + col2))

#define MULT_COLOR(col1, col2) (((col1 * col2) > 255) ? 255 : (col1 * col2))

#define NORME(v1, v2 , v3) (sqrt(SQ(v1) + SQ(v2) + SQ(v3)))

#define REFLECT(v1, v2, v3) (((double)(-2) * v1 * v2) + v3) 

#define TRANSPA(v1, v2, v3, v4, v5) ((((v1) * (v2)) + ((v1) * (v3) - (v4))) * (v5))

typedef struct  s_list
{
  void		*data;
  struct s_list *next;
}               t_list;

typedef struct	s_reflect_transpa
{
  double	save_x_oeil;
  double	save_y_oeil;
  double	save_z_oeil;
  double	save_x1;
  double	save_y1;
  double	save_z1;
  double	Norme_Normal;
  double	Norme_Vision;
  double	Normal_x_unit;
  double	Normal_y_unit;
  double	Normal_z_unit;
  double	Vision_x_unit;
  double	Vision_y_unit;
  double	Vision_z_unit;
  double	scal_VN_unit;
  double	Rx;
  double	Ry;
  double	Rz;
  double	Tx;
  double	Ty;
  double	Tz;
}		t_reflect_transpa;

typedef struct	s_obj
{
  int		type;
  double	k1;
  double	k2;
  double	xt;
  double	yt;
  double	zt;
  double	ax;
  double	ay;
  double	az;
  double	var;
  unsigned long	col;
  double	trans;
  double	indice_trans;
  double	refle;
  int		decx_on;
  double	dmax_x;
  double	dmin_x;
  int		decy_on;
  double	dmax_y;
  double	dmin_y;
  int		decz_on;
  double	dmax_z;
  double	dmin_z;
  int		pl_type;
  double	pl_vax;
  double	pl_vay;
  double	pl_vbx;
  double	pl_vby;
  int		pcs_shadow;
  int		sci_x_on;
  double	sci_x_mod;
  double	sci_x_pas;
  int		sci_y_on;
  double	sci_y_mod;
  double	sci_y_pas;
  int		sci_z_on;
  double	sci_z_mod;
  double	sci_z_pas;
}		t_obj;

typedef struct	s_spot
{
  double	x_spot;
  double	y_spot;
  double	z_spot;
  double       	var;
  unsigned long	col;
}		t_spot;

typedef struct	s_mlx
{
  int		bpp;
  int		sizeline;
  int		endian;
  char		*data;
  void		*mlx;
  void		*win;
  void		*img;
  int		win_x;
  int		win_y;
}		t_mlx;

typedef union	s_color_x
{
  unsigned long	color;
  unsigned char	c_color[4];
}		t_color_x;

typedef struct	s_parse
{
  char		*pars;
  void		(*fct)();
}		t_parse;

typedef struct	s_elem
{
  char		*pars;
  void		(*fct)();
  int		type;
}		t_elem;

typedef struct	s_ray
{
  int		nb;
  unsigned long	(*fct)();
}		t_ray;

typedef struct	s_coord
{
  t_list	**spot;
  int		fd;
  double	coef_spot;
  char		*str;
  int		winx;
  int		winy;
  int		no_object;
  int		k_k;
  double	cosa;
  double	light_var;
  double	isf;
  double	Nx;
  double	Ny;
  double	Nz;
  double	t[3];
  double       	ax;
  double	bx;
  double	cx;
  double       	o_x;
  double	o_y;
  double	o_z;
  double       	o_rx;
  double	o_ry;
  double	o_rz;
  double	Lx;
  double	Ly;
  double	Lz;
  double	Px;
  double	Py;
  double	Pz;
  double	Norme_N;
  double	Norme_P;
  double	scal_NP;
  double	x1;
  double	y1;
  double	z1;
  double	Vx;
  double	Vy;
  double	Vz;
  double	xr;
  double	yr;
  double	zr;
  double	Lsh_x;
  double	Lsh_y;
  double	Lsh_z;
  double	delta;
  double	lambda_1;
  double	lambda_2;
  double	lambda;
  int		aa;
  int		shadow;
  int		max_shadow;
}		t_coord;

/*			anti_aa.c			*/

unsigned long	anti_aa(int x, int y, t_coord *c, t_list *b, t_list *spot);

/*			calc_rot.c			*/

void		calc_li_rotation(t_coord *c, t_obj *b);
void		calc_li_rotation_inv(t_coord *c, t_obj *b);
void		calc_sh_rotation(t_coord *c, t_obj *b);
void		calc_sh_rotation_inv(t_coord *c, t_obj *b);

/*			calc_rot2.c			*/

void		calc_rotation(t_coord *c, t_obj *b);
void		calc_rotation_inv(t_coord *c, t_obj *b);

/*			calc.c				*/

unsigned long	calc(t_coord *c, t_list *b, t_list *spot);

/*			calc_cosa.c			*/

double		calcul_cosa(t_coord *c);

/*			calc_delta.c			*/

void		calc_delta_cone(t_coord *c, t_obj *b);
void		calc_delta_cyl(t_coord *c, t_obj *b);
void		calc_delta_sph(t_coord *c, t_obj *b);
void		calc_delta_para(t_coord *c, t_obj *b);

/*			calc_roeil.c			*/

void		calc_rotation_oeil(t_coord *c);

/*			check_list_size.c		*/

int		check_list_size(t_list *l);

/*			fill.c				*/

void            fill_empty_obj(t_obj *obj);
void		fill(t_list **b, t_coord *t_x, int type);

/*			fill_3_space.c			*/

void		fill_3_space(char *str, t_coord *t_x);

/*			fill_oeil.c			*/

void		fill_oeil(t_coord *t_x);

/*			fill_space.c			*/
int		my_isnum(char c);
char		*fill_space(char *str);

/*			fill_spot.c			*/

void		fill_spot(t_list **sp, t_coord *t_x);

/*			fill_win_size.c			*/

void		fill_win_size(t_coord *t_x, char *str);

/*			gere.c				*/

int		gere_expose(void *param);
int		gere_key(int keycode, void *param);
void		put_pixel_to_image(t_mlx *s, int x, int y, void *color);

/*			get_col.c			*/

unsigned int	get_col(double col[3]);

/*			gl_parse1.c			*/

void		orig(t_obj *obj, t_coord *t_x, char *str);
void		rota(t_obj *obj, t_coord *t_x, char *str);
void		var(t_obj *obj, t_coord *t_x, char *str);
void		col(t_obj *obj, t_coord *t_x, char *str);
void		transpa(t_obj *obj, t_coord *t_x, char *str);

/*			gl_parse2.c			*/

void		refle(t_obj *obj, t_coord *t_x, char *str);
void		dec_x(t_obj *obj, t_coord *t_x, char *str);
void		sci_x(t_obj *obj, t_coord *t_x, char *str);
void		dec_y(t_obj *obj, t_coord *t_x, char *str);
void		sci_y(t_obj *obj, t_coord *t_x, char *str);

/*			gl_parse3.c			*/

void		dec_z(t_obj *obj, t_coord *t_x, char *str);
void		sci_z(t_obj *obj, t_coord *t_x, char *str);
void		pl_va(t_obj *obj, t_coord *t_x, char *str);
void		pl_vb(t_obj *obj, t_coord *t_x, char *str);

/*			init_n.c			*/

void		init_n(t_coord *c, t_obj *obj);

/*			init_sX.c			*/

void		init_sX(char **av);

/*			inter.c				*/

int		inter_cone(t_coord *c, t_obj *b);
int		inter_cyl(t_coord *c, t_obj *b);
int		inter_sph(t_coord *c, t_obj *b);
int		inter_para(t_coord *c, t_obj *b);
int             inter_plan(t_coord *c, t_obj *b);

/*			li_trans.c			*/

void		li_trans(t_coord *c, t_obj *b);
void		de_li_trans(t_coord *c, t_obj *b);

/*			light.c				*/

void		light_calc_p(t_coord *c);
void		light_calc_l(t_coord *c, t_spot *tmp);
void		light_calc_color(t_coord *c, t_color_x *coco);
void		light_calc_tr(t_coord *c, t_list *b, t_list *spot, t_color_x *coco, t_obj *obj);
unsigned long	light(t_coord *c, t_list *b, t_list *spot, t_obj *obj);

/*			load.c				*/

void		loading(t_mlx *s, t_coord *c, int x);

/*			my_put_in_list.c		*/

void		my_put_in_list(t_list **l, void *d);

/*			ombres1.c			*/

double		shadow(t_coord *c, t_list *b, t_list *sp);
int		sh_inter_cone(t_coord *c, t_obj *b);
int		sh_inter_cyl(t_coord *c, t_obj *b);
int		sh_inter_sph(t_coord *c, t_obj *b);

/*			ombres2.c			*/

int		sh_inter_plan(t_coord *c, t_obj *b);
void		sh_calc_delta_cone(t_coord *c, t_obj *b);
void		sh_calc_delta_cyl(t_coord *c, t_obj *b);
void		sh_calc_delta_sph(t_coord *c, t_obj *b);

/*			parse_conf.c			*/

void		parse_conf(t_coord *t_x, t_list **b, t_list **spot, char *file);

/*			plan_limite.c			*/

int		if_plan_limite(t_coord *c, t_obj *b);

/*			prepare.c			*/
  
void		prep_oeil(t_list *b, t_coord *s, int type);
void		prep_window(t_list *b, t_coord *s, int type);
void		prep_spot(t_list *b, t_coord *s, int type);
void		prep_aa(t_list *b, t_coord *s, int type);
void		open_conf(t_coord *t_x, char *file);

/*			ray1.c				*/

unsigned long	ray1(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray2(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray3(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray4(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray5(int x, int y, t_coord *c, t_list *b, t_list *spot);

/*			ray2.c				*/

unsigned long	ray6(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray7(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray8(int x, int y, t_coord *c, t_list *b, t_list *spot);
unsigned long	ray9(int x, int y, t_coord *c, t_list *b, t_list *spot);

/*			reflection.c			*/

unsigned long	reflect(t_coord *c, t_list *b, t_list *spot, t_color_x col, t_obj *obj);

/*			remplis_image.c			*/

void		remplis_image(t_mlx *s, t_coord *c, t_list *b, t_list *spot);

/*			rotation.c			*/

void		rotation_x(double *y, double *z, double angle_x);
void		rotation_y(double *x, double *z, double angle_y);
void		rotation_z(double *x, double *y, double angle_z);

/*			save_coor_ref_trans.c		*/

void		save_coord(t_reflect_transpa *save, t_coord *c);
void		restore_coord(t_reflect_transpa *save, t_coord *c);
void		calcul_vecteur_unitaire(t_reflect_transpa *save, t_coord *c);
void		remplace_coord(t_reflect_transpa *save, t_coord *c);
void		maz(t_reflect_transpa *save);

/*			sh_calc.c			*/

void		sh_calc_n(t_coord *c);
void		sh_calc_lsh(t_coord *c, t_spot *tmp);

/*			sh_trans.c			*/

void		sh_trans(t_coord *c, t_obj *b);
void		sh_de_trans(t_coord *c, t_obj *b);

/*			trans.c				*/

void		trans(t_coord *c, t_obj *b);
void		de_trans(t_coord *c, t_obj *b);

/*			transparence.c			*/

unsigned long	transparancy(t_coord *c, t_list *b, t_list *spot, t_color_x col, t_obj *obj);
void		refraction(t_coord *c, t_obj *obj, t_reflect_transpa *save);

/*			autres				*/

void		xerror(char *str);

/*			autres				*/

void		my_putstr(char *str);
void		*xmalloc(size_t size);
char		*get_next_line(const int fd);

#endif		/* !RT_H__ */
