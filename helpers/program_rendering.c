/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:54:22 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 18:14:09 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	program_rendering(t_program *fractol)
{
	int	x;
	int	y;
	int	model;

	y = 0;
	if (!ft_strncmp(fractol->model, "mandelbrot", 10))
		model = 1;
	else if (!ft_strncmp(fractol->model, "julia", 5))
		model = 2;
	else if (!ft_strncmp(fractol->model, "burning ship", 5))
		model = 3;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (model == 1)
				mandelbrot(x, y, fractol);
			else if (model == 2)
				julia(x, y, fractol);
			else if (model == 3)
				burning_ship(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.obj, 0, 0);
}