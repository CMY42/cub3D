/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:59 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/17 19:11:48 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// ATTENTION GESTION ESPACE A VERIFIER !!!!!!!!!!!!!!!!!!!!!!!!

// Vérifiez si vous êtes en dehors des limites de la carte
// Si la case est déjà visitée ou c'est un mur, elle est valide
int	flood_fill_util(char **map, int x, int y, int map_size)
{
	if (x < 0 || x >= map_size || y < 0 || y >= (int)ft_strlen(map[x])
		|| map[x][y] == ' ')
		return (0);
	if (map[x][y] == 'v' || map[x][y] == '1')
		return (1);
	map[x][y] = 'v';
	if (!flood_fill_util(map, x + 1, y, map_size))
		return (0);
	if (!flood_fill_util(map, x - 1, y, map_size))
		return (0);
	if (!flood_fill_util(map, x, y + 1, map_size))
		return (0);
	if (!flood_fill_util(map, x, y - 1, map_size))
		return (0);
	return (1);
}

int	flood_fill(t_map *config, char **map_copy)
{
	int		i;
	int		j;

	i = 0;
	while (i < config->map_size)
	{
		j = 0;
		while (j < (int)ft_strlen(config->map_array[i]))
		{
			if (ft_strchr("NSEW", config->map_array[i][j]))
			{
				config->player_pos_x = i;
				config->player_pos_y = j;
				break ;
			}
			j++;
		}
		if (config->player_pos_x != -1)
			break ;
		i++;
	}
	if (config->player_pos_x != -1 && config->player_pos_y != -1)
		return (flood_fill_util(map_copy, config->player_pos_x,
				config->player_pos_y, config->map_size));
	return (0);
}

char	**allocate_map_array(t_map *config)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(config->map_size * sizeof(char *));
	if (!map_copy)
	{
		printf("Error\nMemory allocation failed for map array.\n");
		return (NULL);
	}
	i = 0;
	while (i < config->map_size)
	{
		map_copy[i] = malloc((ft_strlen(config->map_array[i]) + 1)
				* sizeof(char));
		if (!map_copy[i])
		{
			free_copied_map_array(map_copy, config->map_size);
			return (NULL);
		}
		ft_strcpy(map_copy[i], config->map_array[i]);
		i++;
	}
	return (map_copy);
}

char	**copy_map_array(t_map *config)
{
	char	**map_copy;

	if (config == NULL || config->map_array == NULL)
	{
		printf("Error\nMap is not valid.\n");
		return (NULL);
	}
	map_copy = allocate_map_array(config);
	return (map_copy);
}

int	ft_map_valid(t_map *config)
{
	char	**map_copy;
	int		is_valid;

	if (ft_player_valid(config) == 1)
	{
		map_copy = copy_map_array(config);
		if (map_copy)
		{
			is_valid = flood_fill(config, map_copy);
			free_copied_map_array(map_copy, config->map_size);
			return (is_valid);
		}
		else
		{
			printf("Error\nMemory allocation failed for map copy.\n");
			return (0);
		}
	}
	else
		return (0);
}
