/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:45:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/07 15:45:29 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_define_size(unsigned int n, int base)
{
	size_t	s;

	s = 1;
	if (n == 0)
		s++;
	while (n != 0)
	{
		n /= base;
		s++;
	}
	return (s);
}

static char	ft_digit_representation(int n, int upper)
{
	if (n <= 9)
		return ((char)n + '0');
	else
		return ((char)(n - 10) + 'a' - upper * ('a' - 'A'));
}

char	*ft_itoa_base_uint(unsigned int n, int base, int upper)
{
	char		*a;
	size_t		size;

	if (base < 2 || base > 36)
		return (NULL);
	size = ft_define_size(n, base);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	a[--size] = '\0';
	while (size--)
	{
		a[size] = ft_digit_representation(n % base, upper);
		n /= base;
	}
	return (a);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	unsigned int		n;
// 	int					base;
// 	char				*str;
// 	int					upper;
// 	int					i;

// 	base = 16;
// 	upper = 1;
// 	n = UINT_MAX;
// 	str = ft_itoa_base_unsigned_int(n, base, upper);
// 	printf("%u base %d: %s\n", n, base, str);
// 	free (str);
// 	n = 0;
// 	str = ft_itoa_base_unsigned_int(n, base, upper);
// 	printf("%u base %d: %s\n", n, base, str);
// 	free (str);
// 	n = INT_MAX;
// 	str = ft_itoa_base_unsigned_int(n, base, upper);
// 	printf("%u base %d: %s\n", n, base, str);
// 	free (str);
// 	i = 0;
// 	while (i <= 36)
// 	{
// 		n = i++;
// 		str = ft_itoa_base_unsigned_int(n, base, upper);
// 		printf("%u base %d: %s\n", n, base, str);
// 		free (str);
// 	}
// 	return (0);
// }
