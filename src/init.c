/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:17:54 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 19:13:13 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void			init_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 17, 1L << 0, hook_close, env);
}

void			init_scene(t_env *env)
{
	env->focale = WIDTH / (tan(0.2));
	env->cam = (t_vec){-env->focale - 200, 0, 0};
	env->camrot = (t_vec){0, 0, 0};
	env->spot = (t_vec){0, 200, 400};
	env->spot2 = (t_vec){0, -200, 400};
	env->objs = NULL;
	obj_next(&env->objs, obj_new(CYLINDER, (t_vec){50, 50, 100},
									(t_vec){0, 0, 0}, 0xB25400));
	obj_next(&env->objs, obj_new(SPHERE, (t_vec){0, -90, 0},
									(t_vec){0, 0, 0}, 0x0092B2));
	obj_next(&env->objs, obj_new(CONE, (t_vec){0, 0, 0},
									(t_vec){0, 0, 0}, 0xFF8519));
	obj_next(&env->objs, obj_new(PLAN, (t_vec){0, 0, -200},
									(t_vec){0, -0.1, 0}, 0x43DDFF));
}

t_env			*init_env(void)
{
	t_env		*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "- RTV1 -");
	env->image.mlx = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->image.data = mlx_get_data_addr(env->image.mlx, &env->image.bpp,
										&env->image.sline, &env->image.endian);
	env->image.bpp = env->image.bpp >> 3;
	init_scene(env);
	return (env);
}
