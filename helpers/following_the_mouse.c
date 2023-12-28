/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   following_the_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:09:37 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/21 20:09:57 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	following_the_mouse(double scaled_x, double scaled_y, double zoom_scale,
	t_program *fractol)
{
	fractol->min_x = scaled_x + zoom_scale * (fractol->min_x - scaled_x);
	fractol->max_x = scaled_x + zoom_scale * (fractol->max_x - scaled_x);
	fractol->min_y = scaled_y + zoom_scale * (fractol->min_y - scaled_y);
	fractol->max_y = scaled_y + zoom_scale * (fractol->max_y - scaled_y);
}
