/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:14:46 by cmansey           #+#    #+#             */
/*   Updated: 2022/10/28 14:42:35 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -32);
	else
		return (c);
}

/*int main ()
{
	int c;
	c = '-';
	printf("%c\n", (ft_toupper(c)));
	printf("%c\n", (toupper(c)));
}*/
