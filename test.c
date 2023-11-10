/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:22:32 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 11:08:16 by bmoretti         ###   ########.fr       */
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

void ft_test_hash(void)
{
	int	ft = 0;
	int	original = 0;

	ft = ft_printf("%#x", 0);
	puts("");
	original = printf("%#x", 0);
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("%#x", -10);
	puts("");
	original = printf("%#x", -10);
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("%#x", INT_MAX);
	puts("");
	original = printf("%#x", INT_MAX);
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	puts("");
	original = printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %d - original: %d\n", ft, original);
}

void ft_test_dash(void)
{
	int	ft = 0;
	int	original = 0;

	ft = ft_printf("$%-10c$", 'a');
	puts("");
	original = printf("$%-10c$", 'a');
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("$%-10s$", "abc");
	puts("");
	original = printf("$%-10p$", NULL);
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("$%-10i$", 42);
	puts("");
	original = printf("$%-10c$", 'a');
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("$%-10u$", 40);
	puts("");
	original = printf("$%-10c$", 'a');
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("$%#-10x$", 42);
	puts("");
	original = printf("$%-10c$", 'a');
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("$%-10c$", 'a');
	puts("");
	original = printf("$%-10c$", 'a');
	printf("\nft: %d - original: %d\n", ft, original);

	ft = ft_printf("$%-10c$", 'a');
	puts("");
	original = printf("$%-10c$", 'a');
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
	// test_c_5_8_9();
	// test_s_10();
	// test_p_9();
	// test_u_1_25_29();
	// mix();
	//ft_test_dash();
	ft_test_hash();

	return (0);
}
