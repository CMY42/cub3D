/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:18 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/17 18:48:11 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	starts_with(const char *line, const char *prefix)
{
	while (*prefix)
		if (*line++ != *prefix++)
			return (0);
	return (1);
}

int	count_tabs(const char *line)
{
	int	count;

	count = 0;
	while (*line != '\0')
	{
		if (*line == '\t')
			count++;
		line++;
	}
	return (count);
}

char	*allocate_new_line(const char *line, int tab_count)
{
	int	new_len;

	new_len = strlen(line) + 3 * tab_count;
	return ((char *)malloc(new_len + 1));
}

void	replace_tabs_with_spaces(const char *line, char *new_line)
{
	int	space_count;

	while (*line != '\0')
	{
		if (*line == '\t')
		{
			space_count = 0;
			while (space_count < 4)
			{
				*new_line = ' ';
				new_line++;
				space_count++;
			}
		}
		else
		{
			*new_line = *line;
			new_line++;
		}
		line++;
	}
	*new_line = '\0';
}

char	*convert_tabs_to_spaces(const char *line)
{
	int		tab_count;
	char	*new_line;

	tab_count = count_tabs(line);
	new_line = allocate_new_line(line, tab_count);
	if (!new_line)
		return (NULL);
	replace_tabs_with_spaces(line, new_line);
	return (new_line);
}
