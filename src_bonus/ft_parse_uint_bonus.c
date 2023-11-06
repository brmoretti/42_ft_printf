/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:25:43 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 21:55:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_parse_uint(char **token, unsigned int n, char conversion)
{
	t_flags	*flags;

	flags = ft_get_flags(*token);
	free (*token);
	if (!flags)
		return (NULL);
	if (conversion == 'u')
		*token = ft_itoa_base_uint(n, 10, 0);
	else if (conversion == 'x')
		*token = ft_conversion_hex(n, conversion, flags);
	free (flags);
	if (!*token)
		return (NULL);
	return (*token);
}
