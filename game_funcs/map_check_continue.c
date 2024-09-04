/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:27:54 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 15:49:39 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	line_count(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_temp[i])
		i++;
	return (i);
}

static int	control(char **map, int i, int j)
{
	if (map[i][j] == 'F' && ((map[i][j + 1] && map[i][j + 1] != 'F' && map[i][j
				+ 1] != '1') || (j != 0 && map[i][j - 1] && map[i][j - 1] != 'F'
				&& map[i][j - 1] != '1') || (map[i + 1] && map[i + 1][j]
				&& map[i + 1][j] != 'F' && map[i + 1][j] != '1') || (i != 0
				&& map[i - 1] && map[i - 1][j] && map[i - 1][j] != 'F' && map[i
				- 1][j] != '1')))
		return (-1);
	return (0);
}

static int	map_characters_control(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
				count++;
		}
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	any_zero_in_outside(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (control(map, i, j) == -1)
				return (-1);
			if (map[i][j] == '0' && ((!map[i + 1] || !map[i + 1][j])
				|| (!map[i - 1] || !map[i - 1][j])))
				return (-1);
		}
	}
	if (map_characters_control(map) == -1)
		return (-1);
	return (0);
}
