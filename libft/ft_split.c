/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:39:18 by mservage          #+#    #+#             */
/*   Updated: 2020/12/04 17:04:36 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_free_malloc(char **src)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (src[j])
	{
		free(src[j]);
		j++;
	}
	free(src);
	return (1);
}

static int		ft_nbsep(char *src, char c)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	while (src[i])
	{
		while ((src[i] == c) && src[i])
		{
			a = 1;
			i++;
			if (src[i] == 0)
				return (j);
		}
		if (a == 1)
		{
			j++;
			i--;
		}
		a = 0;
		i++;
	}
	return (j);
}

static int		ft_nextsep(char *src, char c)
{
	int i;

	i = 0;
	while ((src[i] != c) && src[i])
		i++;
	return (i);
}

static char		**ft_treatment(char **dest, char *src, char c)
{
	int i;
	int j;
	int k;
	int a;

	i = 0;
	j = 0;
	k = 0;
	a = 0;
	while (src[i])
	{
		a = ft_nextsep(src + i, c) + i;
		if (!(dest[j] = malloc(sizeof(char) * (a - i + 1))))
			return (NULL);
		while ((i < a) && (src[i]))
			dest[j][k++] = src[i++];
		dest[j][k] = 0;
		k = 0;
		j++;
		while ((src[i] == c) && (src[i]))
			i++;
	}
	dest[j] = 0;
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if (!s)
		return (0);
	while ((((char *)s)[i] == c) && (((char *)s)[i]))
		i++;
	j = ft_nbsep((char *)s + i, c);
	if (!(tab = malloc(sizeof(char *) * (j + 2))))
		return (NULL);
	if (!(tab = ft_treatment(tab, (char *)s + i, c)))
	{
		ft_free_malloc(tab);
		return (NULL);
	}
	return (tab);
}
