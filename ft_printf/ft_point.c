/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:39:46 by aroberts          #+#    #+#             */
/*   Updated: 2023/02/01 15:53:21 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_point(size_t point, int *len)
{
	char	string[25];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (point == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (point != 0)
	{
		string[i] = base[point % 16];
		point = point / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar(string[i], len);
	}
	return ;
}
