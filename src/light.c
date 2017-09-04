/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:13 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:31:48 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double		norme_vec(t_vec *vec)
{
	double	res;

	res = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
	return (res);
}

void		get_normal(t_vec *normal, t_vec *p, t_obj *obj)
{
	if (obj->type == SPHERE)
		*normal = (t_vec){p->x, p->y, p->z};
	else if (obj->type == CYLINDER)
		*normal = (t_vec){p->x, p->y, 0};
	else if (obj->type == CONE)
		*normal = (t_vec){p->x, p->y, -0.1 * p->z};
	else if (obj->type == PLAN)
		*normal = (t_vec){0, 0, 100};
}

t_uint		light(t_env *env, t_vec *spot)
{
	t_vec	p;
	t_vec	light;
	t_vec	normal;
	double	cos_a;
	t_uint	new_color;

	p = (t_vec){env->cam.x + env->k * env->vec.x,
				env->cam.y + env->k * env->vec.y,
				env->cam.z + env->k * env->vec.z};
	light = (t_vec){spot->x - p.x, spot->y - p.y, spot->z - p.z};
	new_color = env->cur_obj->color;
	get_normal(&normal, &p, env->cur_obj);
	cos_a = (normal.x * light.x + normal.y * light.y + normal.z * light.z)
		/ (norme_vec(&normal) * norme_vec(&light));
	new_color = (cos_a >= 0 && cos_a <= 1)
		? mult_color(env->cur_obj->color, cos_a) : 0;
	return (new_color);
}
