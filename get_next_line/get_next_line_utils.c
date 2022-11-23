/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:21:51 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 17:07:15 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_belongs(const char *set, char s)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

void	ft_reset(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
}

char	*ft_strjoin(char const *res, char const *buff)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (buff[0] == 0)
		return (NULL);
	if (res == NULL)
		join = malloc(sizeof(*join) * (ft_strlen(buff) + 1));
	else
		join = malloc(sizeof(*join) * (ft_strlen(res) + ft_strlen(buff) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (res && res[i])
		join[j++] = res[i++];
	i = 0;
	while (buff[i] && buff[i] != '\n')
		join[j++] = buff[i++];
	if (buff[i] == '\n')
		join[j++] = '\n';
	join[j] = '\0';
	return (join);
}
