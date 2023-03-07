/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:54 by aroberts          #+#    #+#             */
/*   Updated: 2023/03/07 10:35:11 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

// we use i to increment the string, and shift to increment the bytes, whitch
// are sets of 8 bits.
// we use the if statement to check if the bit is set, if it is
// we shift the bits by 'shift' amount, and we use bitwise and operator (& 1) to
// take a a binary number that is normally multiple 1's and 0's and work out its
//  LSB whitch is a 1 or 0 depending on whether its a even or odd number. This 
// effectively simplifies multiple didgit numbers into single didgits and 
// adds then onto each other as a string, then we use kill() to send the signal 
// to our server.c, pid being what we send and SIGSUR being the signal we use.
// SIGSUR2 is used here as a positive signal, or '1', and SIGSUR1 is 
// used as the negative signal, or '0'. we then increment shift and 
// use usleep() to let the fuction sleep for a moment, (300) is 300 
// microseconds, whitch converts too 0.0003 seconds.
// after all of this we repeat, for the character.

void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(300);
		}
		i++;
	}
}

// our client is what receives the messages.
// when client.c is run, it will print a working message to show it is working,
// it then tests to see if there are three arguments, those being
// the function we are calling, (./client) the PID, and a string.
// when the test returns 'true', we use atoi to turn the PID (string)
// into an interger, we assign this interger to (int pid)
// we then assign the string to argv[2], whitch is the message entered.
// we then put the pid and str into our send_bit function, along with
// and interger that is the length of the string, found with ft_strlen
// from my printf library.

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nERROR\n\n");
}
