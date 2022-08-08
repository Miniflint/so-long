/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:54:19 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:17:42 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	change_images(t_all *all)
{
	if (all->models->a_coin == 0)
	{
		free(all->models->exit_model);
		all->models->exit_model = ft_strdup("./assets/openExit_model.xpm");
	}
	if (all->models->rotation)
	{
		free(all->models->player_model);
		all->models->player_model = ft_strdup("./assets/rplayer_model.xpm");
	}
	else
	{
		free(all->models->player_model);
		all->models->player_model = ft_strdup("./assets/player_model.xpm");
	}
	if (!all->models->player_model || !all->models->exit_model)
		handle_error(BLOOPMA, all);
}
