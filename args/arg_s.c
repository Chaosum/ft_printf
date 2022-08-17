/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:02:19 by mservage          #+#    #+#             */
/*   Updated: 2021/02/15 18:02:21 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_if_minus_s(char *temp, t_flags flags, const char *s)
{
	char	*dest;
	int		i;

	if (!(s == NULL))
		return ((dest = ft_if_minus_d(flags, temp)));
	else
	{
		if (!(dest = ft_calloc(flags.size1 + 1, sizeof(char))))
			return (NULL);
	}
	ft_strlcat(dest, (const char *)temp, (size_t)flags.size1 + 1);
	i = ft_strlen(dest);
	while (i < flags.size1)
		dest[i++] = ' ';
	free(temp);
	return (dest);
}

char	*ft_if_dot_s(char *temp, t_flags flags)
{
	char *dest;

	if (!(dest = ft_calloc(flags.size2 + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(dest, (const char *)temp, (size_t)flags.size2 + 1);
	free(temp);
	return (dest);
}

char	*ft_check_flags_s(t_flags flags, char *dest, const char *s)
{
	if (flags.dot && flags.size2 < (int)ft_strlen(dest))
		if ((dest = ft_if_dot_s(dest, flags)) == NULL)
			return (NULL);
	if (flags.minus && flags.size1 > (int)ft_strlen(dest))
		if ((dest = ft_if_minus_s(dest, flags, s)) == NULL)
			return (NULL);
	if (!(flags.minus) && (flags.size1 > (int)ft_strlen(dest)))
		if ((dest = ft_if_no_arg_size(flags.size1, dest)) == NULL)
			return (NULL);
	return (dest);
}

int		ft_arg_s(va_list arg, t_flags flags)
{
	int			i;
	char		*dest;
	const char	*s;

	i = 0;
	dest = NULL;
	if ((s = va_arg(arg, const char *)) == NULL)
		dest = ft_strdup("(null)");
	else
		dest = ft_strdup(s);
	if (flags.zero)
	{
		free(dest);
		return (-2);
	}
	if ((dest = ft_check_flags_s(flags, dest, s)) == NULL)
		return (-1);
	write(1, dest, (i = ft_strlen(dest)));
	free(dest);
	return (i);
}
