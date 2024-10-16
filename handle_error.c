#include "so_long.h"

int	handle_nea(char *prog)
{
	ft_putstr("Error: Not enough arguments\n");
	ft_putstr("\tUsage: ");
	ft_putstr(prog);
	ft_putstr(" [map].ber\n");
	return (1);
}

int	handle_ws(char *str)
{
	ft_putstr("Error:\n");
	ft_putstr(str);
	ft_putstr("\n");
	return (1);
}

int	handle_things(int code)
{
	ft_putstr("Error:\n");
	if (code == 1)
		ft_putstr("Wrong extension name\n");
	if (code == 2)
		ft_putstr("Could not open the file\n");
	if (code == 3)
		ft_putstr("Malloc error somehow\n");
	if (code == 4)
		ft_putstr("Parsing not possible\n");
	if (code == 5)
		ft_putstr("Could not initialize mlx ptr\n");
	if (code == 6)
		ft_putstr("Could not initialize mlx window\n");
	return (1);
}
