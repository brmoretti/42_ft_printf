/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:57:47 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/01 16:20:14 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char	**tab;
	char	*token;
	va_list	args;

	va_start(args, format);
	tab = ft_split_printf(format);
	if (!tab)
		return (NULL);
	token = *tab;
	while (token)
	{
		//tratar cada token
	}
	ft_clear_tab(tab);
	va_end(args);
	return (1); //retornar o ft_strlen()da string final
}

int	main(void)
{
	char	str[] = "oiii";

	ft_printf("teste: %c, %s\n", 'a', "teste");
	return (0);
}
