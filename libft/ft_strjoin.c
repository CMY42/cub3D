/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:47:21 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/02 14:38:53 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*fin;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	fin = (char *)malloc((ft_strlen (s1) + ft_strlen (s2) + 1));
	if (!fin)
		return (NULL);
	while (*s1)
	{
		fin[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		fin[i] = *s2;
		s2++;
		i++;
	}
	fin[i] = '\0';
	return (fin);
}
