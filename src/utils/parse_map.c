/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:10:30 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/08 21:28:32 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	check_map_errors(t_all *all)
{
	int	i;
	int	j;
	int	len;
	int	size;

	i = 0;
	size = amount_char_in_str(all->mlib->map, '\n');
	while (all->mlib->map[i] != '\n' && all->mlib->map[i])
		i++;
	len = i;
	i = 0;
	while (all->mlib->map[i])
	{
		j = 0;
		while (all->mlib->map[i + j] && all->mlib->map[i + j] != '\n')
			j++;
		if (j != len)
			handle_error(BLIPMAP, all);
		if ((i + j + 1) < size)
			i += j + 1;
		else
			break ;
	}
}

char	*quick_read_map(int fd)
{
	char	*str;
	char	*str_cpy;
	int		rd;
	char	buf[2];

	rd = read(fd, buf, 1);
	buf[1] = 0;
	str = ft_strdup(buf);
	while (rd)
	{
		rd = read(fd, buf, 1);
		buf[1] = 0;
		str_cpy = str;
		str = ft_strjoin(str_cpy, buf);
		free(str_cpy);
		str_cpy = NULL;
	}
	close(fd);
	return (str);
}

char	*read_map(char *path, t_all *all)
{
	char	*rtn;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error("Map does not exists", all);
	rtn = quick_read_map(fd);
	return (rtn);
}
