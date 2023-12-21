/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:18:20 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/21 03:49:27 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sign(int zeros, char *number)
{
	char	*str_tmp;
	char	*signal;

	if (*number == '-' || *number == '+')
	{
		if (*number == '-')
			signal = ft_strdup("-");
		else
			signal = ft_strdup("+");
		str_tmp = ft_strdup(number + 1);
		if (!signal || !str_tmp)
			return (NULL);
		free(number);
		while (zeros--)
			str_tmp = ft_strmerge(ft_strdup("0"), str_tmp);
		return (ft_strmerge(signal, str_tmp));
	}
	while (zeros--)
		number = ft_strmerge(ft_strdup("0"), number);
	return (number);
}

char	*precision_int(int n, int precision, char *str, size_t len_nb)
{
	if (n == 0 && precision == 0)
	{
		free(str);
		return (ft_strdup(""));
	}
	if (*str == '-')
		len_nb--;
	if ((int)len_nb >= precision)
		return (str);
	else
		str = ft_sign(precision - len_nb, str);
	return (str);
}

char	*precision_uint(unsigned int n, int precision, char *str)
{
	int		i;

	if (n == 0 && precision == 0)
	{
		free(str);
		return (ft_strdup(""));
	}
	i = precision - (int)ft_strlen(str);
	while (i-- > 0)
		str = ft_strmerge(ft_strdup("0"), str);
	return (str);
}
