/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:57:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/04 17:26:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_flow(char **tab, va_list args)
{
	char	c;

	while (*tab)
	{
		if (**tab == '%')
		{
			c = ft_last_char(*tab);
			if (c == 'c')
				ft_parse_char(tab, va_arg(args, int));
			else if (c == 's')
				ft_parse_string(tab, va_arg(args, char *));
			else if (c == 'p')
				ft_parse_ptr(tab, va_arg(args, unsigned long));
			else if (c == 'd' || c == 'i')
				ft_parse_int(tab, va_arg(args, int));
			else if (c == 'u' || c == 'x' || c == 'X')
				ft_parse_uint(tab, va_arg(args, unsigned int), c);
			else if (c == '%')
				ft_parse_char(tab, '%');
			if (!*tab)
				return (0);
		}
		tab++;
	}
	return (1);
}

int	ft_print_tab(char **tab)
{
	int	len;

	len = 0;
	while (*tab)
	{
		len += ft_strlen((const char *)*tab);
		ft_putstr_fd(*tab, 1);
		tab++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	char	**tab;
	va_list	args;
	int		len;

	va_start(args, format);
	tab = ft_split_printf(format);
	if (!tab)
		return (0);
	len = -1;
	if (ft_conversion_flow(tab, args))
		len = ft_print_tab(tab);
	ft_clear_tab(tab);
	va_end(args);
	return (len);
}
