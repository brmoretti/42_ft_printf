/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:28:37 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

static char	*space_plus_flags(int n, t_flags *flags, char *str)
{
	if (n < 0)
		;
	else if (flags->plus == 1)
		str = ft_strmerge(ft_strdup("+"), str);
	else if (flags->space == 1)
		str = ft_strmerge(ft_strdup(" "), str);
	return (str);
}

int	parse_int(char **token, int n)
{
	size_t	len;
	t_flags	*flags;
	char	*str;

	flags = get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	str = space_plus_flags(n, flags, str);
	if (flags->zero != -1)
		str = zero_flag_int(str, flags->zero, len);
	else
		str = precision_int(n, flags->dot, str, len);
	str = dash_flag(str, flags->dash);
	str = len_flag(str, flags->len);
	len = ft_putstr_len(str);
	free(flags);
	free(str);
	return (len);
}
