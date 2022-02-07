/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:20:04 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:49:00 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../../includes/fract_ol.h"

void	init_information(t_mlx *mlx, int set)
{
	int		width;
	int		height;

	width = 1000;
	height = 750;
	mlx->set = set;
	mlx->width = width;
	mlx->height = height;
	mlx->zoom = 1;
	mlx->color = 1;
	mlx->max_iter = 100;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, "fract-ol");
}

void	ft_process_fractal(int set)
{
	t_mlx	mlx;

	init_information(&mlx, set);
	ft_loop_events(&mlx, set);
	ft_choose_fractal(&mlx);
	mlx_loop(mlx.mlx_ptr);
}
