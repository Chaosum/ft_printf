/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:06:14 by mservage          #+#    #+#             */
/*   Updated: 2022/08/18 16:05:54 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	b;

	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == b)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			return (dest + i + 1);
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (NULL);
}
