/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:57 by aroberts          #+#    #+#             */
/*   Updated: 2023/03/07 10:00:46 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

// msg is a struct declared in the library file that has a char value and a
// size_t value. note it is a char and not a char *, because this function
// sends messages letter by letter.
// msg.c is the char and msg.i is the int or size_t.
// the str 'msg.c' is equal to the number that is 'bit'
// 'bit' is coverted to its LSB, whitch is 1 if the number is odd,
// and 0 if the number is negative. this number is then moved
// up (<<) based on msg.i, to make room for the next bit.
// we go to 7 because a byte is 8 bits, 7 is number 8 when you include
// the 0'th place.
// when we get a byte we print it
// if we reach the 7th (8th) bit, and we have nothing, it is the end
// of the message, so we pring a new line,
// typing '\n' in the message will not work
// we then reset the variables for the next message.
//
// in short, we dont send any message spesifically through
// SIGUSR, but because we have two different signals, our
// function 'bits()' interprets one as a '1' or a '0', compiling
// the pattern of signals back into bytes, then alphanumericals, then it prints.

void	bits(int bit)
{
	int	i;

	i = 0;
	g_msg.c += ((bit & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

// the while loop will run indefiantely until it is closed
// it will receive signals from SIGUSR 1 & 2, it will then run these signals
// through the function bits, whitch will convert the bits back into the 
// alphanumerical characters they originaly were

int	main(void)
{
	ft_printf("THE SERVER IS RUNNING\n");
	ft_printf("THE SERVER PID IS: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bits);
		signal(SIGUSR1, bits);
		pause();
	}
	return (0);
}
