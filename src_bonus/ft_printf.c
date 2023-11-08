/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:57:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 11:55:57 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_free_putstr(char **s)
{
	int	len;

	len = ft_putstr_len(*s);
	free (*s);
	return (len);
}

static void	ft_conversion_flow(char **tab, va_list args, int *len)
{
	char	c;

	while (*tab)
	{
		if (**tab == '%')
		{
			c = ft_last_char(*tab);
			if (c == 'c')
				*len += ft_parse_char(tab, va_arg(args, int));
			else if (c == 's')
				*len += ft_parse_string(tab, va_arg(args, char *));
			else if (c == 'p')
				*len += ft_parse_ptr(tab, va_arg(args, unsigned long));
			else if (c == 'd' || c == 'i')
				*len += ft_parse_int(tab, va_arg(args, int));
			else if (c == 'u' || c == 'x' || c == 'X')
				*len += ft_parse_uint(tab, va_arg(args, unsigned int), c);
			else if (c == '%')
				*len += ft_parse_char(tab, '%');
		}
		else
			*len += ft_free_putstr(tab);
		tab++;
	}
}

int	ft_printf(const char *format, ...)
{
	char	**tab;
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	tab = ft_split_printf(format);
	if (!tab)
		return (-1);
	len = 0;
	ft_conversion_flow(tab, args, &len);
	free (tab);
	va_end(args);
	return (len);
}
