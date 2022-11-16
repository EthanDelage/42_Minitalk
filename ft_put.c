/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:18:54 by edelage           #+#    #+#             */
/*   Updated: 2022/11/16 13:40:50 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_put_char_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_put_str_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_put_pid_fd(pid_t process_id, int fd)
{
	if (process_id == -2147483648)
		write(fd, "-2147483648", 11);
	else if (process_id < 0)
	{
		write(fd, "-", 1);
		ft_put_pid_fd(-process_id, fd);
	}
	else if (process_id > 9)
	{
		ft_put_pid_fd(process_id / 10, fd);
		ft_put_char_fd(process_id % 10 + '0', fd);
	}
	else
		ft_put_char_fd(process_id % 10 + '0', fd);
}
