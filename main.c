#include "so_long.h"

int	free_all(t_prog *prog)
{
	if (prog->read)
		free(prog->read);
	if (prog->map)
		free(prog->map);
	if (prog->txtr.fill)
		free(prog->txtr.fill);
	if (prog->txtr.exit)
		free(prog->txtr.exit);
	if (prog->txtr.item)
		free(prog->txtr.item);
	if (prog->txtr.empty)
		free(prog->txtr.empty);
	if (prog->txtr.player)
		free(prog->txtr.player);
	return (1);
}

int main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 2)
		return (handle_nea(argv[0]));
	if (__init_struct(&prog, argv[1]))
		return (free_all(&prog));
	win_handle(&prog);
	free_all(&prog);
	return (0);
}
