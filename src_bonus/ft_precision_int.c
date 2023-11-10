/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:18:20 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 17:19:21 by bmoretti         ###   ########.fr       */
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

int	ft_zero_flag_int(unsigned int n, int zeros)
{
	char	*s;
	int		i;
	int		len;

	s = ft_itoa_base_int(n, 10, 0);
	if (!s)
		return (-1);
	len = (int)ft_strlen(s);
	i = zeros - len;
	if (zeros == -1 || i <= 0)
		len = ft_putstr_len(s);
	else
		len = ft_sign(i, s);
	free (s);
	return (len);
}
