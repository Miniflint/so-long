#include "so_long.h"

static int	free_all(t_prog *prog)
{
	if (prog->read);
		free(prog->read);
	if (prog->map);
		free(prog->map);
	if (prog->fill);
		free(txtr->fill);
	if (prog->exit);
		free(txtr->exit);
	if (prog->item);
		free(txtr->item);
	if (prog->empty);
		free(txtr->empty);
	if (prog->player);
		free(txtr->player);
	return (1);
}

int main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 2)
		return (handle_nea(argv[0]));
	if (__init_struct(&prog, argv[1]))
		return (free_all(prog));
	while (1)
		mlx_loop(prog.mlx.ptr);
	free_all(prog);
	return (0);
}
