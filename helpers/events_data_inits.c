/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_data_inits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:56:11 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 16:54:21 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	program_data_init(t_program *fractol)
{
	if (!ft_strncmp(fractol->model, "mandelbrot", 10))
		fractol->max_value = 4;
	else if (!ft_strncmp(fractol->model, "julia", 5))
		fractol->max_value = 4;
	fractol->view_x = 0;
	fractol->view_y = 0;
	fractol->zoom_scale = 1.00;
	fractol->max_iter = MAX_ITER;
}

void	program_events_init(t_program *fractol)
{
	mlx_key_hook(fractol->win, key_res, fractol);
	mlx_hook(fractol->win, 17, 1L<<19, closing, fractol);
	mlx_mouse_hook(fractol->win, scroll_zooming, fractol);
	
}
