/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:33:34 by mservage          #+#    #+#             */
/*   Updated: 2020/12/04 10:40:19 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_smaller(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		if (!(dest = malloc(sizeof(char))))
			return (NULL);
		*dest = 0;
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * (ft_smaller(ft_strlen(s), len) + 1))))
		return (NULL);
	if (s)
	{
		i = ft_strlen(s);
		i = 0;
		while (i < len && s[start + i])
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[i] = 0;
	return (dest);
}
