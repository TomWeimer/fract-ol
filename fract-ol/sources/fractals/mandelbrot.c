/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:38:47 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:56:54 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"
#include "../../mlx/mlx.h"

void	start_mandel(t_mlx *mlx)
{
	mlx->x_max = 1.0;
	mlx->x_min = -2 ;
	mlx->y_max = 1 ;
	mlx->y_min = -1 ;
}

t_iter	mandel_iter(t_complex c, t_mlx *mlx)
{
	t_complex	z;
	double		tmp;
	int			i;
	t_iter		index;

	z.r = c.r;
	z.i = c.i;
	i = 0;
	while (i < mlx->max_iter)
	{
		z.r2 = z.r * z.r;
		z.i2 = z.i * z.i;
		if (z.r2 + z.i2 > 4)
			break ;
		tmp = z.r;
		z.r = z.r2 - z.i2 + c.r;
		z.i = 2 * tmp * z.i + c.i;
		i++;
	}
	index.z = z;
	index.i = i;
	index.c = c;
	index.max_iter = mlx->max_iter;
	return (index);
}

void	ft_mandelbrot(t_mlx *mlx)
{
	t_data		img;
	t_complex	constante;

	constante.r = (mlx->x_max - mlx->x_min) / mlx->width;
	constante.i = (mlx->y_max - mlx->y_min) / mlx->height;
	img.ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	img.buff = mlx_get_data_addr(img.ptr, &img.bpp, &img.line, &img.argb);
	draw_fractal(mlx, &img, constante);
	mlx_destroy_image(mlx->mlx_ptr, img.ptr);
}
