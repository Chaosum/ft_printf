/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:53:07 by mservage          #+#    #+#             */
/*   Updated: 2020/11/30 22:21:13 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ((char)c))
			return ((char *)s + i);
		i++;
	}
	if ((c == 0) && (s[i] == 0))
		return ((char *)s + i);
	return (NULL);
}
