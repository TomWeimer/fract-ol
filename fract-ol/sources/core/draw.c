/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:26:10 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 17:05:13 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"
#include "../../mlx/mlx.h"

int	ft_choose_fractal(t_mlx *mlx)
{
	if (mlx->set == 1)
	{
		start_mandel(mlx);
		ft_mandelbrot(mlx);
	}
	else if (mlx->set == 2)
	{
		start_julia(mlx);
		ft_julia(mlx);
	}
	return (1);
}

void	color_pixel(t_data *image, int x, int y, int color)
{
	int	pixel;

	pixel = (y * image->line) + (x * 4);
	if (image->argb == 1)
	{
		image->buff[pixel + 0] = ((color) >> 24) & 0xFF;
		image->buff[pixel + 1] = ((color) >> 16) & 0xFF;
		image->buff[pixel + 2] = ((color) >> 8) & 0xFF;
		image->buff[pixel + 3] = (color) & 0xFF;
	}
	else if (image->argb == 0)
	{
		image->buff[pixel + 0] = (color) & 0xFF;
		image->buff[pixel + 1] = ((color) >> 8) & 0xFF;
		image->buff[pixel + 2] = ((color) >> 16) & 0xFF;
		image->buff[pixel + 3] = ((color) >> 24) & 0xFF;
	}
}

void	draw_fractal(t_mlx *mlx, t_data *image, t_complex constante)
{
	int			x;
	int			y;
	int			color;
	t_complex	c;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		c.i = mlx->y_max - y * constante.i;
		while (x < mlx->width)
		{
			c.r = mlx->x_min + x * constante.r;
			if (mlx->set == 1)
				color = get_pixel_color(mandel_iter(c, mlx), mlx);
			else if (mlx->set == 2)
				color = get_pixel_color(julia_iter(c, mlx), mlx);
			color_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, image->ptr, 0, 0);
}
