/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 09:39:49 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:17:59 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

static int	len_helper(unsigned int len)
{
	if (len >= 1000000000)
		return (10);
	else if (len >= 100000000)
		return (9);
	else if (len >= 10000000)
		return (8);
	else if (len >= 1000000)
		return (7);
	else if (len >= 100000)
		return (6);
	else if (len >= 10000)
		return (5);
	else if (len >= 1000)
		return (4);
	else if (len >= 100)
		return (3);
	else if (len >= 10)
		return (2);
	return (1);
}

static char	*ft_conv(unsigned long n, char *array, int x)
{
	array[x] = '\0';
	while (n >= 0)
	{
		x--;
		array[x] = (n % 10) + '0';
		if (n < 10)
			break ;
		n = n / 10;
	}
	return (array);
}

char	*ft_itoa(unsigned long int n)
{
	char	*array;
	int		x;
	long	get_n;

	get_n = n;
	array = malloc(sizeof(char) * (len_helper(n) + 1));
	if (!array)
		return (NULL);
	x = len_helper(get_n);
	array = ft_conv(get_n, array, x);
	if (!array)
		return (NULL);
	return (array);
}
