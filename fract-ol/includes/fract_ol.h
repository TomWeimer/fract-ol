/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:45:29 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:55:39 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <math.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	zoom;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int		width;
	int		height;
	double	x;
	double	y;
	int		max_iter;
	int		set;
	int		color;
}	t_mlx;

typedef struct s_data
{
	void	*ptr;
	char	*buff;
	int		bpp;
	int		line;
	int		argb;
	int		color;
	int		width;
	int		height;
}	t_data;

typedef struct s_complex
{
	double	i;
	double	r;
	double	r2;
	double	i2;
}	t_complex;

typedef struct s_iter
{
	double		i;
	t_complex	z;
	t_complex	c;
	int			max_iter;
}t_iter;

typedef struct s_RGB
{
	double	r;
	double	g;
	double	b;
}t_RGB;
int		ft_check_input(char *argv[], int *set);
void	ft_process_fractal(int set);
int		ft_choose_fractal(t_mlx *mlx);
void	ft_loop_events(t_mlx *mlx, int set);
void	ft_julia(t_mlx *mlx);
void	ft_mandelbrot(t_mlx *mlx);
void	start_julia(t_mlx *mlx);
void	start_mandel(t_mlx *mlx);
t_iter	julia_iter(t_complex c, t_mlx *mlx);
t_iter	mandel_iter(t_complex c, t_mlx *mlx);
int		get_pixel_color(t_iter p, t_mlx *mlx);
void	ft_no_valid_set(void);
int		ft_check_input(char *argv[], int *set);
int		mouse_zoom(int button, int x, int y, t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx *mlx);
void	draw_fractal(t_mlx *mlx, t_data *image, t_complex constante);
int		key_down(int keycode, t_mlx *mlx);
int		ft_rgb(double r, double g, double b);
int		ft_hsv_2_argb(double h, double S, double V);
int		ft_color(int color1, t_iter p, t_mlx *mlx);
#endif