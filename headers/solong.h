/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:54:49 by tgoel             #+#    #+#             */
/*   Updated: 2022/07/20 12:15:27 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define BLOOPMA "Malloc error"
# define BLIPMAP "Incorrect map"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilib/mlx.h"
# include "solongstruct.h"

/* main */
void	handle_movement(int button, t_all *all);
void	gen_map(t_all *all);
void	change_images(t_all *all);
void	regen_px_player(t_all *all, int n_pos_x, int n_pos_y);
void	big_if(t_all *all, int screen_x, int screen_y, int i);
void	put_str(t_all *all);

	/* utils mlx */
int		close_win(t_all *all);
int		key_event(int button, t_all *all);

/* init */
void	__init__all(t_all *all, char *file_path);

/* secure */
void	free_and_null(char **str);
void	free_all_struct(t_mlxWindow *mlib, t_model *models);
void	check_map_errors(t_all *all);
void	check_e_c_p(t_all *all);

/* utils */
char	*read_map(char *path, t_all *all);
int		ft_strlen(char *str);
int		ft_strlenc(const char *str);
int		ft_strlen_char(char *str, char c);
int		better_strlen_char(char *str, char c);
int		amount_char_in_str(char *str, char c);
void	handle_error(char *str, t_all *all);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(unsigned long int n);
int		ft_strchr(char *str, char *srch);

/* random utils */
void	old_pos(t_all *all, int old_pos_x, int old_pos_y, int *d);
void	increment(int *pos_x, int *pos_y);

#endif