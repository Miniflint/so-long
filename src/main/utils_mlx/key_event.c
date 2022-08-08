/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:53:29 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/15 03:59:18 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/solong.h"

int	key_event(int button, t_all *all)
{
	if (button == K_ESC || button == K_Q)
		close_win(all);
	else
		handle_movement(button, all);
	return (1);
}
