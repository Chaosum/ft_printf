/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:34:28 by mservage          #+#    #+#             */
/*   Updated: 2020/12/01 21:47:06 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_treatment_nbr(long int nb, int fd)
{
	char	a;

	a = 0;
	if (nb > 9)
	{
		ft_treatment_nbr((nb / 10), fd);
		ft_treatment_nbr((nb % 10), fd);
	}
	else
	{
		a = nb + '0';
		write(fd, &a, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}
	ft_treatment_nbr(nbr, fd);
}
