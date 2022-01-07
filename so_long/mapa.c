/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:07 by zwalad            #+#    #+#             */
/*   Updated: 2022/01/07 18:26:36 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_test.h"

int	map_x_walls(char **maap, int x, int y)
{
	int k;
	
	k = 0;
	while (maap[k][0] == '1' && maap[k][x - 1] == '1' && (k + 1) < y)
	{
		k++;
		if ((k + 1) == y || (!maap[k][x + 1] && !maap[k][0]))
			return(1);			
	}	
	if (maap[k][0] != '1' || maap[k][x] != '1')
	{
		printf("you need walls in the left or the right of the map");
		return (0);
	}
	return (0);
}
int	map_y_walls(char **maap, int x, int y)
{
	int k;
	
	k = 0;
	while (maap[0][k] == '1' && maap[y - 1][k] == '1' && (k + 1) < x)
	{
		if ((k + 1) < x || (!maap[0][k] && !maap[y - 1][k]))
			return (1);
		k++;
	}
	if (maap[0][k] != '1' || maap[y][k] != '1')
	{
		printf("you need walls in the top or bot of the map");
		return (0);
	}
	return (0);
}
int mapchr(char **map, char c)
{
	int	i;
	int j;
	int n;

	i = 0;
	n = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				n++;
			}
			j++;
		}
		i++;
	}
	return(n);
}
int check_components(char **map)
{
	if (mapchr(map, 'C') < 1)
	{
		printf("need at least one collectible");
		exit(1);
	}
	if (mapchr(map, 'E') < 1)
	{
		printf("need at least one exit");
		exit(1);
	}
	if (mapchr(map, '0') < 1)
	{
		printf("need at least one free space");
		exit(1);
	}
	if (mapchr(map, 'P') != 1)
	{
		printf("need atleast one player");
		exit(1);
	}
	return (1);
}
int draw_map(char **map, jinx *p)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/wall.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (map[i][j] == '0')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (map[i][j] == 'C')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/collect.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (map[i][j] == 'E')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/exit.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (map[i][j] == 'P')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				/* p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/banania_down.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y); */
				x += 80;
				j++;
			}
			if (map[i][j] == '\n')
				j++;
		}
		y += 80;
		i++;
	}
	return(0);
}
int check_components2(char **map)
{
	int	i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'E' || map[i][j] == '1' 
				|| map[i][j] == 'P' ||map[i][j] == 'C' || map[i][j] == '\n' 
				|| map[i][j] == '\0')
				{
					j++;
				}
				if (map[i][j] != '0' && map[i][j] != 'E' && map[i][j] != '1' 
				&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != '\n' 
				&& map[i][j] != '\0')
				{
					printf("invalid map");
					exit(1);
				}
		}
		i++;
	}
	return (0);
}

int keep_map(jinx *p)
{
	int 	i;
	int 	j;
	int 	x;
	int 	y;
	char	**lamap;

	i = 0;
	x = 0;
	y = 0;
	lamap = &p->maaap;
	while (lamap[i])
	{
		j = 0;
		x = 0;
		while (lamap[i][j])
		{
			if (lamap[i][j] == '1')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/wall.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (lamap[i][j] == '0')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (lamap[i][j] == 'C')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/collect.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (lamap[i][j] == 'E')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/exit.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (lamap[i][j] == 'P')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				/* p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/banania_down.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y); */
				x += 80;
				j++;
			}
			if (lamap[i][j] == '\n')
				j++;
		}
		y += 80;
		i++;
	}
	return(0);
}