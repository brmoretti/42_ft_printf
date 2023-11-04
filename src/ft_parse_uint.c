/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:25:43 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/04 14:49:52 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_uint(char **token, unsigned int n, char conversion)
{
	free (*token);
	if (conversion == 'u')
		*token = ft_itoa_base_uint(n, 10, 0);
	else if (conversion == 'x')
		*token = ft_itoa_base_uint(n, 16, 0);
	else
		*token = ft_itoa_base_uint(n, 16, 1);
	if (!*token)
		return (NULL);
	return (*token);
}
