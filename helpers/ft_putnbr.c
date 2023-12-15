/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:09:14 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/02 18:56:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static void	ft_countdigits(long long n, int *res)
{
	if (n < 0)
	{
		(*res)++;
		n *= -1;
	}
	if (n / 10)
		ft_countdigits(n / 10, res);
	(*res)++;
}

static void	ft_revsort(char *str, int size)
{
	int		i;
	char	c;

	i = 0;
	if (str[0] == '-')
		i = i + 1;
	size = size - 1;
	while (i < size + 1)
	{
		c = str[i];
		str[i] = str[size];
		str[size] = c;
		i++;
		size--;
	}
}

static void	copying(char *res, int size, long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		i++;
	}
	while (i < size)
	{
		res[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	ft_revsort(res, size);
	res[i] = '\0';
}

static char	*ft_itoa(long long n)
{
	int		size;
	char	*res;

	size = 0;
	ft_countdigits(n, &size);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	copying(res, size, n);
	return (res);
}

int	ft_putnbr(long long n, char format)
{
	char	*str;
	int		i;

	if (format == 'u' && n < 0)
		str = ft_itoa(n % 4294967295);
	else
		str = ft_itoa(n);
	if (!str)
		return (-1);
	i = ft_putstr(str);
	free(str);
	return (i);
}
