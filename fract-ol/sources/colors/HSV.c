/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSV.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:56:44 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:48:39 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	ft_rgb(double r, double g, double b)
{
	int	color;

	color = 0;
	r = round(r);
	g = round(g);
	b = round(b);
	color = r;
	color = color << 8;
	color += g;
	color = color << 8;
	color += b;
	return (color);
}

void	hsv_2_rgb_get_colors(double H, double c, double X, t_RGB *RGB)
{
	RGB->r = 0;
	RGB->g = 0;
	RGB->b = 0;
	if ((H >= 60 && H < 120) || (H >= 240 && H < 300))
		RGB->r = X;
	else if ((H >= 0 && H < 60) || (H >= 300 && H < 360))
		RGB->r = c;
	if ((H >= 0 && H < 60) || (H >= 180 && H < 240))
		RGB->g = X;
	else if ((H >= 60 && H < 120) || (H >= 120 && H < 180))
		RGB->g = c;
	if ((H >= 120 && H < 180) || (H >= 300 && H < 360))
		RGB->b = X;
	else if ((H >= 180 && H < 240) || (H >= 240 && H < 300))
		RGB->b = c;
	return ;
}

int	ft_hsv_2_argb(double h, double S, double V)
{
	double	c;
	double	x;
	double	m;
	t_RGB	rgb;

	S /= 100;
	V /= 100;
	c = V * S;
	x = c * (1 - fabs(fmod(h / 60, 2) - 1.0));
	hsv_2_rgb_get_colors(h, c, x, &rgb);
	m = V - c;
	rgb.r = (rgb.r + m) * 255;
	rgb.g = (rgb.g + m) * 255;
	rgb.b = (rgb.b + m) * 255;
	return (ft_rgb(rgb.r, rgb.g, rgb.b));
}
