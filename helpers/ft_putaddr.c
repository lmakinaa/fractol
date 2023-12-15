/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:37:35 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/02 18:56:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static void	number_printing(char c, int *count)
{
	if (write(1, &c, 1) < 0)
		(*count) = -1;
	else
		(*count)++;
}

static void	addr_printing(unsigned long n, char *base, int baselen, int *count)
{
	if (n / baselen && *count != -1)
		addr_printing(n / baselen, base, baselen, count);
	number_printing(base[n % baselen], count);
}

int	ft_putaddr(void *ptr)
{
	unsigned long	numptr;
	int				count;

	count = 0;
	count += ft_putstr("0x");
	if (count < 0)
		return (-1);
	numptr = (unsigned long) ptr;
	addr_printing(numptr, "0123456789abcdef", 16, &count);
	return (count);
}
