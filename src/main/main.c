/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:50:54 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/03 00:02:29 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/solong.h"

void	display_on_screen(char *path_model, t_all *all, int s_x, int s_y)
{
	void	*img;
	int		size_x;
	int		size_y;

	size_x = 64;
	size_y = 64;
	if (!all->mlib->mlx || !path_model)
		handle_error("my fault", all);
	img = mlx_xpm_file_to_image(all->mlib->mlx, path_model, &size_x, &size_y);
	if (!img)
		handle_error("minilibx problem", all);
	mlx_put_image_to_window(all->mlib->mlx, all->mlib->window, img, s_x, s_y);
	mlx_destroy_image(all->mlib->mlx, img);
}

void	big_if(t_all *all, int screen_x, int screen_y, int i)
{
	char	*tmp;

	if (all->mlib->map[i] == '0')
		tmp = ft_strdup(all->models->bg_model);
	else if (all->mlib->map[i] == '1')
		tmp = ft_strdup(all->models->walls_model);
	else if (all->mlib->map[i] == 'C')
		tmp = ft_strdup(all->models->coin_model);
	else if (all->mlib->map[i] == 'E')
		tmp = ft_strdup(all->models->exit_model);
	else if (all->mlib->map[i] == 'P')
	{
		all->models->player_posx = screen_x;
		all->models->player_posy = screen_y;
		tmp = ft_strdup(all->models->player_model);
	}
	else
		tmp = ft_strdup(all->models->missing_model);
	if (!tmp)
	{
		free(tmp);
		handle_error(BLOOPMA, all);
	}
	display_on_screen(tmp, all, screen_x, screen_y);
	free(tmp);
}

void	gen_map(t_all *all)
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

static void	quick_test(t_all *all)
{
	all->mlib->mlx = mlx_init();
	if (!all->mlib->mlx)
		handle_error("Minilibx problem", all);
	all->mlib->mlx_p = 1;
	all->mlib->window = mlx_new_window(all->mlib->mlx, all->mlib->x,
			all->mlib->y, all->mlib->title);
	if (!all->mlib->window)
		handle_error("Minilibx problem", all);
	gen_map(all);
	mlx_key_hook(all->mlib->window, &key_event, all);
	mlx_hook(all->mlib->window, ON_DESTROY, 0, &close_win, all);
	mlx_loop(all->mlib->mlx);
}

int	main(int argc, char *argv[])
{
	t_all	all;

	if (argc != 2)
	{
		write(2, "no map\n", 7);
		exit(1);
	}
	__init__all(&all, argv[1]);
	check_e_c_p(&all);
	check_map_errors(&all);
	quick_test(&all);
	free_all_struct(all.mlib, all.models);
	return (0);
}
