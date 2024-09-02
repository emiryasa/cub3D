/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 20:39:18 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_nulls(t_game *game)
{
	game->map_values = NULL;
	game->map = NULL;
	game->map_temp = NULL;
	game->temp = NULL;
	game->no = NULL;
	game->we = NULL;
	game->so = NULL;
	game->ea = NULL;
	game->f = NULL;
	game->c = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->last_walls = NULL;
	game->imgs.ea = NULL;
	game->imgs.no = NULL;
	game->imgs.so = NULL;
	game->imgs.we = NULL;
}

void	set_direction(t_game *game)
{
	if (game->direction == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->direction == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
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
				game->direction = map[i][j];
		}
	}
	set_direction(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (printf("Too many/few arguments\n"));
	game = game_data_creats(av[1]);
	if (game == NULL)
		return (get_free(game), printf("Error: The map cannot be read.\n"));
	get_direction(game->map, game);
	if (start(game) )
		return (close_game(game), printf("Error: This game cant be opened!\n"));
}
