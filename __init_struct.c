/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:29:21 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/22 17:42:42 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	__init_zero(t_prog *prog)
{
	prog->fd = -1;
	prog->read = 0;
	prog->map = 0;
	prog->size_x = 0;
	prog->size_y = 0;
	prog->exit_x = 0;
	prog->exit_y = 0;
	prog->mlx.ptr = 0;
	prog->mlx.win = 0;
	prog->mlx.win_width = 0;
	prog->mlx.win_height = 0;
	prog->img.img = 0;
	prog->img.addr = 0;
	prog->img.bits_per_pixel = 0;
	prog->img.line_length = 0;
	prog->img.endian = 0;
	prog->txtr.fill = 0;
	prog->txtr.exit = 0;
	prog->txtr.item = 0;
	prog->txtr.empty = 0;
	prog->txtr.player = 0;
	prog->player.x = 0;
	prog->player.y = 0;
	prog->player.nb_moves = 0;
	prog->player.nb_items = 0;
}

static int	__init_textures(t_txtr *txtr)
{
	txtr->fill = ft_strdup("./assets/wall_model.xpm");
	if (!txtr->fill)
		return (handle_things(3));
	txtr->exit = ft_strdup("./assets/closeExit_model.xpm");
	if (!txtr->exit)
		return (handle_things(3));
	txtr->item = ft_strdup("./assets/coin_model.xpm");
	if (!txtr->item)
		return (handle_things(3));
	txtr->empty = ft_strdup("./assets/bg_model.xpm");
	if (!txtr->empty)
		return (handle_things(3));
	txtr->player = ft_strdup("./assets/player_model.xpm");
	if (!txtr->player)
		return (handle_things(3));
	return (0);
}

static int	__init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (handle_things(5));
	mlx->win = mlx_new_window(mlx->ptr, mlx->win_width,
			mlx->win_height, WIN_NAME);
	if (!mlx->win)
		return (handle_things(6));
	return (0);
}

static int	check_map_valid(t_prog *prog)
{
	int		found;
	char	**cpy;

	if (map_valid_pei(prog->read))
		return (1);
	prog->map = fast_split(prog->read);
	if (!prog->map)
		return (handle_things(4));
	if (map_valid_height_width(prog))
		return (1);
	if (map_valid_walls_rect(prog->map, prog->size_x, prog->size_y))
		return (1);
	cpy = cpy_map(prog->map, prog->size_y);
	if (!cpy)
		return (handle_things(3));
	get_player_pos(prog);
	found = 0;
	map_valid_path(cpy, prog->player.x, prog->player.y, &found);
	if (!found)
		return (handle_ws("Could not find a valid path"));
	free_2d_array(cpy);
	return (0);
}

int	__init_struct(t_prog *prog, char *file)
{
	__init_zero(prog);
	prog = __get_prog(prog);
	if (get_ext_name(file))
		return (handle_things(1));
	prog->fd = open(file, O_RDONLY);
	if (prog->fd == -1)
		return (handle_things(2));
	prog->read = quick_read_map(prog->fd);
	close(prog->fd);
	if (!prog->read || !prog->read[0])
		return (handle_things(3));
	if (check_map_valid(prog))
		return (1);
	if (__init_textures(&(prog->txtr)))
		return (1);
	prog->mlx.win_width = prog->size_x * 64;
	prog->mlx.win_height = prog->size_y * 64;
	if (__init_mlx(&(prog->mlx)))
		return (1);
	return (0);
}
