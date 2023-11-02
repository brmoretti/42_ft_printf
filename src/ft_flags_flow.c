/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_flow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:56:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 17:45:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_flags(char *str, char flag)
{
	char	*ptr;

	ptr = ft_strchr((const char *)str, flag);
	if (ptr)
		return ((size_t)ft_atoi(ptr + 1));
	return (-1);
}

static int	ft_max_len(int dash, int zero, int dot, char *token)
{
	int	len_token;
	int	max;

	len_token = ft_strlen(token);
	max = len_token;
	if (dash > max)
		max = dash;
	if (zero > max)
		max = zero;
	if (dot > max)
		max = dot;
	return (max);
}

char	*ft_len_flags_flow(char	*flags, char *token)
{
	int		dash;
	int		zero;
	int		dot;

	dash = ft_strchr(flags, '-');
	zero = ft_strchr(flags, '0');
	dot = ft_strchr(flags, '.');
}
