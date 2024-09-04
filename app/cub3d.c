/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:57:16 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_directionn(t_game *game)
{
	if (game->direction == 'E')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if (game->direction == 'W')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
}

void	set_direction(t_game *game)
{
	if (game->direction == 'N')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
	else if (game->direction == 'S')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
	}
	set_directionn(game);
}

void	get_direction(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S')
			{
				game->direction = map[i][j];
				game->player->player_x = i + 0.5;
				game->player->player_y = j + 0.5;
			}
		}
	}
	set_direction(game);
}

int	control_fc(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->f[i] || game->c[i])
	{
		if (game->f[i] == ',' && game->c[i] == ',')
			count += 2;
		else if (game->f[i] == ',' || game->c[i] == ',')
			count++;
		i++;
	}
	if (count != 4)
		return (-1);
	if ((ft_atoi(game->fcolor[0]) > 255 || ft_atoi(game->fcolor[0]) < 0)
		|| (ft_atoi(game->fcolor[1]) > 255 || ft_atoi(game->fcolor[1]) < 0)
		|| (ft_atoi(game->fcolor[2]) > 255 || ft_atoi(game->fcolor[2]) < 0)
		|| (ft_atoi(game->ccolor[0]) > 255 || ft_atoi(game->ccolor[0]) < 0)
		|| (ft_atoi(game->ccolor[1]) > 255 || ft_atoi(game->ccolor[1]) < 0)
		|| (ft_atoi(game->ccolor[2]) > 255 || ft_atoi(game->ccolor[2]) < 0))
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (printf("Too many/few arguments\n"));
	game = game_data_creats(av[1]);
	if (game == NULL)
		return (close_game(game, "Error: This game cant be opened!\n", 1));
	game->player = ft_calloc(1, sizeof(t_player));
	get_direction(game->map, game);
	if (start(game) == -1)
		return (close_game(game, "Error: This game cant be opened!\n", 1));
}
