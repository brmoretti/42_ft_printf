/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:07:10 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/07 18:43:28 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_ptr(char **token, unsigned long ptr)
{
	char		*address;
	int			len;

	free (*token);
	if (!ptr)
		return(ft_putstr_len("(nil)"));
	address = ft_itoa_base_ulong(ptr, 16, 0);
	if (!address)
		return (-1);
	len = ft_putstr_len("0x") + ft_putstr_len(address);
	free (address);
	return (len);
}
