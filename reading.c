/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:37:25 by mservage          #+#    #+#             */
/*   Updated: 2021/02/22 15:37:26 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		struct_flag_init(void)
{
	t_flags flags;

	flags.dot = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.size1 = 0;
	flags.size2 = 0;
	return (flags);
}

int			ft_flags_minus_zero_init(const char *src,
			t_flags *flags, va_list arg, int j)
{
	while (src[j] == '-' || src[j] == '0')
	{
		if (src[j] == '-')
			flags->minus++;
		else if (src[j] == '0')
			flags->zero++;
		j++;
	}
	if (src[j] >= '1' && src[j] <= '9')
	{
		flags->size1 = ft_atoi(&src[j]);
		while (src[j] >= '0' && src[j] <= '9')
			j++;
	}
	else if (src[j] == '*')
	{
		if ((flags->size1 = va_arg(arg, int)) < 0)
		{
			flags->minus++;
			flags->size1 = -flags->size1;
		}
		j++;
	}
	return (j);
}

int			ft_flags_dot_init(const char *src, t_flags *flags,
			va_list arg, int j)
{
	if (src[j] == '.')
	{
		flags->dot++;
		j++;
		if (src[j] >= '0' && src[j] <= '9')
		{
			flags->size2 = ft_atoi(&src[j]);
			while (src[j] >= '0' && src[j] <= '9')
				j++;
		}
		else if (src[j] == '*')
		{
			if ((flags->size2 = va_arg(arg, int)) < 0)
			{
				flags->size2 = 0;
				flags->dot = 0;
			}
			j++;
		}
		if (flags->minus && flags->zero)
			flags->zero = 0;
	}
	return (j);
}

int			src_reading_flags(const char *src, va_list arg, int *src_i)
{
	t_flags	flags;
	int		read;
	int		i;

	flags = struct_flag_init();
	i = ft_flags_minus_zero_init(src, &flags, arg, 0);
	i = ft_flags_dot_init(src, &flags, arg, i);
	read = src_reading_args((&src[i]), arg, flags);
	*src_i = *src_i + i + 1;
	return (read);
}

int			src_reading_args(const char *src, va_list arg, t_flags flags)
{
	if (src[0] == 'd' || src[0] == 'i')
		return (ft_arg_d(arg, flags));
	if (src[0] == 'c')
		return (ft_arg_c(arg, flags));
	if (src[0] == 's')
		return (ft_arg_s(arg, flags));
	if (src[0] == 'p')
		return (ft_arg_p(arg, flags));
	if (src[0] == 'u')
		return (ft_arg_u(arg, flags));
	if (src[0] == 'x')
		return (ft_arg_x(arg, flags, 0));
	if (src[0] == 'X')
		return (ft_arg_x(arg, flags, 1));
	if (src[0] == '%')
		return (ft_arg_percent(flags));
	return (0);
}
