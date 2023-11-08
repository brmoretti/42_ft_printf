/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:12 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_int(char **token, int n)
{
	char	*s;
	size_t	len;

	free(*token);
	s = ft_itoa_base_int(n, 10, 0);
	if (!*s)
		return (-1);
	len = ft_putstr_len(s);
	free (s);
	return (len);
}
