/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freee.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:57:22 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/02 20:44:44 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	double_pointers_free(t_game	*list)
{
	int	i;

	i = -1;
	if (list->map_values)
	{
		while (list->map_values[++i])
			free(list->map_values[i]);
		free(list->map_values);
	}
	i = -1;
	if (list->map)
	{
		while (list->map[++i])
			free(list->map[i]);
		free(list->map);
	}
	i = -1;
	if (list->map_temp)
	{
		while (list->map_temp[++i])
			free(list->map_temp[i]);
		free(list->map_temp);
	}
}

void	list_imgs_free(t_game *list)
{
	if (list->imgs.so)
		mlx_destroy_image(list->mlx, list->imgs.so);
	if (list->imgs.no)
		mlx_destroy_image(list->mlx, list->imgs.no);
	if (list->imgs.ea)
		mlx_destroy_image(list->mlx, list->imgs.ea);
	if (list->imgs.we)
		mlx_destroy_image(list->mlx, list->imgs.we);
}

static void	pointers_free(t_game *list)
{
	if (list->temp)
		free(list->temp);
	if (list->no)
		free(list->no);
	if (list->we)
		free(list->we);
	if (list->so)
		free(list->so);
	if (list->ea)
		free(list->ea);
	if (list->f)
		free(list->f);
	if (list->c)
		free(list->c);
	if (list->last_walls)
		free(list->last_walls);
	if (list->fd)
		close(list->fd);
	list_imgs_free(list);
}

void	get_free(t_game *list)
{
	if (list)
	{
		double_pointers_free(list);
		pointers_free(list);
		free(list);
		list = NULL;
	}
}

int	close_game(t_game *list)
{
	// mlx_destroy_image(list->mlx, list->img_ptr);
	// mlx_destroy_window(list->mlx, list->win);
	get_free(list);
	exit (0);
}
