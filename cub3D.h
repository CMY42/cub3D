/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:01:23 by cmansey           #+#    #+#             */
/*   Updated: 2023/10/31 17:26:31 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// ----------------------------------
// MACROS

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

// ----------------------------------
// STRUCTS

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct s_window {
	void		*ref;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

/* all info needed for an image */
typedef struct s_image {
	void		*ref;
	t_vector	size;
	char		*pxl;
	int			bits_pxl;
	int			l_size;
	int			end;
}				t_image;

typedef struct s_progr {
	void		*mlx;
	t_window	window;
	t_image		img;
	t_vector	img_position;
}				t_progr;

// ---------------------------------
// FUNCTIONS

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_sprite(void *mlx, char *path);
//t_image		ft_new_image(void *mlx, int width, int height);

t_color		new_color(int r, int g, int b, int a);
void		turn_img_to_color(t_image *image, t_color color);

int			ft_input(int key, t_progr *progr);
int			ft_anime(t_progr *progr);

#endif
