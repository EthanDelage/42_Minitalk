/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:53 by edelage           #+#    #+#             */
/*   Updated: 2022/11/16 13:41:39 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>

size_t	ft_strlen(char *str);
void	ft_put_char_fd(char c, int fd);
void	ft_put_str_fd(char *str, int fd);
void	ft_put_pid_fd(pid_t process_id, int fd);
int		ft_atoi(const char *str);

#endif
