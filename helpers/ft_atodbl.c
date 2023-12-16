/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:53:41 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/16 17:06:54 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static double	atodbl_part2(char *str, int i, double res, int sign)
{
	int		j;
	double	n;

	if (str[i] == '.')
	{
		j = 10;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		n = str[i] - '0';
		res = res + (n / j);
		j *= 10;
		i++;
	}
	return (res * sign);
}

double	ft_atodbl(char *str)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (atodbl_part2(str, i, res, sign));
}
