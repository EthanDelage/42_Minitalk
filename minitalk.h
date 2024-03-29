/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:34:53 by edelage           #+#    #+#             */
/*   Updated: 2022/11/18 16:26:05 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>

size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_put_nb_fd(int nb, int fd);
void	ft_put_char_fd(char c, int fd);
void	ft_put_str_fd(char *str, int fd);
char	*ft_join_char(char *str, char c);

#endif
