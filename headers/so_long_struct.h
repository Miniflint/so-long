/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:42:49 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/21 22:42:58 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define CHECK_FF 'F'

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	int				x;
	int				y;
	unsigned int	nb_moves;
}	t_play;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_texture
{
	char	*empty;
	char	*fill;
	char	*player;
	char	*exit;
	char	*item;
}	t_txtr;

typedef struct s_prog
{
	int		fd;
	char	*read;
	char	**map;
	int		size_x;
	int		size_y;
	t_mlx	mlx;
	t_txtr	txtr;
	t_data	img;
	t_play	player;
}	t_prog;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	K_W = 13,
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_UP = 126,
	K_DOWN = 125,
	K_R = 124,
	K_L = 123,
	K_ESC = 53,
	K_Q = 12
};

#endif
