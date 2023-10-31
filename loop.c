/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:29:31 by cmansey           #+#    #+#             */
/*   Updated: 2023/10/31 17:19:45 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_anime(t_progr *progr)
{
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		progr->img_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		progr->img_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(progr->mlx, progr->window.ref,
		progr->img.ref, progr->img_position.x, progr->img_position.y);
	return (0);
}
