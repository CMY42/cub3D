/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:08:40 by cmansey           #+#    #+#             */
/*   Updated: 2022/10/28 14:36:56 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (s);
}

/*int main(int argc, char **argv)
{
	printf("%sio\n",(bzero(argv[1], 7)));
	printf("%sioko\n",(ft_bzero(argv[1], 7)));
}*/
