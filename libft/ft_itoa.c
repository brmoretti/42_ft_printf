/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:54:07 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/17 15:38:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_define_size(int n)
{
	size_t	s;

	s = 1;
	if (n <= 0)
		s++;
	while (n != 0)
	{
		n /= 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*a;
	size_t		size;
	short int	negative;

	size = ft_define_size(n);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	a[--size] = '\0';
	negative = 0;
	if (n < 0)
		negative = 1;
	if (n < 0)
		a[0] = '-';
	while (size)
	{
		if (n < 0)
			a[--size] = (-(n % 10)) + '0';
		else
			a[--size] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
		a[0] = '-';
	return (a);
}
