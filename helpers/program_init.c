/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:17:02 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 16:47:06 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static void	error_exit(void)
{
	ft_printf("Error while establishing the program.\n");
	exit(EXIT_FAILURE);
}

void	program_init(t_program *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		error_exit();
	fractol->win = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT,
			fractol->model);
	if (!fractol->win)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		free(fractol->mlx);
		error_exit();
	}
	fractol->img.obj = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fractol->img.obj)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		free(fractol->mlx);
		error_exit();
	}
	fractol->img.beg_addr = mlx_get_data_addr(fractol->img.obj,
			&fractol->img.bpp,
			&fractol->img.l_len,
			&fractol->img.endian);
	program_events_init(fractol);
	program_data_init(fractol);
}
