/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:13:43 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/08 17:36:13 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sscanf(const char *str, int *r, int *g, int *b)
{
	int	read;

	read = 0;
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (*str == '\0')
		return (-1);
	read += sscanf(str, "%d", r);
	while (*str && *str != ',')
		str++;
	if (*str != ',')
		return (-1);
	str++;
	read += sscanf(str, "%d", g);
	while (*str && *str != ',')
		str++;
	if (*str != ',')
		return (-1);
	str++;
	read += sscanf(str, "%d", b);
	return (read);
}
