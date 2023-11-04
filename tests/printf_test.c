/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:49:34 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 18:02:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	*ptr;
	unsigned long	test;
	int	n;

	n = 10;
	ptr = &n;
	test = (unsigned long)ptr;
	printf("%p, %lu\n", ptr, sizeof(ptr));
	printf("%lx\n", test);
	printf("%d\n", n);
	printf("%1s\n", "abc");
	printf("%0 8d\n", 10);
	printf("%123%\n");
	printf("%daa\n", 123);
	printf("%-10.5daa\n", 123);
	printf("%00daa\n", 123);
	printf("%.s\n", "ab");
	printf("%-10xaaa\n", 5000000);
	return 0;
}
