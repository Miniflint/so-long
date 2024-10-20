#include "so_long.h"

int	check_can_move(char **map, int desired_x, int desired_y)
{
	if (desired_y < 0 || desired_x < 0)
		return (1);
	if (map[desired_y][desired_x] == WALL)
		return (1);
	return (0);
}

int	make_move(char **map, t_play *play, int desired_x, int desired_y)
{
	const int	old_x = play->x;
	const int	old_y = play->y;
	t_prog		*prog;

	prog = __get_prog(NULL);
	if (map[desired_y][desired_x] == EXIT)
	{
		
	}
	map[desired_y][desired_x] = 'P';
	play->x = desired_x;
	play->y = desired_y;
	map[old_y][old_x] = '0';
	play->nb_moves += 1;
	create_texture(&(prog->mlx), prog->txtr.player, desired_x * 64, desired_y * 64);
	create_texture(&(prog->mlx), prog->txtr.empty, old_x * 64, old_y * 64);
	return (0);
}

int	movements(int press, t_prog *prog)
{
	if (press == K_S)
		if (!check_can_move(prog->map, prog->player.x, prog->player.y + 1))
			return (make_move(prog->map, &(prog->player), prog->player.x, prog->player.y + 1));
	if (press == K_W)
		if (!check_can_move(prog->map, prog->player.x, prog->player.y - 1))
			return (make_move(prog->map, &(prog->player), prog->player.x, prog->player.y - 1));
	if (press == K_A)
		if (!check_can_move(prog->map, prog->player.x - 1, prog->player.y))
			return (make_move(prog->map, &(prog->player), prog->player.x - 1, prog->player.y));
	if (press == K_D)
		if (!check_can_move(prog->map, prog->player.x + 1, prog->player.y))
			return (make_move(prog->map, &(prog->player), prog->player.x + 1, prog->player.y));
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
	if (press == K_ESC || press == K_Q)
		close_win(prog);
	return (movements(press, prog));
}

