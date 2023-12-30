/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:13 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:28:29 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

int	parse_char(char **token, int c)
{
	t_flags	*flags;
	int		len;
	char	*str;

	flags = get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	len = 1;
	while (flags->len-- > 1)
	{
		write(1, " ", 1);
		len++;
	}
	write(1, &c, 1);
	str = dash_flag(ft_strdup(""), flags->dash - 1);
	len += ft_putstr_len(str);
	free(flags);
	free(str);
	return (len);
}
