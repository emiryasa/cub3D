/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:45:27 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:21:49 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'E' && c != 'W' && c != 'S'
		&& c != ' ' && c != '\n')
		return (-1);
	return (0);
}

int	last_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->last_walls = (int *)ft_calloc(1, sizeof(int)
			* (line_count(game) + 1));
	if (!(game->last_walls))
		return (-1);
	while (game->map_temp[i])
	{
		j = 0;
		while (game->map_temp[i][j])
			j++;
		j--;
		if (game->map_temp[i][j] != '1')
			return (-1);
		game->last_walls[i] = j;
		i++;
	}
	game->last_walls[i] = 0;
	return (0);
}

static int	f_giver(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_temp[++i])
	{
		j = 0;
		while (game->map_temp[i][j])
		{
			if (game->map_temp[i][j] != ' ' && !(game->map_temp[i][j] >= 9
					&& game->map_temp[i][j] <= 13)
				&& game->map_temp[i][j] != '1' && game->map_temp[i][j] != '0'
				&& game->map_temp[i][j] != 'N' && game->map_temp[i][j] != 'E'
				&& game->map_temp[i][j] != 'W' && game->map_temp[i][j] != 'S')
				return (-1);
			if (game->map_temp[i][j] == ' ' || (game->map_temp[i][j] >= 9
					&& game->map_temp[i][j] <= 13))
				game->map_temp[i][j] = 'F';
			j++;
		}
	}
	if (any_zero_in_outside(game->map_temp) == -1)
		return (-1);
	return (0);
}

int	map_check(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (character(game->map_temp[i][j]) == -1)
				return (-1);
			j++;
		}
	}
	if (last_wall(game))
		return (-1);
	if (f_giver(game))
		return (-1);
	if (give_me_textures_and_colors(game->map_values, game) == -1)
		return (-1);
	return (0);
}
