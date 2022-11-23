/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:53:28 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/22 19:22:29 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ptf_color(char c)
{
	int	ret;

	ret = 0;
	if (c == '0')
		ret = ft_ptf_putstr("\033[0m");
	else if (c == 'r')
		ret = ft_ptf_putstr("\033[0;31m");
	else if (c == 'g')
		ret = ft_ptf_putstr("\033[0;32m");
	else if (c == 'y')
		ret = ft_ptf_putstr("\033[0;93m");
	else if (c == 'b')
		ret = ft_ptf_putstr("\033[0;34m");
	else if (c == 'm')
		ret = ft_ptf_putstr("\033[0;95m");
	return (ret);
}
