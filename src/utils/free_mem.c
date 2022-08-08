/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 05:03:48 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 12:09:18 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	free_and_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_models(t_model *models)
{
	if (models)
	{
		if (models->bg_model)
			free_and_null(&models->bg_model);
		if (models->player_model)
			free_and_null(&models->player_model);
		if (models->walls_model)
			free_and_null(&models->walls_model);
		if (models->exit_model)
			free_and_null(&models->exit_model);
		if (models->missing_model)
			free_and_null(&models->missing_model);
		free(models);
	}
}

void	free_mlib(t_mlxWindow *mlib)
{
	int	fd;

	fd = open(mlib->path_file, O_RDONLY);
	if (mlib)
	{
		free_and_null(&mlib->title);
		if (mlib->path_file)
			free_and_null(&mlib->path_file);
		if (fd > 0)
		{
			if (mlib->map_p)
				free_and_null(&mlib->map);
			if (mlib->mlx_p)
			{
				free(mlib->mlx);
				mlib->mlx = NULL;
			}
		}
		close(fd);
		free(mlib);
	}
}

void	free_all_struct(t_mlxWindow *mlib, t_model *models)
{
	free_models(models);
	free_mlib(mlib);
}
