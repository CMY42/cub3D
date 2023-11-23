/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:45:17 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/23 15:30:17 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Charge une texture et stocke ses données
int	load_texture(t_texture *texture, char *file_path, void *mlx_ptr)
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;

	img = mlx_xpm_file_to_image(mlx_ptr, file_path,
			&texture->width, &texture->height);
	if (!img)
		return (0);
	texture->data = (unsigned int *)mlx_get_data_addr(img,
			&bpp, &size_line, &endian);
	return (1);
}


// Charge toutes les textures nécessaires
int	ft_textures(t_map *config, t_progr *prog)
{
	if (!load_texture(&(config->north_texture),
			config->north_texture_path, prog->mlx))
		return (0);
	if (!load_texture(&(config->south_texture),
			config->south_texture_path, prog->mlx))
		return (0);
	if (!load_texture(&(config->west_texture),
			config->west_texture_path, prog->mlx))
		return (0);
	if (!load_texture(&(config->east_texture),
			config->east_texture_path, prog->mlx))
		return (0);
	printf("config->north_texture.data: %p\n", config->north_texture.data);
	printf("width: %d\n", config->north_texture.width);
	printf("height: %d\n", config->north_texture.height);
	printf("config->south_texture.data: %p\n", config->south_texture.data);
	printf("width: %d\n", config->south_texture.width);
	printf("height: %d\n", config->south_texture.height);
	printf("config->west_texture.data: %p\n", config->west_texture.data);
	printf("width: %d\n", config->west_texture.width);
	printf("height: %d\n", config->west_texture.height);
	printf("config->east_texture.data: %p\n", config->east_texture.data);
	printf("width: %d\n", config->east_texture.width);
	printf("height: %d\n", config->east_texture.height);
	return (1);
}

// Récupère la couleur d'un pixel spécifique dans la texture
unsigned int	get_pixel_color(t_texture *texture, int x, int y)
{
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	return (texture->data[y * texture->width + x]);
}
