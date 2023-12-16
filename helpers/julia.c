/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:59:20 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 18:48:45 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	julia(int x, int y, t_program *fractol)
{
	t_comp	c;
	t_comp	z;
	int		i;

	z.r = scaling_down(x, -2, 2, fractol) + fractol->view_x;
	z.i = scaling_down(y, -2, 2, fractol) + fractol->view_y;
	c.r = fractol->julia_r;
	c.i = fractol->julia_i;
	i = 0;
	while (i < fractol->max_iter)
	{
		z = comp_square(z);
		z.i += c.i;
		z.r += c.r;
		if (z.i * z.i + z.r * z.r > fractol->max_value)
		{
			improved_pixel_put(fractol->img, x, y,
				(i + 3) * fractol->color / fractol->max_iter);
			return ;
		}
		i++;
	}
	improved_pixel_put(fractol->img, x, y, 0);
}
