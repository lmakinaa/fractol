/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:08:14 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/13 18:34:27 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	improved_pixel_put(t_imgdata img, int x, int y, int color)
{
	char	*dst;

	dst = img.beg_addr + ((y * img.l_len) + (x * (img.bpp / 8)));
	*(unsigned int *) dst = color;
}
