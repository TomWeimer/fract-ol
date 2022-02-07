/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:11:26 by tweimer           #+#    #+#             */
/*   Updated: 2022/02/04 16:49:05 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"
#include "../../libft/libft.h"

void	ft_no_valid_set(void)
{
	write(1, "\nPlease choose between these sets:", 35);
	write(1, "\n\t- Mandelbrot", 15);
	write(1, "\n\t- Julia\n", 11);
	return ;
}

int	ft_check_input(char *argv[], int *set)
{
	if (ft_strcmp(argv[1], "Mandelbrot"))
		*set = 1;
	else if (ft_strcmp(argv[1], "Julia"))
		*set = 2;
	else
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	set;

	set = 0;
	if (argc != 2 || ft_check_input(argv, &set) == 1)
	{
		ft_no_valid_set();
		exit(1);
	}
	ft_process_fractal(set);
}
