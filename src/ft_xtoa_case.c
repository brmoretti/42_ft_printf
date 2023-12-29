/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:59 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 11:11:23 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_case(int n, int base, int hexcase)
{
	char	*a;

	a = ft_itoa_base(n, base);
	if (hexcase == uppercase)
		a = ft_strtoupper(a);
	return (a);
}

char	*ft_utoa_base_case(unsigned int n, int base, int hexcase)
{
	char	*a;

	a = ft_utoa_base(n, base);
	if (hexcase == uppercase)
		a = ft_strtoupper(a);
	return (a);
}

char	*ft_ultoa_base_case(unsigned long n, int base, int hexcase)
{
	char	*a;

	a = ft_ultoa_base(n, base);
	if (hexcase == uppercase)
		a = ft_strtoupper(a);
	return (a);
}
