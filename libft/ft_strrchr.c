/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:40:18 by cmansey           #+#    #+#             */
/*   Updated: 2022/11/03 11:31:09 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			str = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (c == 0)
		return ((char *)s);
	return ((char *)str);
}

/*int main ()
{
	char *s = "Hello World World";
	printf("%s\n", (ft_strrchr(s, 'W')));
	printf("%s\n", (strrchr(s, 'W')));
}*/
