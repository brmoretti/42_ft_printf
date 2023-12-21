/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:59 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/20 13:51:29 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_int_case(int n, int base, int hexcase)
{
	char	*a;

	a = ft_itoa_base_int(n, base);
	if (hexcase == uppercase)
		a = ft_strtoupper(a);
	return (a);
}

char	*ft_itoa_base_uint_case(unsigned int n, int base, int hexcase)
{
	char	*a;

	a = ft_itoa_base_uint(n, base);
	if (hexcase == uppercase)
		a = ft_strtoupper(a);
	return (a);
}

char	*ft_itoa_base_ulong_case(unsigned long n, int base, int hexcase)
{
	char	*a;

	a = ft_itoa_base_ulong(n, base);
	if (hexcase == uppercase)
		a = ft_strtoupper(a);
	return (a);
}
