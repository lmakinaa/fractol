/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:09:13 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 18:42:35 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	closing(t_program *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.obj);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	ft_printf("Exiting..\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	color_shift(int key, t_program *main)
{
	if (key == 8)
	{
		if (main->color == trgb_converter(0, 0, 0, 255))
			main->color = trgb_converter(0, 0, 255, 0);
		else if (main->color == trgb_converter(0, 0, 255, 0))
			main->color = trgb_converter(0, 255, 0, 0);
		else if (main->color == trgb_converter(0, 255, 0, 0))
			main->color = trgb_converter(0, 0, 0, 255);
	}
}

int	key_res(int key, t_program *main)
{
	if (key == 53)
	{
		closing(main);
		return (0);
	}
	else if (key == 124)
		main->view_x += (0.5 * main->zoom_scale);
	else if (key == 123)
		main->view_x += (-0.5 * main->zoom_scale);
	else if (key == 125)
		main->view_y += (0.5 * main->zoom_scale);
	else if (key == 126)
		main->view_y += (-0.5 * main->zoom_scale);
	color_shift(key, main);
	if (key == 124 || key == 123 || key == 125 || key == 126 || key == 8)
		program_rendering(main);
	return (0);
}

int	scroll_zooming(int button, int x, int y, t_program *fractol)
{
	(void) x;
	(void) y;
	if (button == 4)
		fractol->zoom_scale *= 0.95;
	else if (button == 5)
		fractol->zoom_scale *= 1.05;
	if (button == 4 || button == 5)
		program_rendering(fractol);
	return (0);
}
