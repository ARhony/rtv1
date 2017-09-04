/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:03 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:31:39 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_uint		mult_color(t_uint color, double perc)
{
	int		i;
	int		n_color[3];

	i = -1;
	while (++i < 3)
	{
		n_color[i] = (color >> ((2 - i) << 3)) & 0xFF;
		n_color[i] = n_color[i] * perc;
		n_color[i] = (n_color[i] > 0xFF ? 0xFF : n_color[i]);
		n_color[i] = (n_color[i] < 0 ? 0 : n_color[i]);
	}
	return ((n_color[0] << 16) + (n_color[1] << 8) + n_color[2]);
}

t_uint		add_2color(t_uint color1, t_uint color2)
{
	int		i;
	int		n_color1[3];
	int		n_color2[3];

	i = -1;
	while (++i < 3)
	{
		n_color1[i] = (color1 >> ((2 - i) << 3)) & 0xFF;
		n_color2[i] = (color2 >> ((2 - i) << 3)) & 0xFF;
		n_color1[i] = n_color1[i] + n_color2[i];
		n_color1[i] = (n_color1[i] > 0xFF ? 0xFF : n_color1[i]);
		n_color1[i] = (n_color1[i] < 0 ? 0 : n_color1[i]);
	}
	return ((n_color1[0] << 16) + (n_color1[1] << 8) + n_color1[2]);
}
