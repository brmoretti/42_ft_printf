/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:21:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 22:22:57 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_conversion_hex(unsigned int n,
	char conversion, const t_flags *flags)
{
	char	*prefix;
	char	*converted;
	char	*token;

	if (conversion == 'x')
		converted = ft_itoa_base_uint(n, 16, 0);
	else
		converted = ft_itoa_base_uint(n, 16, 1);
	if (!converted)
		return (NULL);
	prefix = NULL;
	if (flags->hash)
		prefix = ft_strdup("0x");
	if (prefix)
	{
		if (conversion == 'X')
			prefix[1] = 'X';
		token = ft_strjoin(prefix, converted);
	}
	free(converted);
	free(prefix);
	return (token);
}
