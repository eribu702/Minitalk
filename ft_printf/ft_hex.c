/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:13:17 by aroberts          #+#    #+#             */
/*   Updated: 2023/02/01 15:36:36 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int nbr, int *len, int XX)
{
	char	str[25];
	char	*base;
	int		i;

	if (XX == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (nbr != 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
	return ;
}
