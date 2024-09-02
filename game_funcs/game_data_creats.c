/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_creats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:07:01 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:01:48 by eyasa            ###   ########.fr       */
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

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	set_nulls(game);
	if (ft_strlen(av) < 5 || file_name_control(av, ".cub") == -1)
		return (get_free(game), NULL);
	game->fd = open(av, O_RDONLY, 0777);
	if (game->fd == -1)
		return (get_free(game), NULL);
	game->temp = ft_get_read(game->fd);
	if (!game->temp)
		return (get_free(game), NULL);
	if (double_new_line(game->temp) == -1)
		return (get_free(game), NULL);
	game->map_values = ft_split(game->temp, '\n');
	if (!(game->map_values) || ((ft_strcmp(game->map_values[0], "NO ./") == -1)
			&& (ft_strcmp(game->map_values[0], "SO ./") == -1)
			&& (ft_strcmp(game->map_values[0], "WE ./") == -1)
			&& (ft_strcmp(game->map_values[0], "EA ./") == -1)))
		return (get_free(game), NULL);
	if (map_find(game->map_values, game) == -1)
		return (get_free(game), NULL);
	return (game);
}
