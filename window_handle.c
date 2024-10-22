/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:37:54 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/22 17:56:03 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_texture(t_mlx *mlx, char *model_path, int coord_x, int coord_y)
{
	int		m_x;
	int		m_y;
	void	*img;

	m_x = 64;
	m_y = 64;
	if (!model_path)
		return (handle_ws("tf happened here ?"));
	img = mlx_xpm_file_to_image(mlx->ptr, model_path, &m_x, &m_y);
	if (!img)
		return (handle_ws("Could not load the image"));
	mlx_put_image_to_window(mlx->ptr, mlx->win, img, coord_x, coord_y);
	mlx_destroy_image(mlx->ptr, img);
	return (0);
}

static int	big_if(t_prog *prog, char c, int coord_x, int coord_y)
{
	if (c == WALL)
		if (create_texture(&(prog->mlx), prog->txtr.fill, coord_x, coord_y))
			return (1);
	if (c == PLAYER)
		if (create_texture(&(prog->mlx), prog->txtr.player, coord_x, coord_y))
			return (1);
	if (c == EXIT)
		if (create_texture(&(prog->mlx), prog->txtr.exit, coord_x, coord_y))
			return (1);
	if (c == EMPTY)
		if (create_texture(&(prog->mlx), prog->txtr.empty, coord_x, coord_y))
			return (1);
	if (c == ITEM)
		if (create_texture(&(prog->mlx), prog->txtr.item, coord_x, coord_y))
			return (1);
	return (0);
}

int	create_all_textures(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (big_if(prog, prog->map[i][j], j * 64, i * 64))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	win_handle(t_prog *prog)
{
	if (create_all_textures(prog))
		return ;
	mlx_key_hook(prog->mlx.win, &key_event, prog);
	mlx_hook(prog->mlx.win, ON_DESTROY, 0, &close_win, prog);
	mlx_loop(prog->mlx.ptr);
	return ;
}
