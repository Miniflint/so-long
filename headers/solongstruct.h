/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solongstruct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:27:59 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 12:09:16 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONGSTRUCT_H
# define SOLONGSTRUCT_H

typedef struct S_model
{
	char		*player_model;
	char		*bg_model;
	char		*walls_model;
	char		*item_model;
	char		*exit_model;
	char		*coin_model;
	char		*missing_model;
	int			player_posx;
	int			player_posy;
	int			a_move;
	int			a_coin;
	int			rotation;
}	t_model;

typedef struct S_mlxWindow
{
	char	*title;
	int		x;
	int		y;
	void	*mlx;
	void	*window;
	char	*path_file;
	char	*map;
	int		map_p;
	int		mlx_p;
}	t_mlxWindow;

typedef struct S_all
{
	t_model		*models;
	t_mlxWindow	*mlib;
}	t_all;

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