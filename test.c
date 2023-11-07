/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:22:32 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/07 10:13:58 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

void	test_c_5_8_9(void)
{
	int	ft;
	int	original;

	ft = ft_printf(" %c %c %c ", '0', 0, '1');
	puts("");
	original = printf(" %c %c %c ", '0', 0, '1');
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf(" %c %c %c ", '2', '1', 0);
	puts("");
	original = printf(" %c %c %c ", '2', '1', 0);
	printf("\nft: %d - original: %d\n\n", ft, original);

	ft = ft_printf(" %c %c %c ", 0, '1', '2');
	puts("");
	original = printf(" %c %c %c ", 0, '1', '2');
	printf("\nft: %d - original: %d\n\n", ft, original);
}

int	main(void)
{
	char	c = 'a';
	char	str[] = "test";
	int		d = INT_MAX;
	int		u = UINT_MAX;
	int		n;

	//ft_printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n", c, str, str, 0x11, 0x11, u, u, u);
	//printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n", c, str, str, 0x11, 0x11, u, u, u);
	//printf("%i\n", n);
	//printf("%i\n", n);
	test_c_5_8_9();
	return (0);
}
