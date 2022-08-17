/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:59:13 by mservage          #+#    #+#             */
/*   Updated: 2021/02/15 17:59:18 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	src_treatment(va_list arg, const char *src)
{
	int	read;
	int	read_temp;
	int	i;

	i = 0;
	read = 0;
	while (src[i])
	{
		while (src[i] == '%')
		{
			if ((read_temp = src_reading_flags(&src[++i], arg, &i)) == -2)
				read_temp = 0;
			else if (read_temp == -1)
				return (-1);
			read = read + read_temp;
		}
		if (src[i])
		{
			write(1, &src[i++], 1);
			read++;
		}
	}
	return (read);
}

int	ft_printf(const char *src, ...)
{
	int			reading_count;
	va_list		arg;

	va_start(arg, src);
	reading_count = src_treatment(arg, src);
	va_end(arg);
	return (reading_count);
}
