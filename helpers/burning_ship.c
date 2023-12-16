/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:06:29 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 18:38:54 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	burning_ship(int x, int y, t_program *fractol)
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
		z.i = fabs(z.i);
		z.r = fabs(z.r);
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
