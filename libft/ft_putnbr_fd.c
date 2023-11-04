/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:53:59 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/17 15:42:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];
	int		i;
	int		digit;

	i = 11;
	s[--i] = '\0';
	if (n == 0)
		s[--i] = '0';
	else if (n < 0)
	{
		write(fd, "-", 1);
		digit = -(n % 10);
		s[--i] = (char)digit + '0';
		n = -(n / 10);
	}
	while (n > 0)
	{
		digit = n % 10;
		s[--i] = (char)digit + '0';
		n = n / 10;
	}
	ft_putstr_fd(&s[i], fd);
}
