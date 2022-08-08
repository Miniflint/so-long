/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:19:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:18:02 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

int	ft_strchr(char *str, char *srch)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == srch[j])
		{
			if (!srch[j])
				return (1);
			i++;
			j++;
		}
		i++;
	}
	return (0);
}
