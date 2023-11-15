/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:07:10 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/15 12:46:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_null_pointer(t_flags *flags)
{
	int	len;

	len = ft_putstr_len("(nil)");
	len += ft_dash_flag(len, flags->dash);
	free(flags);
	return (len);
}

int	ft_parse_ptr(char **token, unsigned long ptr)
{
	char	*address;
	int		len;
	t_flags	*flags;

	flags = ft_get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	if (!ptr)
		return (ft_null_pointer(flags));
	address = ft_itoa_base_ulong(ptr, 16, 0);
	if (!address)
		return (-1);
	len = ft_putstr_len("0x") + ft_putstr_len(address);
	len += ft_dash_flag(len, flags->dash);
	free(flags);
	free(address);
	return (len);
}
