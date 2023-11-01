/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:03:50 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/01 16:06:26 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	**ft_clear_tab(void **tab)
{
	void	**ptr;

	ptr = tab;
	while (*ptr)
		free (*ptr++);
	free (tab);
	return (NULL);
}
