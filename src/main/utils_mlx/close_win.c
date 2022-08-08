/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:10:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/10 18:19:24 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/solong.h"

int	close_win(t_all *all)
{
	mlx_destroy_window(all->mlib->mlx, all->mlib->window);
	free_all_struct(all->mlib, all->models);
	write(1, "Closed with success\n", ft_strlen("Closed with success\n"));
	exit(EXIT_SUCCESS);
}
