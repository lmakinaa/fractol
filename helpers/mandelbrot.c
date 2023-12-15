/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:09:30 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/15 17:22:15 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	mandelbrot(int x, int y, t_program *fractol)
{
	t_comp	c;
	t_comp	z;
	int		i;

	c.r = scaling_down(x, -2, 2, fractol) + fractol->view_x;
	c.i = scaling_down(y, -2, 2, fractol) + fractol->view_y;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < fractol->max_iter)
	{
		z = comp_square(z);
		z.i += c.i;
		z.r += c.r;
		if (z.i * z.i + z.r * z.r > fractol->max_value)
		{
			improved_pixel_put(fractol->img, x, y,
				(i + 3) * trgb_converter(0, 0, 0, 255) / fractol->max_iter);
			return ;
		}
		i++;
	}
	improved_pixel_put(fractol->img, x, y, 0);
}