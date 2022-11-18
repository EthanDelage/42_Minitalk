/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:12:29 by edelage           #+#    #+#             */
/*   Updated: 2022/11/17 23:52:56 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sending_back(int signal)
{
	static size_t	nb_sig_received;

	(void) signal;
	nb_sig_received++;
	ft_put_nb_fd(nb_sig_received, 1);
	ft_put_str_fd(" bits received\n", 1);
}

/**
 * @brief		This function decompose a char (1 byte) to 8 bits
 *
 * @param c		Char to decompose
 * @param pid	Process id of the server
 */
void	decompose_char(char c, pid_t pid)
{
	int		division;

	division = 0b10000000;
	while (division != 0)
	{
		usleep(5000);
		if ((c & division) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		division >>= 1;
	}
}

/**
 * @brief 		This function call decompose_char for each char of str
 *
 * @param str	String to decompose
 * @param pid	Process id of the server
 */
void	decompose_str(char *str, pid_t pid)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		decompose_char(str[index], pid);
		index++;
	}
	decompose_char(str[index], pid);
}

int	main(int argc, char **argv)
{
	pid_t				pid_server;

	signal(SIGUSR1, &sending_back);
	if (argc != 3)
	{
		ft_put_str_fd("Error number argument\n", 2);
		exit(EINVAL);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
	{
		ft_put_str_fd("Error invalid pid\n", 2);
		exit(EINVAL);
	}
	decompose_str(argv[2], pid_server);
	usleep(1000);
	return (0);
}
