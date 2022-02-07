/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ARGB.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:54:42 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:48:27 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	get_red(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_blue(int color)
{
	return ((color >> 8) & 0xFF);
}

int	ft_color(int color1, t_iter p, t_mlx *mlx)
{
	double	red;
	double	green;
	double	blue;
	double	index;

	if (mlx->color == 2)
		color1 = 0x4E598C;
	else if (mlx->color == 3)
		color1 = 0x84E8C62;
	index = p.i + 1 - (log (log (p.z.i2 + p.z.r2) / log(2)) / log(2));
	red = sin(0.36 * index + 1) * 100 + 155;
	red = red - get_red(color1);
	green = sin(0.16 * index + 3) * 100 + 155;
	green = green - get_green(color1);
	blue = sin(0.56 * index + 6) * 100 + 155;
	blue = blue - get_blue(color1);
	return (ft_rgb(red, blue, green));
}
