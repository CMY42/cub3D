/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:40:16 by cmansey           #+#    #+#             */
/*   Updated: 2022/10/28 14:42:22 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c +32);
	else
		return (c);
}

/*int main ()
{
	int c;
	c = 'A';
	printf("%c\n", (ft_tolower(c)));
	printf("%c\n", (tolower(c)));
}*/
