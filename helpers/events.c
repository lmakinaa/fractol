/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:09:13 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 17:44:55 by ijaija           ###   ########.fr       */
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

int	scroll_zooming(int button, int x, int y, t_program *fractol)
{
    double zoom_in_factor;
    double zoom_out_factor;
	
	zoom_in_factor = 1.05;
	zoom_out_factor = 0.95;
	(void) x;
	(void) y;
    if (button == 4)
    {
        fractol->zoom_scale *= zoom_in_factor;
   		program_rendering(fractol);
    }
    else if (button == 5)
    {
        fractol->zoom_scale *= zoom_out_factor;
    	program_rendering(fractol);
    }
    return (0);
}

