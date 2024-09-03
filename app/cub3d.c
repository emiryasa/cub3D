/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:45 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/03 21:14:19 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_direction(t_game *game)
{
	if (game->direction == 'N')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if (game->direction == 'S')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
	else if (game->direction == 'E')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
	else if (game->direction == 'W')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
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
			{	
				game->direction = map[i][j];
				game->player->player_x = j + 0.5;
				game->player->player_y = i + 0.5;
			}
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
		return (close_game(game, "Error: This game cant be opened!\n"));
	game->player = ft_calloc(1, sizeof(t_player));
	get_direction(game->map, game);
	if (start(game) )
		return (close_game(game, "Error: This game cant be opened!\n"));
}
void __attribute__ ((destructor)) end(void)
{
	system("leaks cub3D");
}
