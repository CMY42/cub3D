/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:01:23 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/23 15:30:28 by cmansey          ###   ########.fr       */
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

typedef struct s_texture
{
	unsigned int	*data;
	int				width;
	int				height;
}					t_texture;

typedef struct s_map
{
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		west_texture;
	t_texture		east_texture;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	int				floor_color;
	int				ceiling_color;
	char			**map_array;
	int				map_size;
	int				config_done;
	int				player_pos_x;
	int				player_pos_y;
}					t_map;

// ---------------------------------
// FUNCTIONS

t_window		ft_new_window(void *mlx, int widht, int height, char *name);
t_image			ft_new_sprite(void *mlx, char *path);
//t_image		ft_new_image(void *mlx, int width, int height);

t_color			new_color(int r, int g, int b, int a);
void			turn_img_to_color(t_image *image, t_color color);

int				ft_input(int key, t_progr *progr);
int				ft_anime(t_progr *progr);

void			ft_check_file(char **argv, t_map *config);
void			parse_file(int fd, t_map *config);
int				parse_line(char *line, t_map *config);
int				process_map_line(char *line, t_map *config);
int				process_texture_and_color(char *line, t_map *config);
int				parse_color(char *color_string);
int				is_config_complete(t_map *config);
char			**parse_map(char *line, char **map_array, int *size);
char			*skip_spaces(char *str);
char			*convert_tabs_to_spaces(const char *line);
void			replace_tabs_with_spaces(const char *line, char *new_line);
char			*allocate_new_line(const char *line, int tab_count);
int				count_tabs(const char *line);
int				starts_with(const char *line, const char *prefix);
int				ft_map_valid(t_map *config);
char			**copy_map_array(t_map *config);
void			free_copied_map_array(char **map_copy, int map_size);
int				flood_fill(t_map *config, char **map_copy);
int				flood_fill_util(char **map, int x, int y, int map_size);
int				ft_player_valid(t_map *config);
int				ft_textures(t_map *config, t_progr *prog);
void			trim_trailing_whitespace(char *str);
unsigned int	get_pixel_color(t_texture *texture, int x, int y);

#endif
