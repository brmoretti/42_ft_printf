/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:25:43 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 18:02:50 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_uint(char **token, unsigned int n, char conversion)
{
	char	*s;
	int		len;

	free (*token);
	if (conversion == 'u')
		s = ft_itoa_base_uint(n, 10, 0);
	else if (conversion == 'x')
		s = ft_itoa_base_uint(n, 16, 0);
	else
		s = ft_itoa_base_uint(n, 16, 1);
	if (!*s)
		return (-1);
	len = ft_putstr_len(s);
	free (s);
	return (len);
}
