/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:33:51 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/17 19:44:00 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*realloc_map_array(char *line, char ***map_array, int *size)
{
	char	*converted_line;
	char	**temp;

	converted_line = convert_tabs_to_spaces(line);
	if (!converted_line)
		return (NULL);
	temp = ft_realloc(*map_array, sizeof(char *)
			* (*size), sizeof(char *) * (*size + 1));
	if (!temp)
	{
		free(converted_line);
		return (NULL);
	}
	*map_array = temp;
	return (converted_line);
}

char	**add_convline_to_map(char *converted_line, char **map_array, int *size)
{
	int	len;

	len = ft_strlen(converted_line);
	map_array[*size] = malloc(len + 1);
	if (!map_array[*size])
	{
		free(converted_line);
		return (NULL);
	}
	ft_strcpy(map_array[*size], converted_line);
	free(converted_line);
	(*size)++;
	return (map_array);
}

char	**parse_map(char *line, char **map_array, int *size)
{
	char	*converted_line;

	converted_line = realloc_map_array(line, &map_array, size);
	if (!converted_line)
		return (NULL);
	return (add_convline_to_map(converted_line, map_array, size));
}

int	is_config_complete(t_map *config)
{
	return (config->north_texture != NULL && config->south_texture != NULL
		&& config->west_texture != NULL && config->east_texture != NULL
		&& config->floor_color != -1 && config->ceiling_color != -1);
}

int	parse_color(char *color_string)
{
	int	r;
	int	g;
	int	b;

	if (ft_sscanf(color_string, &r, &g, &b) == 3)
	{
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		{
			printf("Error\nInvalid color value.\n");
			exit(EXIT_FAILURE);
		}
		return (r << 16 | g << 8 | b);
	}
	else
	{
		printf("Error\nColor format is incorrect.\n");
		exit(EXIT_FAILURE);
	}
}
