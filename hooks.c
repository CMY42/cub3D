/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:04:31 by cmansey           #+#    #+#             */
/*   Updated: 2023/10/31 17:19:22 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, t_progr *progr)
{
	mlx_clear_window(progr->mlx, progr->window.ref);
	if (key == 2 || key == 100)
		progr->img_position.x += progr->img.size.x;
	else if (key == 0 || key == 97)
		progr->img_position.x -= progr->img.size.x;
	else if (key == 1 || key == 115)
		progr->img_position.y += progr->img.size.y;
	else if (key == 13 || key == 119)
		progr->img_position.y -= progr->img.size.y;
	else if (key == 53 || key == 65307)
		exit(0);
			/*change color based on keys R, G and B.
	else if (key == 114)
		turn_img_to_color(&progr->img, new_color(255,0,0,0));
	else if (key == 103)
		turn_img_to_color(&progr->img, new_color(0,255,0,0));
	else if (key == 98)
		turn_img_to_color(&progr->img, new_color(0,0,255,0));*/
	mlx_put_image_to_window(progr->mlx, progr->window.ref,
		progr->img.ref, progr->img_position.x, progr->img_position.y);
	printf("Key pressed -> %d\n", key);
	return (0);
}
