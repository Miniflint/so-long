/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:51:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 12:10:42 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

static void	__init__model(t_all *all)
{
	all->models->a_move = 0;
	all->models->player_model = ft_strdup("./assets/player_model.xpm");
	if (!all->models->player_model)
		handle_error(BLOOPMA, all);
	all->models->walls_model = ft_strdup("./assets/wall_model.xpm");
	if (!all->models->walls_model)
		handle_error(BLOOPMA, all);
	all->models->bg_model = ft_strdup("./assets/bg_model.xpm");
	if (!all->models->bg_model)
		handle_error(BLOOPMA, all);
	all->models->missing_model = ft_strdup("./assets/missing_model.xpm");
	if (!all->models->missing_model)
		handle_error(BLOOPMA, all);
	all->models->exit_model = ft_strdup("./assets/closeExit_model.xpm");
	if (!all->models->exit_model)
		handle_error(BLOOPMA, all);
	all->models->coin_model = ft_strdup("./assets/coin_model.xpm");
	if (!all->models->coin_model)
		handle_error(BLOOPMA, all);
}

static void	__init__mlib(t_all *all, char *file_path)
{
	all->mlib->map_p = 0;
	all->mlib->mlx_p = 0;
	all->mlib->title = ft_strdup("Quick game");
	if (!all->mlib->title)
		handle_error(BLOOPMA, all);
	all->mlib->path_file = ft_strdup(file_path);
	if (!all->mlib->path_file)
		handle_error(BLOOPMA, all);
	all->mlib->map = read_map(all->mlib->path_file, all);
	if (!all->mlib->map)
		handle_error(BLOOPMA, all);
	all->mlib->map_p = 1;
	all->mlib->x = ft_strlen_char(all->mlib->map, '\n') * 64;
	all->mlib->y = amount_char_in_str(all->mlib->map, '\n') * 64 + 64;
}

void	__init__all(t_all *all, char *file_path)
{
	all->mlib = (t_mlxWindow *)malloc(sizeof(t_mlxWindow));
	if (!all->mlib)
		handle_error(BLOOPMA, all);
	all->models = (t_model *)malloc(sizeof(t_model));
	if (!all->models)
		handle_error(BLOOPMA, all);
	__init__model(all);
	__init__mlib(all, file_path);
	all->models->a_coin = amount_char_in_str(all->mlib->map, 'C') - 1;
	all->models->a_move = 0;
}
