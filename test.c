/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:22:32 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/06 23:22:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'a';
	char	str[] = "test";
	int		d = INT_MAX;
	int		u = UINT_MAX;
	int		n;

	ft_printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n", c, str, str, 0x11, 0x11, u, u, u);
	printf("c: %c\ns: %s\np: %p\nd: %d\ni: %i\nu: %u\nx: %x\nX: %X\n%%\n", c, str, str, 0x11, 0x11, u, u, u);
	printf("%i\n", n);
	printf("%i\n", n);
	return (0);
}
