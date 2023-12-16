/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:40:57 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 18:38:41 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/helpers.h"
#include "string.h"

int	args_check(int argc, char **argv)
{
	if (argc == 1 || argc > 4)
		return (ft_printf(ERROR_MESSAGE));
	else if ((!ft_strcmp("mandelbrot", argv[1])
			|| !ft_strcmp("burning ship", argv[1])) && argc != 2)
		return (ft_printf(ERROR_MESSAGE));
	else if (!ft_strcmp("julia", argv[1]) && argc != 4)
		return (ft_printf(ERROR_MESSAGE));
	if ((ft_strcmp("mandelbrot", argv[1])
			&& ft_strcmp("burning ship", argv[1])) && argc == 2)
		return (ft_printf(ERROR_MESSAGE));
	if (ft_strcmp("julia", argv[1]) && argc == 4)
		return (ft_printf(ERROR_MESSAGE));
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	fractol;

	if (args_check(argc, argv))
		return (0);
	fractol.model = argv[1];
	ft_printf("The %s set fractal is running now..\n", fractol.model);
	if (!ft_strcmp("julia", fractol.model))
	{
		fractol.julia_r = ft_atodbl(argv[2]);
		fractol.julia_i = ft_atodbl(argv[3]);
	}
	program_init(&fractol);
	program_rendering(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
