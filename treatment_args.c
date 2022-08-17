/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:15:45 by mservage          #+#    #+#             */
/*   Updated: 2021/02/15 18:15:50 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_size(t_flags flags, char *temp, int k)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if ((dest = ft_if_neg(&flags, temp)) == NULL)
		return (NULL);
	if (dest[0] == '-')
		i++;
	while (j++ < (flags.size2 - k))
		dest[i++] = '0';
	ft_strlcat(dest, (dest[0] == '-' ? (const char *)&temp[1] :
				(const char *)&temp[0]), (size_t)flags.size2 + 1);
	free(temp);
	return (dest);
}

char	*ft_if_dot(t_flags flags, char *temp)
{
	char	*dest;
	int		k;

	k = (int)ft_strlen(temp);
	dest = temp;
	if (flags.size2 >= k)
		if ((dest = ft_size(flags, temp, k)) == NULL)
			return (NULL);
	if (flags.zero && (flags.size1 > flags.size2) &&
		flags.size1 > k)
		if ((dest = ft_if_dotzero(flags, dest)) == NULL)
			return (NULL);
	if (temp[0] == '0' && flags.size2 == 0)
	{
		if ((flags.zero && (flags.size1 > flags.size2) &&
		(flags.size1 > k || (flags.size2 >= k))))
			free(dest);
		free(temp);
		return (ft_strdup(""));
	}
	return (dest);
}

char	*ft_if_neg(t_flags *flags, char *temp)
{
	char *dest;

	dest = NULL;
	if (temp[0] == '-')
	{
		if (!(dest = ft_calloc(flags->size2++ + 1, sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(dest = ft_calloc(flags->size2 + 1, sizeof(char))))
			return (NULL);
	}
	if (temp[0] == '-')
		dest[0] = '-';
	return (dest);
}

char	*ft_if_dotzero(t_flags flags, char *temp)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_calloc(flags.size1 + 1, sizeof(char))))
		return (NULL);
	while (i < (flags.size1 - (int)ft_strlen(temp)))
		dest[i++] = ' ';
	ft_strlcat(dest, (const char *)temp, (size_t)flags.size1 + 1);
	if (!(temp[0] == '0' && flags.size2 == 0))
		free(temp);
	return (dest);
}

char	*ft_if_no_arg_size(int size, char *temp)
{
	int		i;
	char	*dest;

	if (!(dest = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size - (int)ft_strlen(temp))
		dest[i++] = ' ';
	ft_strlcat(&dest[i], (const char *)temp, size + 1);
	free(temp);
	return (dest);
}
