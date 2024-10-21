/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:35:05 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/21 22:35:53 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_prog	*__get_prog(t_prog *prog)
{
	static t_prog	*static_prog;

	if (prog)
		static_prog = prog;
	return (static_prog);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = 0;
	return (new_str);
}

int	get_len_backslash(char *str)
{
	int	nb;

	nb = 0;
	if (*str == '\n')
		return (nb);
	while (*str)
	{
		if (*str == '\n' && *(str + 1) && *(str + 1) == '\n')
			return (0);
		if (*str == '\n')
			nb++;
		str++;
	}
	return (nb + 1);
}

char	**fast_split(char *str)
{
	int		i;
	char	**ret;

	i = get_len_backslash(str);
	if (!i)
		return (NULL);
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str && *str == '\n')
		{
			*str = 0;
			str++;
		}
		if (*str)
			ret[i++] = str;
		while (*str && *str != '\n')
			str++;
	}
	ret[i] = 0;
	return (ret);
}
