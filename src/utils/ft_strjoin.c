/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:13:51 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:18:06 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	char	*cpy;

	x = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	cpy = (char *)malloc(sizeof(char *) * ft_strlenc(s1) + ft_strlenc(s2) + 1);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, ft_strlenc(s1) + 1);
	ft_strlcat(cpy, s2, ft_strlenc(s1) + ft_strlenc(s2) + 1);
	return (cpy);
}
