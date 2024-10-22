/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgoel <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:41:00 by trgoel            #+#    #+#             */
/*   Updated: 2024/10/22 17:23:29 by trgoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "mlx.h"
# include "so_long_struct.h"

// GRAPH
void	win_handle(t_prog *prog);
int		close_win(t_prog *prog);
int		key_event(int press, void *a);

int		create_texture(t_mlx *mlx, char *model_path,
			int coord_x, int coord_y);
int		create_all_textures(t_prog *prog);

int		movements(int press, t_prog *prog);

// UTILS
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	get_player_pos(t_prog *prog);

char	**cpy_map(char **map, int size_y);
void	free_2d_array(char **map);
void	ft_putnbr(unsigned int u);

t_prog	*__get_prog(t_prog *prog);

// malloc utils
char	*ft_strdup(char *str);
char	**fast_split(char *str);
int		get_len_backslash(char *str);
char	*ft_strjoin(char *s1, char *s2);

char	*quick_read_map(int fd);

// handle errors
int		handle_ws(char *str);
int		handle_nea(char *prog);
int		handle_things(int code);

// check map valid
int		map_valid_pei(char *map);
int		get_ext_name(char *filename);
int		map_valid_height_width(t_prog *prog);
int		validate_ifs(char map, int player, int exit);
int		map_valid_walls_rect(char **map, int m_x, int m_y);
void	map_valid_path(char **map, int curr_x, int curr_y, int *found);

// INIT
int		__init_struct(t_prog *prog, char *file);

int		free_all(t_prog *prog);

#endif
