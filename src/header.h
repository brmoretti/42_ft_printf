/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:33 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/29 21:46:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa_base_int(int n, int base, int upper);

#endif
