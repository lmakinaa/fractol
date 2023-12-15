/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbase_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:09:30 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/12 14:24:09 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

size_t	ft_numbase_len(unsigned long long n)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = 16;
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
