/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:09:13 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/21 20:09:27 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	closing(t_program *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.obj);
	mlx_destroy_window(fractol->mlx, fractol->win);
	ft_printf("Exiting..\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	color_shift(int key, t_program *fractol)
{
	if (key == 8)
	{
		if (fractol->color == trgb_converter(0, 0, 0, 255))
			fractol->color = trgb_converter(0, 0, 255, 0);
		else if (fractol->color == trgb_converter(0, 0, 255, 0))
			fractol->color = trgb_converter(0, 255, 0, 0);
		else if (fractol->color == trgb_converter(0, 255, 0, 0))
			fractol->color = trgb_converter(0, 0, 0, 255);
	}
}

void	zoom_view_reset(int key, t_program *fractol)
{
	if (key == 15)
	{
		fractol->view_x = 0;
		fractol->view_y = 0;
		fractol->min_x = -2;
		fractol->max_x = 2;
		fractol->min_y = -2;
		fractol->max_y = 2;
		fractol->zoom_scale = 1.00;
	}
}

int	key_res(int k, t_program *fractol)
{
	if (k == 53)
	{
		closing(fractol);
		return (0);
	}
	else if (k == 124)
		fractol->view_x += (0.5 * fractol->zoom_scale);
	else if (k == 123)
		fractol->view_x += (-0.5 * fractol->zoom_scale);
	else if (k == 125)
		fractol->view_y += (0.5 * fractol->zoom_scale);
	else if (k == 126)
		fractol->view_y += (-0.5 * fractol->zoom_scale);
	color_shift(k, fractol);
	zoom_view_reset(k, fractol);
	if (k == 124 || k == 123 || k == 125 || k == 126 || k == 8 || k == 15)
		program_rendering(fractol);
	return (0);
}

int	scroll_zooming(int button, int x, int y, t_program *fractol)
{
	double	scaled_x;
	double	scaled_y;

	scaled_x = scaling_down(x, fractol->min_x, fractol->max_x);
	scaled_y = scaling_down(y, fractol->min_y, fractol->max_y);
	if (button == 4)
	{
		fractol->zoom_scale *= 0.87;
		following_the_mouse(scaled_x, scaled_y, 0.87, fractol);
	}
	else if (button == 5)
	{
		fractol->zoom_scale *= 1.13;
		following_the_mouse(scaled_x, scaled_y, 1.13, fractol);
	}
	if (button == 4 || button == 5)
		program_rendering(fractol);
	return (0);
}
