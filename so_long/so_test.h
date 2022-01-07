/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:06:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/01/07 18:25:11 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_TEST_H
# define SO_TEST_H

# include	"mlx.h"
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"libft.h"

typedef struct t_jinx
	{
		void    *mlx_ptr;
		void    *win_ptr;
		void	*player;
		void	*new_img;
		char	*maaap;
		char	*player_path;
		int		width;
		int		height;
	} jinx;
    
int		map_check(int num, char **map);
int		ft_mouve(int keycode, jinx *p);
int		mouse(int keycode, jinx *p);
int		map_y_walls(char **maap, int x, int y);
int		map_x_walls(char **maap, int x, int y);
int		check_components(char **map);
int		draw_map(char **map, jinx *p);
int 	check_components2(char **map);
int		keep_map(jinx *p);

#endif 