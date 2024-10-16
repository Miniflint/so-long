#include "so_long.h"

static void	__init_zero(t_prog *prog)
{
	prog->fd = -1;
	prog->file = 0;
	prog->read = 0;
	prog->map = 0;
	prog->size_x = 0;
	prog->size_y = 0;
	prog->mlx.ptr = 0;
	prog->mlx.win = 0;
	prog->img.img = 0;
	prog->img.addr = 0;
	prog->img.bits_per_pixel = 0;
	prog->img.line_length = 0;
	prog->img.endian = 0;
	txtr->fill = 0;
	txtr->exit = 0;
	txtr->item = 0;
	txtr->empty = 0;
	txtr->player = 0;
}

static int	__init_image(t_txtr *txtr)
{
	txtr->fill = ft_strdup("");
	if (!txtr->fill)
		return (1);
	txtr->exit = ft_strdup("");
	if (!txtr->exit)
		return (1);
	txtr->item = ft_strdup("");
	if (!txtr->item)
		return (1);
	txtr->empty = ft_strdup("");
	if (!txtr->empty)
		return (1);
	txtr->player = ft_strdup("");
	if (!txtr->player)
		return (1);
	return (0);
}

static int	__init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (handle_things(5));
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, WIN_NAME);
	if (!mlx->win)
		return (handle_things(6));
	return (0);
}

int	__init_struct(t_prog *prog, char *file)
{
	__init_zero(prog);
	if (get_ext_name(file))
		return (handle_things(1));
	prog->file = file;
	prog->fd = open(file, O_RDONLY);
	if (prog->fd == -1)
		return (handle_things(2));
	prog->read = quick_read_map(prog->fd);
	close(prog->fd);
	if (!prog->read || !prog->read[0])
		return (handle_things(3));
	if (map_valid_pei(prog->read))
		return (1);
	prog->map = fast_split(prog->read);
	if (!prog->map)
		return (handle_things(4));
	if (__init_mlx(&(prog->mlx)))
		return (1);
	if (map_valid_height_width(prog))
		return (1);
	if (map_valid_walls_rect(prog->map, prog->size_x, prog->size_y))
		return (1);
	return (0);
}
