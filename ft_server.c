/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:51:54 by edelage           #+#    #+#             */
/*   Updated: 2022/11/16 14:28:11 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(void)
{
	write(1, "PID: ", 5);
	ft_put_pid_fd(getpid(), 1);
	write(1, "\n", 1);
}
