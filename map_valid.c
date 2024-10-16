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
		else if (*map == PLAYER && player > 0)
			return (handle_ws("Too many players. 1 max allowed"));
		else if (*map == PLAYER)
			player++;
		else if (*map == EXIT)
			exit++;
		else if (*map != WALL && *map != EMPTY && *map != '\n')
			return (handle_ws("Unknown char"));
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

int map_valid_height_width(t_prog *prog)
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
