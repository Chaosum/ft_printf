/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:43:17 by mservage          #+#    #+#             */
/*   Updated: 2020/12/02 15:23:41 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev_1(char *str, int neg)
{
	int		i;
	int		j;
	char	a;
	int		b;

	i = 0;
	j = 0;
	if (neg == 1)
		i = 1;
	while (str[j])
		j++;
	b = j;
	j--;
	while (i <= j)
	{
		a = str[j];
		str[j] = str[i];
		str[i] = a;
		i++;
		j--;
	}
	str[b] = '\0';
	return (str);
}

static int		ft_count(long int n)
{
	int			i;
	long int	a;

	i = 1;
	a = n;
	if (n < 0)
		a = -a;
	while (a > 9)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	long int		nbr;
	char			*dest;
	int				neg;

	i = 0;
	neg = 0;
	nbr = n;
	if (n < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	if (!(dest = malloc(sizeof(char) * (ft_count(n) + 1 + neg))))
		return (NULL);
	if (neg == 1)
		dest[i++] = '-';
	while (i < ft_count(n) + neg)
	{
		dest[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	dest[i] = '\0';
	return (ft_strrev_1(dest, neg));
}
