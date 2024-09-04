/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find_and_clone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:09:12 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:09:11 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	pointer_counts(char **str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

static int	give_me_map_temp(t_game *game, int i)
{
	int	x;
	int	z;
	int	count;

	x = 0;
	z = i;
	count = pointer_counts(game->map_values + i) + 1;
	game->map_temp = (char **)malloc(sizeof(char *) * count);
	if (!game->map_temp)
		return (-1);
	while (game->map_values[z])
	{
		game->map_temp[x] = (char *)malloc(ft_strlen(game->map_values[z]) + 1);
		if (!game->map_temp[x])
			return (-1);
		ft_strcpy(game->map_temp[x], game->map_values[z]);
		z++;
		x++;
	}
	game->map_temp[x] = NULL;
	return (0);
}

static int	map_clone(t_game *game, int i)
{
	int	x;
	int	z;
	int	count;

	x = 0;
	z = i;
	count = pointer_counts(game->map_values + i) + 1;
	game->map = (char **)ft_calloc(1, sizeof(char *) * count);
	if (!game->map)
		return (-1);
	while (game->map_values[z])
	{
		game->map[x] = (char *)malloc(ft_strlen(game->map_values[z]) + 1);
		if (!game->map[x])
			return (-1);
		ft_strcpy(game->map[x], game->map_values[z]);
		z++;
		x++;
	}
	game->map[x] = NULL;
	if (give_me_map_temp(game, i) == -1)
		return (-1);
	if (map_check(game->map, game) == -1)
		return (-1);
	return (0);
}

int	map_find(char **map, t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] == 32 || (map[i][j] >= 9 && map[i][j] <= 13))
			j++;
		while (map[i][j] && (map[i][j] == '1' || (map[i][j] == 32
				|| (map[i][j] >= 9 && map[i][j] <= 13))))
		{
			if (map[i][j + 1] && map[i][j + 1] != '1' && !(map[i][j + 1] == 32
				|| (map[i][j + 1] >= 9 && map[i][j + 1] <= 13)))
				return (-1);
			j++;
			if (map[i][j] == '\0')
				return (map_clone(game, i));
		}
	}
	return (-1);
}
