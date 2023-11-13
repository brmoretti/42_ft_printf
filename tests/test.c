/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:18:54 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/11 16:41:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	// printf("$%.0s$\n", "abc");
	// printf("$%.10p$\n", NULL);
	// printf("$%+.3d$\n", 10);
	// printf("$%03d$\n", -10);
	// printf("$%.3d$\n", 10);
	// printf("$%03d$\n", 10);
	// printf("$%+.0u$\n", 11);
	// printf("$%#.5x$\n", 11);
	// printf("$%#.5X$\n", 11);
	// printf("$%#05x$\n", 11);
	// printf("$%-10.3s$\n", NULL);
	// printf("$%.3s$\n", "NULL");
	// printf("$%.0p$\n", NULL);
	// printf("$% d$", 0);
	printf("$%5.3s$\n", "12345");
	printf("$%10.8s$\n", NULL);
	printf("$% 1s$\n", "");

	return (0);
}
