/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:39:14 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:18:24 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	increment(int *pos_x, int *pos_y)
{
	*pos_x = 0;
	*pos_y += 64;
}

void	old_pos(t_all *all, int old_pos_x, int old_pos_y, int *d)
{
	all->models->player_posx = old_pos_x;
	all->models->player_posy = old_pos_y;
	*d -= 1;
}
