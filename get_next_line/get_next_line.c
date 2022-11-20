/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:12:39 by lkrief            #+#    #+#             */
/*   Updated: 2022/11/14 15:28:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	aux(char **res, char *buff)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, buff);
	if (tmp)
		free(tmp);
}

char	*one_line(char *buff, int fd)
{
	int		ret;
	char	*res;

	res = NULL;
	ret = 0;
	aux(&res, buff);
	if (!ft_belongs(buff, '\n'))
		ret = read(fd, buff, BUFFER_SIZE);
	while (ret && !ft_belongs(buff, '\n'))
	{
		buff[ret] = '\0';
		aux(&res, buff);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret)
	{
		buff[ret] = '\0';
		aux(&res, buff);
	}
	ft_reset(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	return (one_line(buff, fd));
}
