/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:17:50 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 17:30:56 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int				main(void)
{
	t_env		*env;

	env = init_env();
	raytracer(env);
	init_hooks(env);
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 17, 1L << 0, hook_close, env);
	mlx_loop(env->mlx);
	return (0);
}
