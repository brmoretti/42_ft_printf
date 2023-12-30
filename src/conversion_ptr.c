/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:07:10 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:28:50 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

static char	*null_pointer(void)
{
	char	*str;

	str = ft_strdup("(nil)");
	if (!str)
		return (NULL);
	return (str);
}

int	parse_ptr(char **token, unsigned long ptr)
{
	char	*str;
	int		len;
	t_flags	*flags;

	flags = get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	if (!ptr)
		str = null_pointer();
	else
		str = ft_strmerge(ft_strdup("0x"), ft_ultoa_base(ptr, 16));
	str = dash_flag(str, flags->dash);
	str = len_flag(str, flags->len);
	len = ft_putstr_len(str);
	free(flags);
	free(str);
	return (len);
}
