/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:17:45 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:33:56 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH			1000
# define HEIGHT			1000
# define R				50

typedef unsigned int	t_uint;

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef enum			e_type
{
	SPHERE,
	CYLINDER,
	CONE,
	PLAN
}						t_type;

typedef struct			s_obj
{
	t_type				type;
	t_vec				pos;
	t_vec				rot;
	t_uint				color;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_img
{
	void				*mlx;
	char				*data;
	int					x;
	int					y;
	int					bpp;
	int					sline;
	int					endian;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				image;
	t_obj				*objs;
	t_vec				cam;
	t_vec				camrot;
	t_vec				plan;
	t_vec				vec;
	t_vec				spot;
	t_vec				spot2;
	double				focale;
	double				k;
	t_obj				*cur_obj;
}						t_env;

void					raytracer(t_env *env);
t_env					*init_env(void);
int						key_press(int keycode, t_env *env);
int						hook_close(t_env *env);
void					init_hooks(t_env *env);
void					rot(t_vec *vec, t_vec *rot, int invert);
void					pxl_putimg(t_env *env, int x, int y, t_uint color);
t_obj					*obj_new(t_type type, t_vec pos,
							t_vec rot, t_uint color);
void					obj_next(t_obj **list, t_obj *new);
void					sphere(t_vec *cam, t_vec *vec, double *k);
void					cylinder(t_vec *cam, t_vec *vec, double *k);
void					cone(t_vec *cam, t_vec *vec, double *k);
void					plane(t_vec *cam, t_vec *vec, double *k);
void					cur_obj(t_vec *cam, t_vec *vec,
								t_obj *obj, double *k);
t_uint					light(t_env *env, t_vec *spot);
t_uint					shadow(t_env *env, t_vec *spot, t_uint cur_color);
t_uint					mult_color(t_uint color, double perc);
t_uint					add_2color(t_uint color1, t_uint color2);
void					move_cam(t_vec *cam, t_vec *vec,
							t_obj *tmp, int invert);
#endif
