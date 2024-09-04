/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:57:22 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:42:43 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	double_pointers_free(t_game *game)
{
	int	i;

	i = -1;
	if (game->map_values)
	{
		while (game->map_values[++i])
			free(game->map_values[i]);
		free(game->map_values);
	}
	i = -1;
	if (game->map)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	i = -1;
	if (game->map_temp)
	{
		while (game->map_temp[++i])
			free(game->map_temp[i]);
		free(game->map_temp);
	}
}

void	game_imgs_free(t_game *game)
{
	if (game->imgs.so)
		mlx_destroy_image(game->mlx, game->imgs.so);
	if (game->imgs.no)
		mlx_destroy_image(game->mlx, game->imgs.no);
	if (game->imgs.ea)
		mlx_destroy_image(game->mlx, game->imgs.ea);
	if (game->imgs.we)
		mlx_destroy_image(game->mlx, game->imgs.we);
}

static void	pointers_free(t_game *game)
{
	if (game->player)
		free(game->player);
	if (game->temp)
		free(game->temp);
	if (game->no)
		free(game->no);
	if (game->we)
		free(game->we);
	if (game->so)
		free(game->so);
	if (game->ea)
		free(game->ea);
	if (game->f)
		free(game->f);
	if (game->c)
		free(game->c);
	if (game->move)
		free(game->move);
	if (game->ray)
		free(game->ray);
	if (game->last_walls)
		free(game->last_walls);
	game_imgs_free(game);
}

void	get_free(t_game *game)
{
	int	i;

	if (game)
	{
		double_pointers_free(game);
		i = -1;
		if (game->fcolor)
		{
			while (game->fcolor[++i])
				free(game->fcolor[i]);
			free(game->fcolor);
		}
		i = -1;
		if (game->ccolor)
		{
			while (game->ccolor[++i])
				free(game->ccolor[i]);
			free(game->ccolor);
		}
		pointers_free(game);
		free(game);
	}
}

int	exit_game(t_game *game)
{
	close_game(game, NULL, 0);
	return (0);
}
