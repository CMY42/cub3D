/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:39:02 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/23 14:52:13 by cmansey          ###   ########.fr       */
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

void	trim_trailing_whitespace(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
	{
		str[i] = '\0';
		i--;
	}
}

char	*skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
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
