/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:12:45 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 21:08:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_conversion(char conversion, unsigned int n)
{
	char *s;

	if (conversion == 'u')
		s = ft_itoa_base_uint(n, 10, 0);
	else if (conversion == 'x')
		s = ft_itoa_base_uint(n, 16, 0);
	else
		s = ft_itoa_base_uint(n, 16, 1);
	return (s);

}

int	ft_precision_uint(char conversion, unsigned int n, int precision)
{
	char	*s;
	size_t	len;
	int		i;

	s = ft_conversion(conversion, n);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	i = precision - len;
	if (precision == -1 || i <= 0)
		len = ft_putstr_len(s);
	else
	{
		len = i;
		while (i--)
			write(1, "0", 1);
		len += ft_putstr_len(s);
	}
	free (s);
	return (len);
}
