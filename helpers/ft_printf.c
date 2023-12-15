/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:41:20 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/02 18:56:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
va_list (name) to declare a list called (name) so it can be initialised
by the va_start() macro

the second argument of vas_start is used to determine the memory
location of the arguments by locating the last argument before the '...'

va_arg increments the va_list to point to the next argument based on the size
of the specified type, then it gets the value and returns it.

va_end macro indicate the end of processing variable arguments and perform
any required cleanup operations to reset or release any resources related
to va_list.
*/

#include "./../includes/helpers.h"

static int	ft_format(va_list args, char f)
{
	int	count;

	count = 0;
	if (f == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (f == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		count = ft_putnbr(va_arg(args, int), 'd');
	else if (f == 'u')
		count = ft_putnbr(va_arg(args, unsigned int), 'u');
	else if (f == '%')
		count = ft_putchar('%');
	else if (f == 'p')
		count = ft_putaddr(va_arg(args, void *));
	else if (f == 'x')
		count = ft_puthex(va_arg(args, int), "0123456789abcdef");
	else if (f == 'X')
		count = ft_puthex(va_arg(args, int), "0123456789ABCDEF");
	return (count);
}

static int	ft_return_check(const char *str, va_list args, int i)
{
	int	tmp;

	tmp = 0;
	if (str[i] == '%')
	{
		tmp = ft_format(args, str[i + 1]);
		if (tmp < 0)
			return (-1);
		else
			return (tmp);
	}
	else
	{
		if (ft_putchar(str[i]) < 0)
			return (-1);
		else
			return (1);
	}
}

int	ft_printf(const char *mainstr, ...)
{
	int		i;
	int		count;
	int		tmp;
	va_list	args;

	va_start (args, mainstr);
	i = 0;
	count = 0;
	while (mainstr[i])
	{
		tmp = ft_return_check(mainstr, args, i);
		if (mainstr[i] == '%')
			i++;
		if (tmp < 0)
			return (-1);
		else
			count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}
