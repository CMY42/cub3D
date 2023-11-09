/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:19 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/09 18:07:30 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments.\nInsert only one map.\n");
		exit (1);
	}
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
	{
		printf("Error\nInvalid type of file.\nInsert .cub file\n");
		exit (1);
	}
}

/*char	*convert_tabs_to_spaces(const char *line)
{
	int		tab_count;
	int		i;
	int		j;
	int		k;
	int		new_len;
	char	*new_line;

	tab_count = 0;
	i = 0;
	j = 0;
	k = 0;
	while (line[i] != '\0')
	{
		if (line[i++] == '\t')
			tab_count++;
	}
	new_len = i + 3 * tab_count;
	new_line = malloc(new_len + 1);
	if (!new_line)
		return (NULL);

	while (line[j] != '\0')
	{
		if (line[j] == '\t')
		{
			new_line[k++] = ' ';
			new_line[k++] = ' ';
			new_line[k++] = ' ';
			new_line[k] = ' ';
		}
		else
			new_line[k] = line[j];
		j++;
		k++;
	}
	new_line[new_len] = '\0';
	return (new_line);
}*/

int	starts_with(const char *line, const char *prefix)
{
	while (*prefix)
		if (*line++ != *prefix++)
			return (0);
	return (1);
}

int	count_tabs(const char *line)
{
	int	count;

	count = 0;
	while (*line != '\0')
	{
		if (*line == '\t')
			count++;
		line++;
	}
	return (count);
}

char	*allocate_new_line(const char *line, int tab_count)
{
	int	new_len;

	new_len = strlen(line) + 3 * tab_count;
	return ((char *)malloc(new_len + 1));
}

void	replace_tabs_with_spaces(const char *line, char *new_line)
{
	int	space_count;

	while (*line != '\0')
	{
		if (*line == '\t')
		{
			space_count = 0;
			while (space_count < 4)
			{
				*new_line = ' ';
				new_line++;
				space_count++;
			}
		}
		else
		{
			*new_line = *line;
			new_line++;
		}
		line++;
	}
	*new_line = '\0';
}

char	*convert_tabs_to_spaces(const char *line)
{
	int		tab_count;
	char	*new_line;

	tab_count = count_tabs(line);
	new_line = allocate_new_line(line, tab_count);
	if (!new_line)
		return (NULL);
	replace_tabs_with_spaces(line, new_line);
	return (new_line);
}

void	ft_init(t_map *config)
{
	config->north_texture = NULL;
	config->south_texture = NULL;
	config->west_texture = NULL;
	config->east_texture = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map_array = NULL;
	config->map_size = 0;
	config->config_done = 0;
}

char	*skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

/*char	**parse_map(char *line, char **map_array)
{
	static int	i = 0;
	int			len;

	printf("line: %s\n", line);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	printf("len: %d\n", len);
	map_array[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!map_array[i])
	{
		free(map_array);
		return (NULL);
	}
	ft_strcpy(map_array[i], line);
	printf("map_array[%d]: %s\n", i, map_array[i]);
	i++;
	return (map_array);
}*/

char	**parse_map(char *line, char **map_array, int *size)
{
	char	**temp;
	int		len;
	char	*converted_line;

	converted_line = convert_tabs_to_spaces(line);
	if (!converted_line)
		return (NULL);
	len = strlen(converted_line);
	temp = ft_realloc(map_array, sizeof(char *) * (*size),
			sizeof(char *) * (*size + 1));
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	map_array = temp;
	map_array[*size] = malloc(len + 1);
	if (!map_array[*size])
	{
		free(map_array[*size]);
		return (NULL);
	}
	strcpy(map_array[*size], converted_line);
	(*size)++;
	return (map_array);
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

/*int	parse_line(char *line, t_map *config)
{
	if (config->north_texture != NULL && config->south_texture != NULL
		&& config->west_texture != NULL && config->east_texture != NULL
		&& config->floor_color != -1 && config->ceiling_color != -1)
		config->config_done = 1;
	if (config->config_done == 0)
		line = skip_spaces(line);
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	else if (line[0] == 'N' && line[1] == 'O' && config->north_texture == NULL)
		config->north_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'S' && line[1] == 'O' && config->south_texture == NULL)
		config->south_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'W' && line[1] == 'E' && config->west_texture == NULL)
		config->west_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'E' && line[1] == 'A' && config->east_texture == NULL)
		config->east_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'F' && line[1] == ' ' && config->floor_color == -1)
		config->floor_color = parse_color(skip_spaces(&line[2]));
	else if (line[0] == 'C' && line[1] == ' ' && config->ceiling_color == -1)
		config->ceiling_color = parse_color(skip_spaces(&line[2]));
	else if (config->config_done == 1)
	{
		if (ft_isdigit(line[0]) || line[0] == ' ' || line[0] == '\t')
			config->map_array = parse_map(line, config->map_array, &config->map_size);
		else
			return (-1);
	}
	else
	{
		printf("Error\nMissing configuration element\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}*/

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

int	is_config_complete(t_map *config)
{
	return (config->north_texture != NULL && config->south_texture != NULL
		&& config->west_texture != NULL && config->east_texture != NULL
		&& config->floor_color != -1 && config->ceiling_color != -1);
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
	int i = 0;
	while (i < config->map_size)
		printf("Map array: %s", config->map_array[i++]);
}

void	ft_check_map(char **argv, t_map *config)
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

int	main(int argc, char **argv)
{
	t_progr	progr;
	t_map	config;

	ft_check_args(argc, argv);
	ft_init(&config);
	ft_check_map(argv, &config);
	progr.mlx = mlx_init();
	progr.window = ft_new_window(progr.mlx, 1980, 1080, "so_long");
	progr.img = ft_new_sprite(progr.mlx, "xpm/player.xpm");
	progr.img_position.x = 100;
	progr.img_position.y = 100;
	mlx_put_image_to_window(progr.mlx, progr.window.ref,
		progr.img.ref, progr.img_position.x, progr.img_position.y);
	mlx_key_hook(progr.window.ref, *ft_input, &progr);
	mlx_loop_hook(progr.mlx, *ft_anime, &progr);
	mlx_loop(progr.mlx);
	return (0);
}
