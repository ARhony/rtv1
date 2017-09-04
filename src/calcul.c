/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:00 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:31:36 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void		move_cam(t_vec *cam, t_vec *vec, t_obj *tmp, int invert)
{
	if (invert == 1)
	{
		rot(cam, &tmp->rot, invert);
		rot(vec, &tmp->rot, invert);
	}
	cam->x += invert * tmp->pos.x;
	cam->y += invert * tmp->pos.y;
	cam->z += invert * tmp->pos.z;
	vec->x += invert * tmp->pos.x;
	vec->y += invert * tmp->pos.y;
	vec->z += invert * tmp->pos.z;
	if (invert == -1)
	{
		rot(cam, &tmp->rot, invert);
		rot(vec, &tmp->rot, invert);
	}
}

void		cur_obj(t_vec *cam, t_vec *vec, t_obj *obj, double *k)
{
	move_cam(cam, vec, obj, -1);
	if (obj->type == SPHERE)
		sphere(cam, vec, k);
	else if (obj->type == CYLINDER)
		cylinder(cam, vec, k);
	else if (obj->type == CONE)
		cone(cam, vec, k);
	else if (obj->type == PLAN)
		plane(cam, vec, k);
	move_cam(cam, vec, obj, 1);
}

static void	inter(int x, int y, t_env *env)
{
	double	k[2];
	t_obj	*tmp;
	t_uint	color;

	env->k = 0xFFFFFF;
	env->cur_obj = NULL;
	tmp = env->objs;
	while (tmp)
	{
		cur_obj(&env->cam, &env->vec, tmp, k);
		if (k[0] >= 0 && env->k > k[0] && (env->cur_obj = tmp))
			env->k = k[0];
		if (k[1] >= 0 && env->k > k[1] && (env->cur_obj = tmp))
			env->k = k[1];
		tmp = tmp->next;
	}
	if (env->cur_obj != NULL)
	{
		color = light(env, &env->spot);
		color = add_2color(color, light(env, &env->spot2));
		color = mult_color(color, 0.7);
		color = shadow(env, &env->spot, color);
		color = shadow(env, &env->spot2, color);
		pxl_putimg(env, x, y, color);
	}
}

static void	calc_ray_xy(int x, int y, t_env *env)
{
	env->plan.x = env->focale;
	env->plan.y = (WIDTH / 2.0) - x;
	env->plan.z = (HEIGHT / 2.0) - y;
	env->vec.x = env->plan.x - env->cam.x;
	env->vec.y = env->plan.y - env->cam.z;
	env->vec.z = env->plan.z - env->cam.z;
	rot(&env->vec, &env->camrot, 1);
	inter(x, y, env);
}

void		raytracer(t_env *env)
{
	int		x;
	int		y;
	int		prev_perc;

	prev_perc = -1;
	rot(&env->cam, &env->camrot, 1);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			calc_ray_xy(x, y, env);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->image.mlx, 0, 0);
}
