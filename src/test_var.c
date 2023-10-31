/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:17:59 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/31 15:15:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	ft_print_int(int count, ...)
{
	va_list	args;
	int		arg;

	va_start(args, count);
	while (count--)
	{
		arg = va_arg(args, int);
		printf("%d\n", arg);
	}
	va_end(args);
}

int	main(void)
{
	ft_print_int(5, 1, 2, 3);
	return (0);
}
