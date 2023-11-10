/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 16:26:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_int(char **token, int n)
{
	size_t	len;
	t_flags	*flags;

	flags = ft_get_flags(*token);
	free (*token);
	if (!flags)
		return (-1);
	len = ft_zero_flag_int(n, flags->zero);
	len += ft_dash_flag(len, flags->dash);
	free (flags);
	return (len);
}
