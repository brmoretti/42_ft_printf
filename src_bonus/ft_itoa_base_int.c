/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:45:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 16:02:53 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_define_size(int n, int base)
{
	size_t	s;

	s = 1;
	if (n <= 0)
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

char	*ft_itoa_base_int(int n, int base, int upper)
{
	char		*a;
	size_t		size;

	if (base < 2 || base > 36)
		return (NULL);
	size = ft_define_size(n, base);
	a = ft_calloc(size, sizeof(char));
	if (a == NULL)
		return (NULL);
	size--;
	if (n < 0)
	{
		a[0] = '-';
		a[--size] = ft_digit_representation(-(n % base), upper);
		n /= -base;
	}
	while (size--)
	{
		if (size || a[size] != '-')
			a[size] = ft_digit_representation(n % base, upper);
		n /= base;
	}
	return (a);
}
