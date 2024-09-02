/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:22:10 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:01:48 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_wallpaper(t_game *game)
{
	int	i;
	int	j;

	game->img_ptr = mlx_new_image(game->mlx, game->x_cord * PIXEL,
			game->y_cord * PIXEL);
	if (!(game->img_ptr))
		return (-1);
	game->wallpaper = (int *)mlx_get_data_addr(game->img_ptr, &i, &i, &i);
	if (!(game->wallpaper))
		return (-1);
	i = -1;
	while (++i < (game->y_cord * PIXEL) / 2)
	{
		j = -1;
		while (++j < game->x_cord * PIXEL)
			game->wallpaper[j + i * game->x_cord * PIXEL] = game->c_color;
	}
	i--;
	while (++i < game->y_cord * PIXEL)
	{
		j = -1;
		while (++j < game->x_cord * PIXEL)
			game->wallpaper[j + i * game->x_cord * PIXEL] = game->f_color;
	}
	return (0);
}

void	get_coordinats(t_game *game)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	while (game->last_walls[++i])
		if (game->last_walls[i] > cont)
			cont = game->last_walls[i];
	game->x_cord = cont;
	game->y_cord = i;
	game->player.rot_speed = 0.05;
	game->player.move_speed = 0.05;
}

int	get_colors(t_game *game, int i, char **ccolor, char **fcolor)
{
	ccolor = ft_split(game->c + 2, ',');
	if (!ccolor)
		return (-1);
	fcolor = ft_split(game->f + 2, ',');
	if (!fcolor)
		return (-1);
	if (ft_atoi(ccolor[0]) == -1 || ft_atoi(ccolor[1]) == -1
		|| ft_atoi(ccolor[2]) == -1 || ft_atoi(fcolor[0]) == -1
		|| ft_atoi(fcolor[1]) == -1 || ft_atoi(fcolor[2]) == -1)
		return (-1);
	game->c_color = (ft_atoi(ccolor[0]) << 16)
		| (ft_atoi(ccolor[1]) << 8) | ft_atoi(ccolor[2]);
	game->f_color = (ft_atoi(fcolor[0]) << 16)
		| (ft_atoi(fcolor[1]) << 8) | ft_atoi(fcolor[2]);
	i = -1;
	while (ccolor[++i])
		free(ccolor[i]);
	free(ccolor);
	i = -1;
	while (fcolor[++i])
		free(fcolor[i]);
	free(fcolor);
	get_coordinats(game);
	return (0);
}

int	can_we_open_files(t_game *game)
{
	char	**ccolor;
	char	**fcolor;
	int		i;

	ccolor = NULL;
	fcolor = NULL;
	i = -1;
	game->files.east = open((game->ea + 3), O_RDONLY, 0777);
	game->files.north = open((game->no + 3), O_RDONLY, 0777);
	game->files.south = open((game->so + 3), O_RDONLY, 0777);
	game->files.west = open((game->we + 3), O_RDONLY, 0777);
	if (game->files.east == -1 || game->files.north == -1
		|| game->files.south == -1 || game->files.west == -1)
		return (-1);
	close (game->files.east);
	close (game->files.north);
	close (game->files.south);
	close (game->files.west);
	if (get_colors(game, i, ccolor, fcolor) == -1)
		return (-1);
	return (0);
}

int	give_me_textures_and_colors(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'N' && map[i][1] == 'O' && map[i][2] == ' ')
			game->no = ft_strdup(map[i]);
		else if (map[i][0] == 'S' && map[i][1] == 'O' && map[i][2] == ' ')
			game->so = ft_strdup(map[i]);
		else if (map[i][0] == 'W' && map[i][1] == 'E' && map[i][2] == ' ')
			game->we = ft_strdup(map[i]);
		else if (map[i][0] == 'E' && map[i][1] == 'A' && map[i][2] == ' ')
			game->ea = ft_strdup(map[i]);
		else if (map[i][0] == 'F' && map[i][1] == ' ')
			game->f = ft_strdup(map[i]);
		else if (map[i][0] == 'C' && map[i][1] == ' ')
			game->c = ft_strdup(map[i]);
		i++;
	}
	if (!(game->no) || !(game->so) || !(game->ea)
		|| !(game->we) || !(game->c) || !(game->f))
		return (-1);
	if (can_we_open_files(game) == -1)
		return (-1);
	return (0);
}
