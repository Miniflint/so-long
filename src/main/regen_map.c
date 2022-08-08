/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regen_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:28:28 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/15 04:08:22 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	put_str(t_all *all)
{
	char	*tmp;

	if (all->models->a_move)
	{
		tmp = ft_itoa(all->models->a_move - 1);
		mlx_string_put(all->mlib->mlx, all->mlib->window, all->mlib->x / 2,
			32, 0x000000, tmp);
		free(tmp);
	}
	tmp = ft_itoa(all->models->a_move);
	mlx_string_put(all->mlib->mlx, all->mlib->window, all->mlib->x / 2,
		32, 0xB4D455, tmp);
	free(tmp);
}

void	regen_px_player(t_all *all, int n_pos_x, int n_pos_y)
{
	int		i;
	int		screen_x;
	int		screen_y;

	i = 0;
	screen_x = 0;
	screen_y = 64;
	while (all->mlib->map[i])
	{
		put_str(all);
		if ((n_pos_x == screen_x && n_pos_y == screen_y)
			|| (screen_x == all->models->player_posx
				&& screen_y == all->models->player_posy)
			|| all->mlib->map[i] == 'E')
			big_if(all, screen_x, screen_y, i);
		if (all->mlib->map[i] == '\n')
		{
			screen_x = 0;
			screen_y += 64;
		}
		else
			screen_x += 64;
		i++;
	}
}
