/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:18 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 17:18:19 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void	rot_x(t_vec *vec, t_vec *rot, int invert)
{
	t_vec	new_vec;

	new_vec.y = vec->y * cos(invert * rot->x)
		+ vec->z * -sin(invert * rot->x);
	new_vec.z = vec->y * sin(invert * rot->x)
		+ vec->z * cos(invert * rot->x);
	vec->y = new_vec.y;
	vec->z = new_vec.z;
}

static void	rot_y(t_vec *vec, t_vec *rot, int invert)
{
	t_vec	new_vec;

	new_vec.x = vec->x * cos(invert * rot->y)
		+ vec->z * sin(invert * rot->y);
	new_vec.z = vec->x * -sin(invert * rot->y)
		+ vec->z * cos(invert * rot->y);
	vec->x = new_vec.x;
	vec->z = new_vec.z;
}

static void	rot_z(t_vec *vec, t_vec *rot, int invert)
{
	t_vec	new_vec;

	new_vec.x = vec->x * cos(invert * rot->z)
		+ vec->y * -sin(invert * rot->z);
	new_vec.y = vec->x * sin(invert * rot->z)
		+ vec->y * cos(invert * rot->z);
	vec->x = new_vec.x;
	vec->y = new_vec.y;
}

void		rot(t_vec *vec, t_vec *rot, int invert)
{
	if (invert == -1)
	{
		rot_x(vec, rot, invert);
		rot_y(vec, rot, invert);
		rot_z(vec, rot, invert);
	}
	else
	{
		rot_z(vec, rot, invert);
		rot_y(vec, rot, invert);
		rot_x(vec, rot, invert);
	}
}
