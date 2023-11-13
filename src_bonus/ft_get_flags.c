/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:11:30 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 23:26:08 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_flag_attribute(const char *s, char flag, int atoi)
{
	char	*p;

	p = ft_strchr(s, flag);
	if (!p)
		return (-1);
	if (!atoi)
		return (1);
	return (ft_atoi(p + 1));
}

t_flags	*ft_get_flags(const char *s)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->dash = ft_get_flag_attribute(s, '-', 1);
	flags->dot = ft_get_flag_attribute(s, '.', 1);
	if (flags->dash != -1 || flags->dot != -1)
		flags->zero = -1;
	else
		flags->zero = ft_get_flag_attribute(s, '0', 1);
	flags->hash = ft_get_flag_attribute(s, '#', 0);
	flags->plus = ft_get_flag_attribute(s, '+', 0);
	if (flags->plus != -1)
		flags->space = -1;
	else
		flags->space = ft_get_flag_attribute(s, ' ', 0);
	return (flags);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "#05 .02";
// 	t_flags	*f;

// 	f = ft_get_flags(s);
// 	printf("-: %d\n0: %d\n.: %d\n#: %d\ns: %d\n+: %d\n", f->dash, f->zero, f->dot, f->hash, f->space, f->plus);
// 	free (f);
// 	return (0);
// }
