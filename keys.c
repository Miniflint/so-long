/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:27:03 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/22 17:53:21 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_can_move(char **map, int desired_x, int desired_y)
{
	if (desired_y < 0 || desired_x < 0)
		return (1);
	if (map[desired_y][desired_x] == WALL)
		return (1);
	if (map[desired_y][desired_x] == EXIT
		&& __get_prog(NULL)->player.nb_items != 0)
		return (1);
	if (map[desired_y][desired_x] == ITEM
		&& __get_prog(NULL)->player.nb_items == 1)
	{
		free(__get_prog(NULL)->txtr.exit);
		__get_prog(NULL)->txtr.exit
			= ft_strdup("./assets/openExit_model.xpm");
	}
	return (0);
}

int	make_move(char **map, t_play *play, int desired_x, int desired_y)
{
	const int	old_x = play->x;
	const int	old_y = play->y;
	t_prog		*prog;

	prog = __get_prog(NULL);
	if (map[desired_y][desired_x] == ITEM)
	{
		create_texture(&(prog->mlx), prog->txtr.exit,
			prog->exit_x * 64, prog->exit_y * 64);
		play->nb_items -= 1;
	}
	if (map[desired_y][desired_x] == EXIT)
		return (2);
	map[desired_y][desired_x] = PLAYER;
	play->x = desired_x;
	play->y = desired_y;
	map[old_y][old_x] = EMPTY;
	play->nb_moves += 1;
	create_texture(&(prog->mlx), prog->txtr.player,
		desired_x * 64, desired_y * 64);
	create_texture(&(prog->mlx), prog->txtr.empty,
		old_x * 64, old_y * 64);
	ft_putnbr(play->nb_moves);
	write(1, "\n", 1);
	return (0);
}

int	movements(int press, t_prog *prog)
{
	if (press == K_S || press == K_DOWN)
		if (!check_can_move(prog->map, prog->player.x, prog->player.y + 1))
			return (make_move(prog->map, &(prog->player),
					prog->player.x, prog->player.y + 1));
	if (press == K_W || press == K_UP)
		if (!check_can_move(prog->map, prog->player.x, prog->player.y - 1))
			return (make_move(prog->map, &(prog->player),
					prog->player.x, prog->player.y - 1));
	if (press == K_A || press == K_L)
		if (!check_can_move(prog->map, prog->player.x - 1, prog->player.y))
			return (make_move(prog->map, &(prog->player),
					prog->player.x - 1, prog->player.y));
	if (press == K_D || press == K_R)
		if (!check_can_move(prog->map, prog->player.x + 1, prog->player.y))
			return (make_move(prog->map, &(prog->player),
					prog->player.x + 1, prog->player.y));
	return (1);
}

int	close_win(t_prog *prog)
{
	mlx_destroy_window(prog->mlx.ptr, prog->mlx.win);
	free_all(prog);
	ft_putstr("Program closed successfully\n");
	exit(0);
}

int	key_event(int press, void *a)
{
	t_prog	*prog;

	prog = (t_prog *)a;
	if (press == K_ESC || press == K_Q || movements(press, prog) == 2)
		close_win(prog);
	return (0);
}
