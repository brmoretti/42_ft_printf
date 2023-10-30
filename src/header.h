/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:33 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:38 by bmoretti         ###   ########.fr       */
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
char	*ft_itoa_base_uint(unsigned int n, int base, int upper);
char	*ft_itoa_base_ulong(unsigned long n, int base, int upper);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
