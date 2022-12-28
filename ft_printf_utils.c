/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:59:08 by jcapistr          #+#    #+#             */
/*   Updated: 2022/12/28 15:06:13 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		len += ft_print_str("(null)");
	else
		while (str[len])
			len += ft_print_chr(str[len]);
	return (len);
}

int	ft_print_address(unsigned long long address, int instance)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (address == 0)
	{
		len += ft_print_str("(nil)");
		return (len);
	}
	if (instance == 0)
		len += ft_print_str("0x");
	if (address < 16)
		len += ft_print_chr(hex[address % 16]);
	else
	{
		len += ft_print_address(address / 16, instance + 1);
		len += ft_print_chr(hex[address % 16]);
	}
	return (len);
}

int	ft_print_nbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		len += ft_print_chr('-');
		nbr *= -1;
	}
	if (nbr < 10)
		len += ft_print_chr((char)((nbr % 10) + '0'));
	else
	{
		len += ft_print_nbr(nbr / 10);
		len += ft_print_chr((char)((nbr % 10) + '0'));
	}
	return (len);
}

int	ft_print_base(const char *base, unsigned int nbr)
{
	unsigned int	base_len;
	int				len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (nbr < base_len)
		len += ft_print_chr(base[nbr % base_len]);
	else
	{
		len += ft_print_base(base, nbr / base_len);
		len += ft_print_chr(base[nbr % base_len]);
	}
	return (len);
}

int	ft_print_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_chr(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_address(va_arg(args, unsigned long long), 0);
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_base("0123456789", va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_print_base("0123456789abcdef", va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_print_base("0123456789ABCDEF", va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_print_chr('%');
	return (len);
}
