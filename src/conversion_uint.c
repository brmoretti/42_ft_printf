/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:25:43 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/21 03:49:22 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hash_flag(unsigned int n, char conversion,
		t_flags *flags, char *number)
{
	if (n == 0 || flags->hash != 1 || conversion == 'u')
		return (number);
	if (conversion == 'x')
		return (ft_strmerge(ft_strdup("0x"), number));
	else
		return (ft_strmerge(ft_strdup("0X"), number));
}

static char	*get_conversion(char conversion, unsigned int n)
{
	char	*s;

	if (conversion == 'u')
		s = ft_itoa_base_uint(n, 10);
	else if (conversion == 'x')
		s = ft_itoa_base_uint(n, 16);
	else
		s = ft_itoa_base_uint_case(n, 16, uppercase);
	return (s);
}

int	parse_uint(char **token, unsigned int n, char conversion)
{
	int		len;
	t_flags	*flags;
	char	*str;

	flags = get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	str = get_conversion(conversion, n);
	str = hash_flag(n, conversion, flags, str);
	if (flags->zero != -1)
		str = zero_flag_uint(flags->zero, str);
	else
		str = precision_uint(n, flags->dot, str);
	str = dash_flag(str, flags->dash);
	str = len_flag(str, flags->len);
	len = ft_putstr_len(str);
	free(flags);
	free(str);
	return (len);
}
