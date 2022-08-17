/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:17:47 by mservage          #+#    #+#             */
/*   Updated: 2021/02/15 18:17:55 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		nbr_size(unsigned int nbr, unsigned int base)
{
	int count;

	count = 1;
	while (nbr / base)
	{
		nbr = nbr / base;
		count++;
	}
	return (count);
}

char	*ft_put_nbrstr_base(unsigned int nbr, char *dest,
								int size, int mode)
{
	static int	i = 0;
	char		*tab;

	if (mode == 0)
		tab = "0123456789abcdef";
	else if (mode == 1)
		tab = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_put_nbrstr_base(nbr / 16, dest, size, mode);
		ft_put_nbrstr_base(nbr % 16, dest, size, mode);
	}
	else
		dest[i++] = tab[nbr];
	if (i == size)
		i = 0;
	return (dest);
}

char	*ft_check_flags_x(t_flags flags, char *dest)
{
	if (flags.dot)
		if ((dest = ft_if_dot(flags, dest)) == NULL)
			return (NULL);
	if (flags.minus &&
		((flags.size1 > flags.size2) && flags.size1 > (int)ft_strlen(dest)))
	{
		if ((dest = ft_if_minus_d(flags, dest)) == NULL)
			return (NULL);
	}
	else if (flags.zero &&
			(flags.dot == 0) && (flags.size1 > (int)ft_strlen(dest)))
	{
		if ((dest = ft_if_zero(flags, dest)) == NULL)
			return (NULL);
	}
	else if (flags.size1 > (int)ft_strlen(dest))
		if ((dest = ft_if_no_arg_size(flags.size1, dest)) == NULL)
			return (NULL);
	return (dest);
}

int		ft_arg_x(va_list arg, t_flags flags, int mode)
{
	unsigned int	nbr;
	char			*dest;
	int				i;

	i = 0;
	nbr = va_arg(arg, unsigned int);
	if (!(dest = ft_calloc(nbr_size(nbr, 16) + 1, sizeof(char))))
		return (-1);
	dest = ft_put_nbrstr_base(nbr, dest, nbr_size(nbr, 16), mode);
	if ((dest = ft_check_flags_x(flags, dest)) == NULL)
		return (-1);
	write(1, dest, (i = ft_strlen(dest)));
	free(dest);
	return (i);
}
