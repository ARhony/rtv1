/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:17:57 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 17:32:05 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int	key_press(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

int	hook_close(t_env *env)
{
	(void)env;
	exit(EXIT_SUCCESS);
	return (0);
}
