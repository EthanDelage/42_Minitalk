/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:51:54 by edelage           #+#    #+#             */
/*   Updated: 2022/11/17 14:18:40 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

/**
 * @brief 	Display the pid of this process in specific file descriptor
 *
 * @param process_id	Process id of this programm
 * @param fd			File descriptor where write pid
 */
void	print_pid(pid_t process_id, int fd)
{
	write(fd, "PID: ", 5);
	ft_put_pid_fd(process_id, fd);
	write(fd, "\n", 1);
}

int	main(void)
{
	print_pid(getpid(), 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{

	}
}
