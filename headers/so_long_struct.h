#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

# define WIDTH 1920
# define HEIGHT 1080
# define WIN_NAME "this is a window name"

# define ITEM 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define WALL '1'
# define EMPTY '0'

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct	s_texture
{
	char	*empty;
	char	*fill;
	char	*player;
	char	*exit;
	char	*item;
}	t_txtr;

typedef struct	s_prog
{
	int		fd;
	char	*file;
	char	*read;
	char	**map;
	int		size_x;
	int		size_y;
	t_mlx	mlx;
	t_data	img;
}	t_prog;

#endif
