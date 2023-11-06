/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:22:32 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 14:36:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "libft.h"
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
	n = printf("  Or\t:\tInvalid: [%%wawa] = [%wawa]\n");
	printf("%i\n", n);
	n = printf("[%%wawa = [%wawa\n");
	printf("%i\n", n);
	return (0);
}
