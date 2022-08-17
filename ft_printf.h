/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:36:49 by mservage          #+#    #+#             */
/*   Updated: 2021/02/22 15:36:50 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	int		dot;
	int		minus;
	int		zero;
	int		star;
	int		size1;
	int		size2;
}				t_flags;

char			*ft_if_minus_d(t_flags flags, char *temp);
char			*ft_check_flags_d(t_flags flags, char *dest);
int				ft_arg_d(va_list arg, t_flags flags);

char			*ft_if_no_arg_size_c(int size, char *temp);
char			*ft_if_minus(t_flags flags, char *temp);
unsigned char	*ft_check_flags_c(t_flags flags, unsigned char *dest);
int				ft_arg_c(va_list arg, t_flags flags);

int				nbr_size_p(long long unsigned int nbr);
char			*ft_put_nbrstr_base_p(long long unsigned int nbr, char *dest,
				int size);
char			*ft_add_0x(long long unsigned nbr, char *temp);
char			*ft_check_flags_p(t_flags flags, char *dest);
int				ft_arg_p(va_list arg, t_flags flags);

char			*ft_if_dot_percent(t_flags flags, char *temp);
char			*ft_check_flags_percent(t_flags flags, char *dest);
int				ft_arg_percent(t_flags flags);

char			*ft_if_minus_s(char *temp, t_flags flags, const char *s);
char			*ft_if_dot_s(char *temp, t_flags flags);
char			*ft_check_flags_s(t_flags flags, char *dest, const char *s);
int				ft_arg_s(va_list arg, t_flags flags);

char			*ft_put_nbrstr(unsigned int nbr, char *dest, int size);
int				ft_arg_u(va_list arg, t_flags flags);

int				nbr_size(unsigned int nbr, unsigned int base);
char			*ft_put_nbrstr_base(unsigned int nbr,
				char *dest, int size, int mode);
int				ft_arg_x(va_list arg, t_flags flags, int mode);

char			*ft_size(t_flags flags, char *temp, int k);
char			*ft_if_dot(t_flags flags, char *temp);
char			*ft_if_zero(t_flags flags, char *temp);
char			*ft_if_neg(t_flags *flags, char *temp);
char			*ft_if_dotzero(t_flags flags, char *temp);
char			*ft_if_no_arg_size(int size, char *temp);

t_flags			struct_flag_init(void);
int				ft_flags_minus_zero_init(const char *src,
				t_flags *flags, va_list arg, int j);
int				ft_flags_dot_init(const char *src, t_flags *flags,
				va_list arg, int j);
int				src_reading_flags(const char *src, va_list arg, int *src_i);
int				src_reading_args(const char *src, va_list arg, t_flags flags);

int				src_treatment(va_list arg, const char *src);
int				ft_printf(const char *src,
						...) __attribute__((__format__(__printf__,1,2)));

#endif
