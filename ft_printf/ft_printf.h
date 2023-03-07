/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:23:29 by aroberts          #+#    #+#             */
/*   Updated: 2023/03/06 11:50:46 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *args, int *length);
void	ft_putnbr(int nbr, int *len);
void	ft_putchar(char c, int *len);
void	ft_unint(unsigned int nbr, int *len);
void	ft_hex(unsigned int nbr, int *len, int XX);
void	ft_point(size_t point, int *len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

t_message	g_msg;

#endif