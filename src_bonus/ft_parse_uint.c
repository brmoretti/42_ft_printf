/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:25:43 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 16:23:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_hash_flag(unsigned int n, char conversion, t_flags *flags)
{
	if (n == 0 || flags->hash != 1 || conversion == 'u')
		return (0);
	if (conversion == 'x')
		return (ft_putstr_len("0x"));
	else
		return (ft_putstr_len("0X"));
}

int	ft_parse_uint(char **token, unsigned int n, char conversion)
{
	int		len;
	t_flags *flags;

	flags = ft_get_flags(*token);
	free (*token);
	if (!flags)
		return (-1);
	len = ft_hash_flag(n, conversion, flags);
	len += ft_zero_flag_uint(conversion, n, len, flags->zero);
	len += ft_dash_flag(len, flags->dash);
	free (flags);
	return (len);
}
