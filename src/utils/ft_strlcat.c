/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:16:41 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:18:09 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlenc(src);
	if (n <= len_d)
		return (n + len_s);
	i = 0;
	while (dst[i] && i < n - 1)
		i++;
	while (*src && i < n - 1)
		dst[i++] = *(src++);
	dst[i] = '\0';
	return (len_d + len_s);
}
