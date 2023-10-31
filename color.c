/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:04:35 by cmansey           #+#    #+#             */
/*   Updated: 2023/10/31 17:21:08 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Return a new color, each value can go from 0 to 255.
* With alpha at 0 the image is opaque,
and with it at 255 is completely transparent. */
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

/* Turns the four first chars of <pixel> to be representing <color>
the first char is blue, the second green, then red
and finally the alpha or transparency.
This order depends on the system, and it is defined by the endian. */
void	turn_pixel_to_color(char *pixel, t_color color)
{
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
	pixel[3] = color.a;
}

/* turns all pixels of <image> to <color> */
/* Loops that repeat for each pixel of the image as it was a 2D table */
/* 	We apply the formula to get the pixel
*	in that x,y position of the pixels char array */
void	turn_img_to_color(t_image *image, t_color color)
{
	int	x;
	int	y;

	y = 0;
	while (y < image->size.y)
	{
		x = 0;
		while (x < image->size.x)
		{
			turn_pixel_to_color(
				&image->pxl[x * 4 + image->l_size * y],
				color);
			x++;
		}
		y++;
	}
}
