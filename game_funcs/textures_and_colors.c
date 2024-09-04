/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:22:10 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:42:31 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_scene(t_game *game)
{
	int	i;

	game->scene_ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->scene_ptr)
		return (1);
	game->scene = (int *)mlx_get_data_addr(game->scene_ptr, &i, &i, &i);
	if (!game->scene)
		return (1);
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
}

int	get_colors(t_game *game, int i)
{
	game->ccolor = ft_split(game->c + 2, ',');
	if (!game->ccolor)
		close_game(game, "Error\nInvalid rgb value\n", 1);
	game->fcolor = ft_split(game->f + 2, ',');
	if (!game->fcolor)
		close_game(game, "Error\nInvalid rgb value\n", 1);
	while (game->ccolor[++i])
		if (!game->ccolor[i] || !game->fcolor[i])
			close_game(game, "Error\nInvalid rgb value\n", 1);
	if (ft_atoi(game->ccolor[0]) == -1 || ft_atoi(game->ccolor[1]) == -1
		|| ft_atoi(game->ccolor[2]) == -1 || ft_atoi(game->fcolor[0]) == -1
		|| ft_atoi(game->fcolor[1]) == -1 || ft_atoi(game->fcolor[2]) == -1)
		close_game(game, "Error\nInvalid rgb value\n", 1);
	if (control_fc(game) == -1)
		close_game(game, "Error\nInvalid rgb value\n", 1);
	game->c_color = (ft_atoi(game->ccolor[0]) << 16)
		| (ft_atoi(game->ccolor[1]) << 8) | ft_atoi(game->ccolor[2]);
	game->f_color = (ft_atoi(game->fcolor[0]) << 16)
		| (ft_atoi(game->fcolor[1]) << 8) | ft_atoi(game->fcolor[2]);
	get_coordinats(game);
	return (0);
}

int	can_we_open_files(t_game *game)
{
	int		i;

	i = -1;
	game->files.east = open((game->ea + 3), O_RDONLY, 0777);
	game->files.north = open((game->no + 3), O_RDONLY, 0777);
	game->files.south = open((game->so + 3), O_RDONLY, 0777);
	game->files.west = open((game->we + 3), O_RDONLY, 0777);
	if (game->files.east == -1 || game->files.north == -1
		|| game->files.south == -1 || game->files.west == -1)
		close_game(game, "Error\nFile not found\n", 1);
	close(game->files.east);
	close(game->files.north);
	close(game->files.south);
	close(game->files.west);
	if (get_colors(game, i) == -1)
		close_game(game, "Error\nInvalid rgb value\n", 1);
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
	if (!(game->no) || !(game->so) || !(game->ea) || !(game->we) || !(game->c)
		|| !(game->f))
		close_game(game, "Error\nInvalid map data\n", 1);
	if (can_we_open_files(game) == -1)
		close_game(game, "Error\nInvalid map data\n", 1);
	return (0);
}
