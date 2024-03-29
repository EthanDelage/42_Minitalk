/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:51:54 by edelage           #+#    #+#             */
/*   Updated: 2022/11/18 16:39:27 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static char	*g_str;

void	print_pid(pid_t process_id, int fd)
{
	ft_put_str_fd("PID: ", fd);
	ft_put_nb_fd(process_id, fd);
	write(fd, "\n", 1);
}

/**
 * @brief This function add bit when signal (SIGUSR1 or SIGUSR2) is received
 *
 * @param signal		Signal received (SIGUSR1 or SIGUSR2)
 */
void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static char		char_received;
	static size_t	bit_received;

	(void) context;
	bit_received++;
	char_received <<= 1;
	if (signal == SIGUSR2)
		char_received += 1;
	usleep(25);
	kill(info->si_pid, SIGUSR1);
	if (bit_received == 8)
	{
		g_str = ft_join_char(g_str, char_received);
		if (char_received == 0)
		{
			ft_put_str_fd(g_str, 1);
			free(g_str);
			g_str = NULL;
		}
		bit_received = 0;
		char_received = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	print_pid(getpid(), 1);
	g_str = NULL;
	s_sigaction.sa_sigaction = &sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		;
}
