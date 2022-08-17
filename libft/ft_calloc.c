/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:27:54 by mservage          #+#    #+#             */
/*   Updated: 2020/12/02 15:33:31 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (!(ptr = malloc(size * count)))
		return (NULL);
	while (i < (size * count))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
