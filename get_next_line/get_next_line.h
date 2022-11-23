/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:20:47 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 04:04:24 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//get_next_line_utils.c
size_t	ft_strlen(const char *s);
int		ft_belongs(const char *set, char s);
void	ft_reset(char *buff);
char	*ft_strjoin(char const *res, char const *buff);

//get_next_line.c
void	aux(char **res, char *buff);
char	*one_line(char *buff, int fd);
char	*get_next_line(int fd);

#endif