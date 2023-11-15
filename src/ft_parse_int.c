/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/15 12:46:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_space_plus_flags(int n, t_flags *flags)
{
	if (n < 0)
		return (0);
	if (flags->plus == 1)
	{
		write(1, "+", 1);
		return (1);
	}
	if (flags->space == 1)
	{
		write(1, " ", 1);
		return (1);
	}
	return (0);
}

int	ft_parse_int(char **token, int n)
{
	size_t	len;
	t_flags	*flags;

	flags = ft_get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	len = ft_space_plus_flags(n, flags);
	if (flags->zero != -1)
		len += ft_zero_flag_int(n, flags->zero);
	else
		len += ft_precision_int(n, flags->dot);
	len += ft_dash_flag(len, flags->dash);
	free(flags);
	return (len);
}
