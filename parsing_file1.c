/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:30:32 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/17 19:44:01 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	process_texture_and_color(char *line, t_map *config)
{
	if (starts_with(line, "NO") && config->north_texture == NULL)
		config->north_texture = ft_strdup(skip_spaces(&line[2]));
	else if (starts_with(line, "SO") && config->south_texture == NULL)
		config->south_texture = ft_strdup(skip_spaces(&line[2]));
	else if (starts_with(line, "WE") && config->west_texture == NULL)
		config->west_texture = ft_strdup(skip_spaces(&line[2]));
	else if (starts_with(line, "EA") && config->east_texture == NULL)
		config->east_texture = ft_strdup(skip_spaces(&line[2]));
	else if (starts_with(line, "F ") && config->floor_color == -1)
		config->floor_color = parse_color(skip_spaces(&line[2]));
	else if (starts_with(line, "C ") && config->ceiling_color == -1)
		config->ceiling_color = parse_color(skip_spaces(&line[2]));
	else
		return (0);
	return (1);
}

int	process_map_line(char *line, t_map *config)
{
	if (ft_isdigit(line[0]) || line[0] == ' ' || line[0] == '\t')
	{
		config->map_array = parse_map(line, config->map_array,
				&config->map_size);
		return (1);
	}
	return (0);
}

int	parse_line(char *line, t_map *config)
{
	if (is_config_complete(config))
		config->config_done = 1;
	if (config->config_done == 0)
		line = skip_spaces(line);
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	if (config->config_done == 0 && process_texture_and_color(line, config))
		return (0);
	if (config->config_done == 1 && process_map_line(line, config))
		return (0);
	printf("Error\nInvalid or incomplete configuration elements\n");
	exit(EXIT_FAILURE);
}

void	parse_file(int fd, t_map *config)
{
	char	*line;
	char	*temp_line;
	int		i;

	temp_line = get_next_line(fd);
	while (temp_line != NULL)
	{
		line = temp_line;
		if (parse_line(line, config) == -1)
		{
			printf("Error\nInvalid line in file: %s", line);
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		temp_line = get_next_line(fd);
	}
	printf("North texture: %s\n", config->north_texture);
	printf("South texture: %s\n", config->south_texture);
	printf("West texture: %s\n", config->west_texture);
	printf("East texture: %s\n", config->east_texture);
	printf("Floor color: %d\n", config->floor_color);
	printf("Ceiling color: %d\n", config->ceiling_color);
	printf("Map size: %d\n", config->map_size);
	i = 0;
	while (i < config->map_size)
		printf("Map array: %s", config->map_array[i++]);
}

void	ft_check_file(char **argv, t_map *config)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nMap not found.\n");
		close(fd);
		exit (1);
	}
	parse_file(fd, config);
	close(fd);
}
