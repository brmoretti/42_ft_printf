/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:52:10 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/01 11:45:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtoa(void *ptr)
{
	char			*prefix;
	unsigned long	address_no;
	char			*str;

	prefix = ft_strdup("0x");
	if (!prefix)
		return (NULL);
	address_no = ft_itoa_base_ulong((unsigned long)ptr, 16, 0);
	if (!address_no)
	{
		free (prefix);
		return (NULL);
	}
	str = ft_strjoin(prefix, address_no);
	free (prefix);
	free (address_no);
	return (str);
}
