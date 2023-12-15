/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:09:13 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 16:47:30 by ijaija           ###   ########.fr       */
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
	program_rendering(main);
	return (0);
}

