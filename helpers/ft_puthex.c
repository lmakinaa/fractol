/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:13:23 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/02 18:56:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bzero is necessary because it is the one who put the \0s
//for the end of the string

#include "./../includes/helpers.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

int	ft_puthex(unsigned int n, char *base)
{
	int		numlen;
	char	*str;
	int		count;

	numlen = ft_numbase_len(n);
	str = ft_calloc((numlen + 1), sizeof(char));
	if (!str)
		return (-1);
	while (numlen > 0)
	{
		numlen--;
		str[numlen] = base[n % 16];
		n /= 16;
	}
	count = ft_putstr(str);
	free(str);
	return (count);
}
