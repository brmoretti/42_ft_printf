/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:07:10 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 15:42:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_ptr(char **token, unsigned long ptr)
{
	char		*prefix;
	char		*address_no;
	char		*str;

	free (*token);
	prefix = ft_strdup("0x");
	if (!prefix)
		return (NULL);
	address_no = ft_itoa_base_ulong(ptr, 16, 0);
	if (!address_no)
	{
		free (prefix);
		return (NULL);
	}
	*token = ft_strjoin(prefix, address_no);
	free (prefix);
	free (address_no);
	return (*token);
}
