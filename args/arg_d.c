/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:17:26 by mservage          #+#    #+#             */
/*   Updated: 2021/02/15 18:17:29 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_if_zero(t_flags flags, char *temp)
{
	int		i;
	int		j;
	char	*dest;

	if (!(dest = ft_calloc(flags.size1 + 1, sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	if (temp[0] == '-')
		dest[i++] = '-';
	while (j++ < flags.size1 - (int)ft_strlen(temp))
		dest[i++] = '0';
	ft_strlcat(dest, (temp[0] == '-' ? (const char *)&temp[1] :
				(const char *)&temp[0]), flags.size1 + 1);
	free(temp);
	return (dest);
}

char	*ft_if_minus_d(t_flags flags, char *temp)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = ft_calloc(flags.size1 + 1, sizeof(char))))
		return (NULL);
	i = ft_strlen(temp);
	while (i < flags.size1)
		dest[i++] = ' ';
	i = -1;
	while (temp[++i])
		dest[i] = temp[i];
	free(temp);
	return (dest);
}

char	*ft_check_flags_d(t_flags flags, char *dest)
{
	if (flags.dot)
		if ((dest = ft_if_dot(flags, dest)) == NULL)
			return (NULL);
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

int		ft_arg_d(va_list arg, t_flags flags)
{
	int		i;
	char	*temp;
	char	*dest;

	temp = ft_itoa(va_arg(arg, int));
	dest = ft_strdup((const char *)temp);
	free(temp);
	if ((dest = ft_check_flags_d(flags, dest)) == NULL)
		return (-1);
	write(1, dest, (i = ft_strlen(dest)));
	free(dest);
	return (i);
}
