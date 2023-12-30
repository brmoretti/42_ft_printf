/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:57:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:30:09 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"
#include <stdarg.h>

static int	ft_free_putstr(char **s)
{
	int	len;

	len = ft_putstr_len(*s);
	free(*s);
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
				*len += parse_char(tab, va_arg(args, int));
			else if (c == 's')
				*len += parse_string(tab, va_arg(args, char *));
			else if (c == 'p')
				*len += parse_ptr(tab, va_arg(args, unsigned long));
			else if (c == 'd' || c == 'i')
				*len += parse_int(tab, va_arg(args, int));
			else if (c == 'u' || c == 'x' || c == 'X')
				*len += parse_uint(tab, va_arg(args, unsigned int), c);
			else if (c == '%')
				*len += parse_perc(tab);
		}
		else
			*len += ft_free_putstr(tab);
		tab++;
	}
}

/**
 * @brief The ft_printf function is a formatted output function that prints
 * data to the standard output stream.
 * It supports various conversion specifiers and flags to format the output
 * according to the given format string.
 * 
 * Conversions:
 * - %d or %i: Signed decimal integer
 * - %u: Unsigned decimal integer
 * - %x or %X: Unsigned hexadecimal
 * - %c: Character
 * - %s: String
 * - %p: Pointer
 * 
 * Flags:
 * - -: Left-align the output
 * - +: Prepend a plus sign for positive numbers
 * - 0: Pad with zeros instead of spaces
 * - #: Use alternative form for conversions
 * - ' ': Prepend a space for positive numbers
 * - width: Minimum width of the field
 * - precision: Number of digits after the decimal point for floating
 *   point conversions
 * 
 * @param format The format string specifying the output format.
 * @param ... Additional arguments to be formatted and printed.
 * @return The number of characters printed, or a negative value if an error
 * occurred.
 */
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
	free(tab);
	va_end(args);
	return (len);
}
