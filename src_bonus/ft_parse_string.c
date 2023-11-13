/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:50:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/12 21:12:40 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_null_string(t_flags *flags)
{
	int	len;

	if (0 <= flags->dot && flags->dot <= 5)
		len = 0;
	else
		len = ft_putstr_len("(null)");
	len += ft_dash_flag(len, flags->dash);
	free (flags);
	return (len);
}

static int	ft_left_space(const char *token, const char *str, t_flags *flags)
{
	int	total_len;
	int	len_str;
	int	i;

	if (!str)
	{
		if (0 <= flags->dot && flags->dot <= 5)
			len_str = 0;
		else
			len_str = 6;
	}
	else
	{
		len_str = ft_strlen(str);
		if (flags->dot >= 0  && len_str > flags->dot)
			len_str = flags->dot;
	}
	total_len = ft_atoi(token + 1) - len_str;
	if (total_len <= 0)
		return (0);
	i = total_len;
	while (i--)
		write(1, " ", 1);
	return (total_len);
}

int	ft_parse_string(char **token, char *str)
{
	t_flags		*flags;
	int			len;

	flags = ft_get_flags(*token);
	len = ft_left_space(*token, str, flags);
	free (*token);
	if (!flags)
		return (-1);
	if (!str)
		return (ft_null_string(flags));
	len += ft_putstr_len_limit(str, flags->dot);
	len += ft_dash_flag(len, flags->dash);
	free (flags);
	return (len);
}
