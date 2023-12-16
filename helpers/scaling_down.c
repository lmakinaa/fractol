/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:09:59 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 18:52:11 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

// double	scaling_down(double unscaled_num, double min,
// 	double max, t_program *fractol)
// {
// 	double	res;
// 	double	new_min;
// 	double	new_max;

// 	new_min = -2 * fractol->zoom_scale;
// 	new_max = 2 * fractol->zoom_scale;
// 	res = (new_max - new_min) * (unscaled_num - min)
// 		/ (max - min) + new_min;
// 	return (res);
// }

double	scaling_down(double unscaled_num, double new_min, double new_max,
	t_program *fractol)
{
	double	res;

	new_min *= fractol->zoom_scale;
	new_max *= fractol->zoom_scale;
	res = (new_max - new_min) * (unscaled_num - 0)
		/ (WIN_HEIGHT - 0) + new_min;
	return (res);
}

double	color_mapping(double unscaled_num, double min, double max)
{
	double	res;
	double	new_min;
	double	new_max;

	new_min = 0;
	new_max = trgb_converter(0, 255, 255, 255);
	res = (new_max - new_min) * (unscaled_num - min)
		/ (max - min) + new_min;
	return (res);
}
