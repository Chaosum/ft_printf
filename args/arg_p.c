/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:40:53 by mservage          #+#    #+#             */
/*   Updated: 2021/02/16 15:40:55 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		nbr_size_p(long long unsigned int nbr)
{
	int count;

	count = 1;
	while (nbr / 16)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

char	*ft_put_nbrstr_base_p(long long unsigned int nbr, char *dest,
								int size)
{
	static int	i = 0;
	char		*tab;

	tab = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_put_nbrstr_base_p(nbr / 16, dest, size);
		ft_put_nbrstr_base_p(nbr % 16, dest, size);
	}
	else
		dest[i++] = tab[nbr];
	if (i == size)
		i = 0;
	return (dest);
}

char	*ft_add_0x(long long unsigned nbr, char *temp)
{
	char *dest;

	if (!(dest = ft_calloc(nbr_size_p(nbr) + 3, sizeof(char))))
		return (NULL);
	dest[0] = '0';
	dest[1] = 'x';
	ft_strlcat(dest, (const char *)temp, nbr_size_p(nbr) + 3);
	return (dest);
}

char	*ft_check_flags_p(t_flags flags, char *dest)
{
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

int		ft_arg_p(va_list arg, t_flags flags)
{
	int						i;
	long long unsigned int	nbr;
	char					*temp;
	char					*dest;

	i = 0;
	dest = NULL;
	nbr = va_arg(arg, unsigned long long int);
	if (!(temp = ft_calloc(nbr_size_p(nbr) + 1, sizeof(char))))
		return (-1);
	temp = ft_put_nbrstr_base_p(nbr, temp, nbr_size_p(nbr));
	if ((dest = ft_add_0x(nbr, temp)) == NULL)
		return (-1);
	if ((void *)nbr == NULL && flags.dot)
	{
		free(dest);
		dest = ft_strdup("0x");
	}
	free(temp);
	if ((dest = ft_check_flags_p(flags, dest)) == NULL)
		return (-1);
	write(1, dest, (i = ft_strlen(dest)));
	free(dest);
	return (i);
}
