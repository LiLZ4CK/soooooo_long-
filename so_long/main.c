/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:14:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/01/07 18:35:30 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_test.h"
#include	"get_next_line.h"

 char *player_banania(int keycode)
{
	char	*up = "./img/banania_up.xpm";
	char	*down = "./img/banania_down.xpm";
	char	*left = "./img/banania_left.xpm";
	char	*right = "./img/banania_right.xpm";
	
	if (keycode == 13 || keycode == 126)
		return (up);
	if (keycode == 1 || keycode == 125)
		return (down);
	if (keycode == 0 || keycode == 123)
		return (left);
	if (keycode == 2 || keycode == 124)
		return (right);
	return (down);
} 
int map_check(int num, char **map)
{
	int 	i;
	char	*ber = ".ber";
	int 	len;

	i = 0;
	len = ft_strlen(map[1]) - 4;
	if (num == 2)
	{
		while (map[1][len] == ber[i])
		{
			len++;
			i++;
			if (!map[1][len] && !ber[i])
			{
				return(1);
			}
			if (map[1][len] != ber[i])
			{
				printf("your map is invalid!\n");
				return(0);
			}
		}
	}
	printf("your map is invalid!\n");
	return(0);
}
char	**map(int argc, char **argv, char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = ft_strdup("");
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		exit(1);
		return(0);
	}
	str = get_next_line(fd, str);
	while (str != NULL)
	{
		map[i] = malloc(ft_strlen(str) + 1);
		map[i] = ft_strdup(str);
		map[i+1] = NULL;
		str = get_next_line(fd, str);
		if (!map)
		{
			free(str);
			str = NULL;
			return (NULL);				
		}
		i++;
	}
	free(str);
	str = NULL;
	return (map);
}
int	ft_move_y(int keycode, jinx *p, int x, int y)
{
	
	if (keycode == 125 || keycode == 1)
	{
		y += 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	if (keycode == 126 || keycode == 13)
	{
		y -= 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	return (y);
} 
int	ft_move_x(int keycode, jinx *p, int x, int y)
{
	if (keycode == 124 || keycode == 2)
	{
		x += 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	if (keycode == 123 || keycode == 0)
	{
		x -= 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	return (x);
}
int	mouse(int keycode, jinx *p)
{
	exit(1);
	return (0);
}
int	ft_mouve(int keycode, jinx *p)
{
	static int x = 80;
	static int y = 80;
	static int i = 1;
	
	//printf("hi\n");
	p->player_path = player_banania(keycode);
	p->player = mlx_xpm_file_to_image(p->mlx_ptr, p->player_path, &p->width, &p->height);
	if (keycode == 124 || keycode == 2 || keycode == 123 || keycode == 0)
	{
		mlx_clear_window(p->mlx_ptr,p->win_ptr);
		x = ft_move_x(keycode, p, x, y);
		//draw_map(map, p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
		printf("your move is : %d\n", i++);
	}
	if (keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
	{
		mlx_clear_window(p->mlx_ptr,p->win_ptr);
		y = ft_move_y(keycode, p, x, y);
		//draw_map(map, p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
		printf("your move is : %d\n", i++);
	}
	if (keycode == 12 || keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
		return (0);
	}
	return (0);
}
int main(int argc, char *argv[])
{
	jinx p;
	int i = 0;
	int j = 0;
	char	**maap;
	
	if (!map_check(argc, argv))
		{
			exit (1);
			return (0);
		}
	maap = map(argc, argv, maap);
	while (maap[i])
	{
		j = 0;
		while (maap[i][j])
		{
			printf("%c", maap[i][j]);
			j++;
		}
		i++;
	}
	j = ft_strlen(maap[0]) - 1;
	if(!map_x_walls(maap, j, i) || !map_y_walls(maap, j, i))
	{
		exit(1);
		return (0);
	}
	if(!check_components(maap))
		return(0);	
	check_components2(maap);

	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, j * 80, i * 80, "so_long");
	//p.player_path = choose_character(p, j, i);
	//p.player_path = "./img/nft80x80.xpm";
	draw_map(maap, &p);
	//p.player = mlx_xpm_file_to_image(p.mlx_ptr, p.player_path, &p.width, &p.height);
	mlx_key_hook(p.win_ptr, ft_mouve, &p);
	mlx_hook(p.win_ptr, 17, (1L<<17), mouse, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}