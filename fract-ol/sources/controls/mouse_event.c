/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:48:58 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:48:50 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../../includes/fract_ol.h"
#include "../../includes/keys.h"

void	ft_zoom(double mouse_x, double mouse_y, t_mlx *mlx, int zoom)
{
	double	ecart_x;
	double	ecart_y;

	ecart_x = (mlx->x_max - mlx->x_min);
	ecart_y = (mlx->y_max - mlx->y_min);
	if (zoom == 1)
	{
		ecart_x *= mlx->zoom;
		ecart_y *= mlx->zoom;
	}
	else
	{
		ecart_x /= mlx->zoom;
		ecart_y /= mlx->zoom;
	}
	mlx->x_max *= mlx->zoom;
	mlx->x_min *= mlx->zoom;
	mlx->y_max *= mlx->zoom;
	mlx->y_min *= mlx->zoom;
	mlx->x_max = mouse_x + (ecart_x / 2);
	mlx->x_min = mlx->x_max - ecart_x;
	mlx->y_max = mouse_y + (ecart_y / 2);
	mlx->y_min = mlx->y_max - ecart_y;
}

void	ft_pre_zoom(int x, int y, t_mlx *mlx, int zoom)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = 0;
	mouse_y = 0;
	mouse_x = mlx->x_min + x * (mlx->x_max - mlx->x_min) / mlx->width;
	mouse_y = mlx->y_max - y * (mlx->y_max - mlx->y_min) / mlx->height;
	ft_zoom(mouse_x, mouse_y, mlx, zoom);
	if (mlx->set == 1)
		ft_mandelbrot(mlx);
	else if (mlx->set == 2)
		ft_julia(mlx);
}

int	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	if ((button == SCROLL_DOWN || button == LEFT_CLIC) && mlx->zoom <= 1)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->zoom -= 0.007;
		ft_pre_zoom(x, y, mlx, 1);
	}
	else if (button == SCROLL_UP || button == RIGHT_CLIC)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->zoom += 0.007;
		if (mlx->zoom > 1)
			mlx->zoom = 1;
		ft_pre_zoom(x, y, mlx, 0);
	}
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	double	pos_x;
	double	pos_y;

	if (mlx->set != 1 && (mlx->x != x || mlx->y != y))
	{
		pos_x = (mlx->x_min + x * (mlx->x_max - mlx->x_min) / mlx->width);
		pos_y = (mlx->y_max - y * (mlx->y_max - mlx->y_min) / mlx->height);
		mlx->x = pos_x;
		mlx->y = pos_y;
		ft_julia(mlx);
	}
	return (1);
}
