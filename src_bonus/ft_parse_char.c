/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:13 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/09 09:18:03 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_char(char **token, int c)
{
	t_flags	*flags;
	int		len;

	flags = ft_get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	write(1, &c, 1);
	len = 1;
	len += ft_dash_flag(len, flags->dash);
	free(flags);
	return (len);
}
