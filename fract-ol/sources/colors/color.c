/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:27:35 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:48:32 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	get_pixel_color(t_iter p, t_mlx *mlx)
{
	double	h;
	double	s;
	double	v;

	if (p.i == p.max_iter)
		return (0);
	if (mlx->color >= 1 && mlx->color < 4)
		return (ft_color(0x031927, p, mlx));
	else if (mlx->color >= 4)
	{
		h = 266;
		s = (p.i / p.max_iter) * 100;
		v = (p.i / p.max_iter) * 100;
		if (mlx->color == 5)
		{	
			h = 31;
			s = 100;
		}
		return (ft_hsv_2_argb(h, s, v));
	}
	return (0);
}
