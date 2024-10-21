/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:35:57 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/21 22:37:31 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_ext_name(char *filename)
{
	int	i;

	if (!filename)
		return (1);
	i = ft_strlen(filename);
	if (i <= 4)
		return (1);
	i -= 4;
	if (filename[i++] != '.')
		return (1);
	if (filename[i++] != 'b')
		return (1);
	if (filename[i++] != 'e')
		return (1);
	if (filename[i++] != 'r')
		return (1);
	return (0);
}

int	map_valid_pei(char *map)
{
	int	item;
	int	player;
	int	exit;

	item = 0;
	player = 0;
	exit = 0;
	while (*map)
	{
		if (*map == ITEM)
			item++;
		else if (*map == PLAYER)
			player++;
		else if (*map == EXIT)
			exit++;
		else if (validate_ifs(*map, player, exit))
			return (1);
		map++;
	}
	if (!item || !player || !exit)
		return (handle_ws("Missing player || item || exit"));
	return (0);
}

int	map_valid_walls_rect(char **map, int m_x, int m_y)
{
	int	i;

	i = 0;
	while (i < m_x)
	{
		if (map[0][i] != WALL)
			return (handle_ws("First row is not walls"));
		if (map[m_y - 1][i] != WALL)
			return (handle_ws("Last row is not walls"));
		i++;
	}
	i = 0;
	while (i < m_y)
	{
		if (map[i][0] != WALL)
			return (handle_ws("First column is not walls"));
		if (map[i][m_x - 1] != WALL)
			return (handle_ws("Last column is not walls"));
		i++;
	}
	return (0);
}

int	map_valid_height_width(t_prog *prog)
{
	int	i;
	int	size_x;
	int	old_size;

	size_x = 0;
	size_x = ft_strlen(prog->map[0]);
	i = 1;
	while (prog->map[i])
	{
		old_size = size_x;
		size_x = ft_strlen(prog->map[i]);
		if (old_size != size_x)
			return (handle_ws("Map is not rectangular"));
		i++;
	}
	prog->size_y = i;
	prog->size_x = size_x;
	return (0);
}

void	map_valid_path(char **map, int curr_x, int curr_y, int *found)
{
	if (*found || curr_x < 0 || curr_y < 0
		|| !map || !map[curr_y] || !map[curr_y][curr_x])
		return ;
	if (map[curr_y][curr_x] == CHECK_FF || map[curr_y][curr_x] == WALL)
		return ;
	if (map[curr_y][curr_x] == EXIT)
		*found = 1;
	if (*found)
		return ;
	map[curr_y][curr_x] = CHECK_FF;
	if (map[curr_y][curr_x + 1])
		map_valid_path(map, curr_x + 1, curr_y, found);
	if (map[curr_y][curr_x - 1])
		map_valid_path(map, curr_x - 1, curr_y, found);
	if (map[curr_y + 1][curr_x])
		map_valid_path(map, curr_x, curr_y + 1, found);
	if (map[curr_y - 1][curr_x])
		map_valid_path(map, curr_x, curr_y - 1, found);
	return ;
}
