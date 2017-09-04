/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:09 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 17:18:10 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void		sphere(t_vec *cam, t_vec *vec, double *k)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2);
	b = 2 * (cam->x * vec->x + cam->y * vec->y
			+ cam->z * vec->z);
	c = pow(cam->x, 2) + pow(cam->y, 2)
		+ pow(cam->z, 2) - pow(R, 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void		cylinder(t_vec *cam, t_vec *vec, double *k)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(vec->x, 2) + pow(vec->y, 2);
	b = 2 * (cam->x * vec->x + cam->y * vec->y);
	c = pow(cam->x, 2) + pow(cam->y, 2) - pow(R / 1.5, 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void		cone(t_vec *cam, t_vec *vec, double *k)
{
	double	new_z;
	double	a;
	double	b;
	double	c;
	double	delta;

	new_z = 0.7 * vec->z;
	a = pow(vec->x, 2) + pow(vec->y, 2) - pow(new_z, 2);
	b = 2 * (cam->x * vec->x + cam->y * vec->y
			- cam->z * new_z);
	c = pow(cam->x, 2) + pow(cam->y, 2)
		- pow(cam->z, 2);
	delta = pow(b, 2) - 4 * a * c;
	k[0] = (delta >= 0 ? (-b - sqrt(delta)) / (2 * a) : -1);
	k[1] = (delta >= 0 ? (-b + sqrt(delta)) / (2 * a) : -1);
}

void		plane(t_vec *cam, t_vec *vec, double *k)
{
	if (vec->z < 0.000001 && vec->z > -0.000001)
		k[0] = -1;
	else
		k[0] = -cam->z / vec->z;
	k[1] = -1;
}
