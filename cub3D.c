/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:19 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/23 15:30:32 by cmansey          ###   ########.fr       */
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

void	ft_init(t_map *config)
{
	config->north_texture_path = NULL;
	config->south_texture_path = NULL;
	config->west_texture_path = NULL;
	config->east_texture_path = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map_array = NULL;
	config->map_size = 0;
	config->config_done = 0;
	config->player_pos_x = -1;
	config->player_pos_y = -1;
}

int	main(int argc, char **argv)
{
	t_progr	progr;
	t_map	config;

	ft_check_args(argc, argv);
	ft_init(&config);
	ft_check_file(argv, &config);
	progr.mlx = mlx_init();
	if (ft_map_valid(&config) == 1 && ft_textures(&config, &progr) == 1)
	{
		printf("pixel color: %d\n", get_pixel_color(&config.north_texture, 0, 0));
		printf("pixel color: %d\n", get_pixel_color(&config.north_texture, 0, 1));
		printf("pixel color: %d\n", get_pixel_color(&config.north_texture, 0, 2));
		printf("pixel color: %d\n", get_pixel_color(&config.north_texture, 1, 0));
		printf("pixel color: %d\n", get_pixel_color(&config.north_texture, 2, 0));
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
	else
	{
		printf("Error\nMap is not valid.\n");
		exit (1);
	}
}
