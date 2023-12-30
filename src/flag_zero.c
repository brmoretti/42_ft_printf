/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:03:16 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:29:23 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

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

char	*zero_flag_int(char *str, int zeros, size_t len_nb)
{
	int		i;

	i = zeros - len_nb;
	if (zeros == -1 || i <= 0)
		return (str);
	else
		str = ft_sign(i, str);
	return (str);
}

char	*zero_flag_uint(int zeros, char *str)
{
	size_t	len_nb;
	int		i;

	len_nb = ft_strlen(str);
	i = zeros - (int)len_nb;
	while (i-- > 0)
		str = ft_strmerge(ft_strdup("0"), str);
	return (str);
}
