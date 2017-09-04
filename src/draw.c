/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:06 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:31:42 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void		pxl_putimg(t_env *env, int x, int y, t_uint color)
{
	int		i;
	int		dest;
	t_uint	new_color;

	new_color = mlx_get_color_value(env->mlx, color);
	dest = y * env->image.sline + x * env->image.bpp;
	i = -1;
	while (++i < env->image.bpp)
	{
		if (env->image.endian == 0)
			env->image.data[dest + i] = new_color >> (i << 3) & 0xFF;
		else
			env->image.data[dest + i] = new_color
				>> (env->image.bpp - ((i + 1) << 3)) & 0xFF;
	}
}
