/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:50:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/09 10:58:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_null_string(t_flags *flags)
{
	int	len;

	len = ft_putstr_len("(null)");
	len += ft_dash_flag(len, flags->dash);
	free (flags);
	return (len);
}

int	ft_parse_string(char **token, char *str)
{
	t_flags		*flags;
	int			len;

	flags = ft_get_flags(*token);
	free (*token);
	if (!flags)
		return (-1);
	if (!str)
		return (ft_null_string(flags));
	len = ft_putstr_len(str);
	len += ft_dash_flag(len, flags->dash);
	free (flags);
	return (len);
}
