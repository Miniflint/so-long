/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:06:00 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:17:56 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

static void	check_walls(t_all *all, int y)
{
	int	last_line;
	int	i;

	last_line = amount_char_in_str(all->mlib->map, '\n');
	i = 0;
	while (all->mlib->map[i])
	{
		if (y == 0 || y == last_line - 1)
		{
			while (all->mlib->map[i] != '\n' && all->mlib->map[i])
			{
				if (all->mlib->map[i] != '1')
					handle_error("first or last line isn't wall", all);
				i++;
			}
			if (y == last_line - 1)
				break ;
		}
		if (y != last_line && all->mlib->map[i] == '\n')
			if (all->mlib->map[i - 1] != '1' || all->mlib->map[i + 1] != '1')
				handle_error("Missing walls on the side of the map", all);
		if (all->mlib->map[i] == '\n')
			y++;
		i++;
	}
}

void	check_e_c_p(t_all *all)
{
	int	i;

	if (!ft_strchr(all->mlib->path_file, ".ber"))
		handle_error("map name doesn't end with .ber", all);
	i = amount_char_in_str(all->mlib->map, 'E') - 1;
	if (!i)
		handle_error("The map doesn't have an exit", all);
	if (i > 1)
		handle_error("To much exit", all);
	i = amount_char_in_str(all->mlib->map, 'C') - 1;
	if (!i)
		handle_error("The map doesn't have a collectible", all);
	i = amount_char_in_str(all->mlib->map, 'P') - 1;
	if (!i)
		handle_error("The map doesn't have a player", all);
	if (i > 1)
		handle_error("Too much player", all);
	check_walls(all, 0);
}
