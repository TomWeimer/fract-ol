/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:47:32 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:48:45 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../../includes/fract_ol.h"
#include "../../includes/keys.h"

int	key_down(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(1);
	}
	if (keycode == TOUCH_C)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx-> color == 5)
			mlx->color = 1;
		else
			mlx->color = mlx->color + 1;
		if (mlx->set == 1)
			ft_mandelbrot(mlx);
		else if (mlx->set == 2)
			ft_julia(mlx);
	}
	return (0);
}

void	ft_loop_events(t_mlx *mlx, int set)
{
	mlx_key_hook(mlx->win_ptr, key_down, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_zoom, mlx);
	if (set == 2)
		mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
}
