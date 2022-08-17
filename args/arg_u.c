/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:40:29 by mservage          #+#    #+#             */
/*   Updated: 2021/02/16 15:40:31 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_put_nbrstr(unsigned int nbr, char *dest, int size)
{
	static int i = 0;

	if (nbr > 9)
	{
		ft_put_nbrstr(nbr / 10, dest, size);
		ft_put_nbrstr(nbr % 10, dest, size);
	}
	else
		dest[i++] = nbr + '0';
	if (i == size)
		i = 0;
	return (dest);
}

char	*ft_check_flags_u(t_flags flags, char *dest)
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

int		ft_arg_u(va_list arg, t_flags flags)
{
	unsigned int	nbr;
	char			*dest;

	nbr = va_arg(arg, unsigned int);
	if (!(dest = ft_calloc(nbr_size(nbr, 10) + 1, sizeof(char))))
		return (-1);
	dest = ft_put_nbrstr(nbr, dest, nbr_size(nbr, 10));
	if ((dest = ft_check_flags_u(flags, dest)) == NULL)
		return (-1);
	write(1, dest, (nbr = ft_strlen(dest)));
	free(dest);
	return (nbr);
}
