/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:09:13 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 17:55:06 by ijaija           ###   ########.fr       */
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


int scroll_zooming(int button, int x, int y, t_program *fractol)
{
	double prev_scale = fractol->zoom_scale;
	double zoom_factor = 0.05;

	if (button == 4)
		fractol->zoom_scale *= (1 - zoom_factor);
	else if (button == 5)
		fractol->zoom_scale *= (1 + zoom_factor);

	// Adjust the view position based on the mouse position
	double mouse_x = (double)x / WIN_WIDTH;
	double mouse_y = (double)y / WIN_HEIGHT;
	fractol->view_x += (mouse_x - 0.5) * (prev_scale - fractol->zoom_scale);
	fractol->view_y += (mouse_y - 0.5) * (prev_scale - fractol->zoom_scale);

	// ft_printf("x-->%d | y-->%d\n", x, y); 
	program_rendering(fractol);
	return (0);
}



