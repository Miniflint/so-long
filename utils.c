#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	get_player_pos(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == PLAYER)
			{
				prog->player.x = j;
				prog->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**cpy_map(char **map, int size_y)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (size_y + 1));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = 0;
	return (new_map);
}
