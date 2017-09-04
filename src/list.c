/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:18:15 by aramon            #+#    #+#             */
/*   Updated: 2017/06/30 18:31:52 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_obj			*obj_new(t_type type, t_vec pos, t_vec rot, t_uint color)
{
	t_obj		*new;

	if ((new = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new->type = type;
	new->pos = pos;
	new->rot = rot;
	new->color = color;
	new->next = NULL;
	return (new);
}

void			obj_next(t_obj **objs, t_obj *new)
{
	t_obj		*tmp;

	if (!*objs)
		*objs = new;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
