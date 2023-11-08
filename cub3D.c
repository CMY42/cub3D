/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:19 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/08 19:26:09 by cmansey          ###   ########.fr       */
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

char	*skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
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

int	parse_line(char *line, t_map *config)
{
	line = skip_spaces(line);
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	else if (line[0] == 'N' && line[1] == 'O')
		config->north_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'S' && line[1] == 'O')
		config->south_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'W' && line[1] == 'E')
		config->west_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'E' && line[1] == 'A')
		config->east_texture = ft_strdup(skip_spaces(&line[2]));
	else if (line[0] == 'F' && line[1] == ' ')
		config->floor_color = parse_color(skip_spaces(&line[2]));
	else if (line[0] == 'C' && line[1] == ' ')
		config->ceiling_color = parse_color(skip_spaces(&line[2]));
	else if (ft_isdigit(line[0]) || line[0] == ' ')
		config->map_array = parse_map(line, config->map_array);
	else
		return (-1);
	return (0);
}

void	parse_file(int fd, t_map *config)
{
	char	*line;
	char	*temp_line;
	//int		read_status;

	temp_line = get_next_line(fd);

	while (temp_line != NULL)
	{
		//read_status = (temp_line[0] != '\0');
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
	//printf("Map:\n%s\n", config->map_array);
	printf("North texture: %s\n", config->north_texture);
	printf("South texture: %s\n", config->south_texture);
	printf("West texture: %s\n", config->west_texture);
	printf("East texture: %s\n", config->east_texture);
	printf("Floor color: %d\n", config->floor_color);
	printf("Ceiling color: %d\n", config->ceiling_color);
	/*if (read_status == -1)
	{
		printf("Error\nAn error occurred while reading the file.\n");
		exit(EXIT_FAILURE);
	}*/
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
