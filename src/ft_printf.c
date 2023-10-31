/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:57:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/31 18:35:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "header.h"

void	ft_get_flag(char **str, char *flag)
{
	char	*s;
	char	c;

	s = *str;
	c = *s;
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
	{
		*str = s + 1;
		*flag = c;
	}
	else
		*flag = '\0';
}

void	ft_get_conversion(char **str, char *convention)
{
	char	*s;
	char	c;

	s = *str;
	c = *s;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		*str = s + 1;
		*convention = c;
	}
	else
		*convention = '\0';
}

int	ft_printf(const char *format, ...)
{
	char	flag;
	char	convention;
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*(format++) == '%')
		{
			ft_get_conversion((char **)&format, &convention);
			if (convention == 'c')
				ft_putchar((char)va_arg(args, int));
			if (convention == 's')
				ft_putstr(va_arg(args, char *));
		}
		else
			ft_putchar(*(format - 1));
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	char	str[] = "oiii";

	ft_printf("teste: %c, %s\n", 'a', "teste");
	return (0);
}
