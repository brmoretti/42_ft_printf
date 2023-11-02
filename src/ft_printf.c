/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:57:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 04:17:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //DELETE

void	ft_conversion_direct(char **tab, va_list args)
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
				ft_parse_string(tab, va_arg(args, (char *)));
			else if (c == 'p')
				ft_parse_pointer(tab, va_arg(args, unsigned long));
			else if (c == 'd' || c == 'i')
				ft_parse_int(tab, va_arg(args, int));
			else if (c == 'u' || c == 'x' || c == 'X')
				ft_parse_uint(tab, va_arg(args, unsigned int));
			else if (c == '%')
				ft_parse_percentage(tab);
		}
		tab++;
	}
}

int	ft_printf(const char *format, ...)
{
	char	**tab;
	va_list	args;

	va_start(args, format);
	tab = ft_split_printf(format);
	if (!tab)
		return (0);

	ft_clear_tab(tab);
	va_end(args);
	return (1); //retornar o ft_strlen()da string final
}

int	main(void)
{
	ft_printf("teste.%d.%pid%%.%i americanas");
	return (0);
}
