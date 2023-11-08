/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:57:32 by cmansey           #+#    #+#             */
/*   Updated: 2023/11/07 18:40:55 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_fstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_fstrjoin(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!str)
	{
		str = malloc(sizeof (char));
		str[0] = '\0';
	}
	if (!buf)
		return (NULL);
	new_str = malloc((ft_fstrlen(str) + ft_fstrlen(buf)) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i])
			new_str[i] = str[i];
	while (buf[j])
		new_str[i++] = buf[j++];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
