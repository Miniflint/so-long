/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:09:48 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/17 04:44:19 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

// i[0] = i; : incrementation
// i[1] = c_pos_x; : current position - x | (current position on the map)
// i[2] = c_pos_y; : current position - y | (current position on the map)
// i[3] = old_pos_x; : old position - x | (old position on the map)
// i[4] = old_pos_y; : old position - y | (old position on the map)

int	t_pos_to_map(char *map, t_all *all)
{
	int	i;
	int	x;
	int	y;
	int	max_size_map;

	i = 0;
	x = 0;
	y = 0;
	max_size_map = open(all->mlib->path_file, O_RDONLY);
	while (map[i])
	{
		if (x == all->models->player_posx && y == all->models->player_posy)
			return (i - better_strlen_char(map, '\n'));
		if (map[i] == '\n')
		{
			x = 0;
			y += 64;
		}
		else
			x += 64;
		i++;
	}
	close(max_size_map);
	return (-1);
}

static void	while_loop(t_all *all, int *i, char *m)
{
	while (m[i[0]])
	{
		if (all->models->player_posx == i[1]
			&& all->models->player_posy == i[2])
		{
			if (m[i[0]] == 'C')
				all->models->a_coin--;
			if (m[i[0]] == 'E' && all->models->a_coin == 0)
				close_win(all);
			else
				m[i[0]] = 'P';
		}
		else if (i[3] == i[1] && i[4] == i[2])
			m[i[0]] = '0';
		if (m[i[0]] == '\n')
			increment(&i[1], &i[2]);
		else
			i[1] += 64;
		i[0]++;
	}
}

static void	actualize_map(t_all *all, int old_pos_x, int old_pos_y, char *c_map)
{
	int	i;
	int	c_pos_x;
	int	c_pos_y;
	int	quick_all[5];

	i = 0;
	c_pos_x = 0;
	c_pos_y = 64;
	quick_all[0] = i;
	quick_all[1] = c_pos_x;
	quick_all[2] = c_pos_y;
	quick_all[3] = old_pos_x;
	quick_all[4] = old_pos_y;
	while_loop(all, quick_all, c_map);
	change_images(all);
	all->models->a_move++;
}

static void	check_pos_on_map(t_all *all, int old_pos_X, int old_pos_Y)
{
	int		i;
	int		check_pos;

	i = 0;
	check_pos = t_pos_to_map(all->mlib->map, all);
	if (check_pos == -1 || all->mlib->map[check_pos] == '1'
		|| (all->mlib->map[check_pos] == 'E' && all->models->a_coin != 0))
		return ;
	actualize_map(all, old_pos_X, old_pos_Y, all->mlib->map);
}

void	handle_movement(int button, t_all *all)
{
	int	old_pos_x;
	int	old_pos_y;

	old_pos_x = all->models->player_posx;
	old_pos_y = all->models->player_posy;
	if (button == K_A || button == K_L)
	{
		all->models->rotation = 1;
		all->models->player_posx -= 64;
	}
	if (button == K_D || button == K_R)
	{
		all->models->rotation = 0;
		all->models->player_posx += 64;
	}
	if (button == K_W || button == K_UP)
		all->models->player_posy -= 64;
	if (button == K_S || button == K_DOWN)
		all->models->player_posy += 64;
	check_pos_on_map(all, old_pos_x, old_pos_y);
	return (regen_px_player(all, old_pos_x, old_pos_y));
}
