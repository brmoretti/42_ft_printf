/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:49:34 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 04:05:05 by bmoretti         ###   ########.fr       */
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
	printf("%c %c %d\n", 'a');
	printf("%123%\n");
	return 0;
}
