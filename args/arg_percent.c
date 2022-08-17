/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:19:06 by mservage          #+#    #+#             */
/*   Updated: 2021/02/22 15:19:08 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_if_dot_percent(t_flags flags, char *temp)
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

char	*ft_check_flags_percent(t_flags flags, char *dest)
{
	if (flags.dot)
	{
		if ((dest = ft_if_dot_percent(flags, dest)) == NULL)
			return (NULL);
	}
	if (flags.minus)
	{
		if ((dest = ft_if_minus(flags, dest)) == NULL)
			return (NULL);
	}
	if (flags.zero &&
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

int		ft_arg_percent(t_flags flags)
{
	int				i;
	char			*dest;

	i = 0;
	if (!(dest = ft_strdup("%")))
		return (-1);
	if ((dest = ft_check_flags_percent(flags, dest)) == NULL)
		return (-1);
	while (i < flags.size1 || i < 1)
		write(1, &dest[i++], 1);
	free(dest);
	return (i);
}
