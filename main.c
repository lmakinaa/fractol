/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:40:57 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 16:47:02 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/helpers.h"

int	main(int argc, char **argv)
{
	t_program fractol;

	if (argc != 2)
		return (ft_printf("Usage: ./fractol [fractal name]\n"));
	if (ft_strncmp(argv[1], "mandelbrot", 10))
		return (ft_printf("Usage: ./fractol [mandelbrot or julia]\n"));
	fractol.model = argv[1];
	program_init(&fractol);
	program_rendering(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}