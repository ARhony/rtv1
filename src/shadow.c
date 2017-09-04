/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:21 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:31:57 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void	set_vecs(t_env *env, t_vec *spot, t_vec *p, t_vec *light)
{
	*p = (t_vec){env->cam.x + env->k * env->vec.x,
				env->cam.y + env->k * env->vec.y,
				env->cam.z + env->k * env->vec.z};
	*light = (t_vec){spot->x - p->x, spot->y - p->y, spot->z - p->z};
}

t_uint		shadow(t_env *env, t_vec *spot, t_uint cur_color)
{
	t_vec	p;
	t_vec	light;
	double	new_k;
	double	k[2];
	t_obj	*tmp;

	if (env->cur_obj->type != PLAN)
		return (cur_color);
	set_vecs(env, spot, &p, &light);
	new_k = -1;
	tmp = env->objs;
	while (tmp)
	{
		if (tmp != env->cur_obj)
		{
			cur_obj(&p, &light, tmp, k);
			new_k = (k[0] > 0.1 && k[0] < 0.9) ? k[0] : new_k;
			new_k = (k[1] > 0.1 && k[1] < 0.9) ? k[1] : new_k;
		}
		tmp = tmp->next;
	}
	cur_color = (new_k != -1) ? mult_color(cur_color, 0.8) : cur_color;
	return (cur_color);
}
