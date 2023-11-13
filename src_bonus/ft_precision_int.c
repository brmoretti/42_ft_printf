/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:18:20 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 21:58:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_sign(int zeros, const char *number)
{
	int	len;

	if (*number == '-')
	{
		write(1, "-", 1);
		len = 1 + zeros;
		while (zeros--)
			write(1, "0", 1);
		return (len + ft_putstr_len(number + 1));
	}
	len = zeros;
	while (zeros--)
		write (1, "0", 1);
	return (len + ft_putstr_len(number));
}

int	ft_precision_int(int n, int precision)
{
	char	*s;
	int		len;

	s = ft_itoa_base_int(n, 10, 0);
	if (!s)
		return (-1);
	len = (int)ft_strlen(s);
	if (*s == '-')
		len--;
	if (precision == -1 || len >= precision)
		len = ft_putstr_len(s);
	else
		len = ft_sign(precision - len, s);
	free (s);
	return (len);
}
