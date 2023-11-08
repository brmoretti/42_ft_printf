/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:22:32 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 12:16:32 by bmoretti         ###   ########.fr       */
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

	ft = ft_printf("%c", 0);
	puts("");
	original = printf("%c", 0);
	printf("\nft: %d - original: %d\n\n", ft, original);
}

void	test_s_10(void)
{
	int	ft = 0;
	int	original = 0;

	ft = ft_printf(" NULL %s NULL ", NULL);
	puts("");
	original = printf(" NULL %s NULL ", NULL);
	printf("\nft: %d - original: %d\n", ft, original);
}

void	test_p_9(void)
{
	int	ft = 0;
	int	original = 0;

	ft = ft_printf(" %p %p ", 0, 0);
	puts("");
	original = printf(" %p %p ", 0, 0);
	printf("\nft: %d - original: %d\n", ft, original);
}

void	test_u_1_25_29()
{
	int	ft = 0;
	int	original = 0;

	ft = ft_printf(" %u ", 0);
	puts("");
	original = printf(" %u ", 0);
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf(" %u ", LONG_MIN);
	puts("");
	original = printf(" %u ", LONG_MIN);
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	puts("");
	original = printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %d - original: %d\n", ft, original);
}

void	mix()
{
	int	ft = 0;
	int	original = 0;

	ft = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	puts("");
	original = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nft: %d - original: %d\n", ft, original);
}

int	main(void)
{
	char	c = 'a';
	char	str[] = "test";
	int		d = INT_MAX;
	int		u = UINT_MAX;
	int		n;

	ft_printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n", c, str, str, 0x11, 0x11, u, u, u);
	printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n", c, str, str, 0x11, 0x11, u, u, u);
	test_c_5_8_9();
	test_s_10();
	test_p_9();
	test_u_1_25_29();
	mix();
	printf("%d\n", ft_printf(0));
	printf("%d\n", printf(0));
	return (0);
}
