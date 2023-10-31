/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:04:26 by cmansey           #+#    #+#             */
/*   Updated: 2023/10/31 17:19:38 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*Returns an image of <width> x <height> black pixels
mlx function that returs a pointer to the first pixel of the image.
¡Pixels are not stored in a 2D table, just a single char[] array!
the fuction also saves in the given pointers:
the bits per pixel (each pixel is usually 4 chars of the array),
the line size of the pixels array  (the amount of pixels in one line of the image)
and the endian (info of how the colors are stored)*/

/*t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.ref = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pxl = mlx_get_data_addr(img.ref, &img.bits_pxl, &img.l_size, &img.end);
	return (img);
}*/

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pxl = mlx_get_data_addr(img.ref, &img.bits_pxl, &img.l_size, &img.end);
	return (img);
}
