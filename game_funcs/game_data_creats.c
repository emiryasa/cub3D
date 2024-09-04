/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_creats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:07:01 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:34:41 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	double_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != 'C' && map[i] != 'F')
		i++;
	while (map[i] == '\n')
		i++;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i] != '\n')
		i++;
	while (map[i] == '\n')
		i++;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] && map[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] && str2[i])
	{
		if (str2[i] == '\0')
			return (0);
		else if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

t_game	*game_data_creats(char *av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		close_game(game, "Error\nMalloc\n", 1);
	if (ft_strlen(av) < 5 || file_name_control(av, ".cub"))
		close_game(game, "Error\nInvalid file name\n", 1);
	game->fd = open(av, O_RDONLY, 0777);
	if (game->fd == -1)
		close_game(game, "Error\nInvalid map name\n", 1);
	game->temp = ft_get_read(game->fd);
	if (!game->temp)
		close_game(game, "Error\nInvalid map data\n", 1);
	if (double_new_line(game->temp) == -1)
		close_game(game, "Error\nInvalid map data\n", 1);
	game->map_values = ft_split(game->temp, '\n');
	if (!(game->map_values) || ((ft_strcmp(game->map_values[0], "NO ./") == -1)
			&& (ft_strcmp(game->map_values[0], "SO ./") == -1)
			&& (ft_strcmp(game->map_values[0], "WE ./") == -1)
			&& (ft_strcmp(game->map_values[0], "EA ./") == -1)))
		close_game(game, "Error\nInvalid direction data\n", 1);
	if (map_find(game->map_values, game) == -1)
		close_game(game, "Error\nInvalid direction data\n", 1);
	return (game);
}
