/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:17:12 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:18:11 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (n <= 0 || n >= 4294967295)
		return (dst);
	else
	{
		while (x < n)
		{
			((char *)dst)[x] = ((char *)src)[x];
			x++;
		}
		return (dst);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	src_size;

	src_size = ft_strlenc(src);
	if (src_size + 1 < n)
	{
		ft_memcpy(dst, src, src_size + 1);
		dst[n - 1] = '\0';
	}
	else if (n == 0)
	{
		ft_memcpy(dst, src, 0);
		return (src_size);
	}
	else if (src_size != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = '\0';
	}
	return (src_size);
}
