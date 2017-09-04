/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:36:38 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/12 19:43:26 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_strlen(const char *str)
{
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

void			ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

int				puterror(char *str)
{
	write(2, "rtv1: error with ", 19);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}
