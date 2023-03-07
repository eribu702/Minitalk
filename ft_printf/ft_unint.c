/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:39:22 by aroberts          #+#    #+#             */
/*   Updated: 2023/01/31 12:47:13 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unint(unsigned int nbr, int *len)
{
	if (nbr >= 10)
		ft_unint(nbr / 10, len);
	ft_putchar(nbr % 10 + '0', len);
}
