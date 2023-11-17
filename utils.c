/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:39:02 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/17 19:10:55 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_player_valid(t_map *config)
{
	int		i;
	size_t	j;
	int		player;

	i = 0;
	player = 0;
	while (i < config->map_size)
	{
		j = 0;
		while (config->map_array[i][j] != '\0')
		{
			if (config->map_array[i][j] == 'N'
				|| config->map_array[i][j] == 'S'
				|| config->map_array[i][j] == 'W'
				|| config->map_array[i][j] == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player == 1)
		return (1);
	else
		return (0);
}

void	free_copied_map_array(char **map_copy, int map_size)
{
	int	i;

	if (map_copy == NULL)
		return ;
	i = 0;
	while (i < map_size)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
