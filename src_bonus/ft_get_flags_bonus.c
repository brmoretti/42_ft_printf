/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:55:19 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 21:47:32 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_flags	*ft_flags_initializer(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->dash = -1;
	flags->zero = -1;
	flags->dot = -1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	return (flags);
}

static int	ft_is_in(const char *s, char c, char **ptr)
{
	*ptr = NULL;
	*ptr = ft_strchr(s, c);
	if (*ptr)
		return (1);
	return (0);
}

t_flags	*ft_get_flags(const char *token)
{
	char	*ptr;
	t_flags	*flags;
	int		n;

	flags = ft_flags_initializer();
	if (!flags)
		return (NULL);
	if (ft_is_in(token, '-', &ptr))
		flags->dash = ft_atoi(ptr + 1);
	if (flags->dash == -1)
	{
		if (ft_is_in(token, '0', &ptr))
			flags->zero = ft_atoi(ptr + 1);
	}
	if (ft_is_in(token, '.', &ptr))
		flags->dot = ft_atoi(ptr + 1);
	if (ft_is_in(token, '#', &ptr))
		flags->hash = 1;
	if (ft_is_in(token, ' ', &ptr))
		flags->space = 1;
	if (ft_is_in(token, '+', &ptr))
		flags->plus = 1;
	return (flags);
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	t_flags	*flags;

// 	flags = ft_get_flags("010.#");
// 	printf("dash: %i\n", flags->dash);
// 	printf("zero: %i\n", flags->zero);
// 	printf("dot: %i\n", flags->dot);
// 	printf("hash: %i\n", flags->hash);
// 	printf("space: %i\n", flags->space);
// 	printf("plus: %i\n", flags->plus);
// 	free(flags);
// 	return (0);
// }
