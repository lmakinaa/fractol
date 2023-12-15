/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:41:39 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/05 16:50:17 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	case_handling(int i, int sign, const char *str)
{
	int			newi;
	long int	nbr;
	long int	res;

	newi = i;
	res = 0;
	while (str[newi] && ft_isdigit(str[newi]))
	{
		nbr = res * 10 + (str[newi] - '0');
		if (res > nbr && sign == 1)
			return (-1);
		else if (res > nbr && sign == -1)
			return (0);
		newi++;
		res = nbr;
	}
	res = (int) res;
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (case_handling(i, sign, str));
}
