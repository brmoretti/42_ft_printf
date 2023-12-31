/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:03:50 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/15 12:43:42 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_clear_tab(char **tab)
{
	char	**ptr;

	ptr = tab;
	while (*ptr)
		free(*ptr++);
	free(tab);
	return (NULL);
}
