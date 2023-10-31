/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:19 by cmansey           #+#    #+#             */
/*   Updated: 2023/10/31 17:35:25 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments.\n");
		exit (1);
	}
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
	{
		printf("Error\nInvalid type of file.\nInsert .cub file\n");
		exit (1);
	}
}

/*void	ft_check_map(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nMap not found.\n", 21);
		exit (1);
	}
}*/

int	main(int argc, char **argv)
{
	t_progr	progr;

	ft_check_args(argc, argv);
	//ft_check_map(argv);
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
