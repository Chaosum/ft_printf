/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:19:26 by mservage          #+#    #+#             */
/*   Updated: 2021/02/22 15:19:27 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*ft_if_no_arg_size_c(int size, char *temp)
{
	int		i;
	char	*dest;

	if (!(dest = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size - 1)
		dest[i++] = ' ';
	dest[i++] = temp[0];
	free(temp);
	return (dest);
}

char			*ft_if_minus(t_flags flags, char *temp)
{
	char	*dest;
	int		i;
	int		zero;

	i = 0;
	zero = 0;
	if (!(dest = ft_calloc(flags.size1 + 1, sizeof(char))))
		return (NULL);
	if (temp[0] == 0)
	{
		temp[0] = 1;
		zero++;
	}
	i = ft_strlen(temp);
	while (i < flags.size1)
		dest[i++] = ' ';
	i = -1;
	while (temp[++i] || (zero && temp[i] == 1))
	{
		if (zero && temp[i] == 1)
			temp[i] = 0;
		dest[i] = temp[i];
	}
	free(temp);
	return (dest);
}

unsigned char	*ft_check_flags_c(t_flags flags, unsigned char *dest)
{
	if (flags.minus && flags.size1 > 1)
	{
		if ((dest = (unsigned char *)ft_if_minus(flags, (char *)dest)) == NULL)
			return (NULL);
	}
	else if (flags.size1 > 1)
		if ((dest = (unsigned char *)ft_if_no_arg_size_c(flags.size1,
				(char *)dest)) == NULL)
			return (NULL);
	return (dest);
}

int				ft_arg_c(va_list arg, t_flags flags)
{
	int				i;
	unsigned char	c;
	unsigned char	*dest;

	i = 0;
	if (!(dest = ft_calloc(2, sizeof(unsigned char))))
		return (-1);
	c = va_arg(arg, int);
	dest[0] = c;
	if (flags.zero || flags.size2)
	{
		free(dest);
		return (-2);
	}
	if ((dest = ft_check_flags_c(flags, dest)) == NULL)
		return (-1);
	while (i < flags.size1 || i < 1)
		write(1, &dest[i++], 1);
	free(dest);
	return (i);
}
