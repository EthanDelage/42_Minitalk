/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:59:16 by edelage           #+#    #+#             */
/*   Updated: 2022/11/18 16:25:43 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

char	*ft_join_char(char *str, char c)
{
	char	*result;
	size_t	len_str;
	size_t	count;

	len_str = ft_strlen(str);
	result = (char *) malloc(sizeof(char) * (len_str + 2));
	if (result == NULL)
		return (NULL);
	count = 0;
	while (count < len_str)
	{
		result[count] = str[count];
		count++;
	}
	result[count] = c;
	result[count + 1] = '\0';
	free(str);
	return (result);
}
