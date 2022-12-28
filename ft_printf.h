/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:59:03 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/28 14:59:04 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_print_chr(char chr);

int	ft_print_str(const char *str);

int	ft_print_address(unsigned long long address, int instance);

int	ft_print_nbr(int nbr);

int	ft_print_base(const char *base, unsigned int nbr);

int	ft_print_format(va_list args, char format);

int	ft_printf(const char *str, ...);

#endif
