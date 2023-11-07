/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:26:54 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/07 13:32:04 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char 	s[2];

// 	s[0] = 1;
// 	s[1] = '\0';
// 	printf("%zu\n", ft_strlen(s));
// 	printf("%d\n", printf("%s", s));
// 	printf("%c%%\n", 0);
// 	printf("%d\n", printf("%c", 0));
// 	printf("%s", "");
// 	printf("%d\n", printf("%s", ""));
// 	return (0);
// }
