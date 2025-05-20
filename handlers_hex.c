/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:46:57 by luimarti          #+#    #+#             */
/*   Updated: 2025/05/17 17:32:44 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int	hexadec_aux(unsigned long num, const char *hexa, char *temp, int temp_size);

int	handle_ptr(va_list args)
{
	unsigned long	num;
	char			*hexa;
	char			temp[19];
	int				len;

	num = (unsigned long)va_arg (args, void *);
	hexa = "0123456789abcdef";
	len = 0;
	if (num == 0)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	len = len + 2;
	len = len + hexadec_aux(num, hexa, temp, 19);
	return (len);
}

int	handle_hexadec_lower(va_list args)
{
	unsigned long	num;
	char			*hexa;
	char			temp[17];
	int				len;

	num = va_arg(args, unsigned int);
	hexa = "0123456789abcdef";
	len = 0;
	if (num == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	len = len + hexadec_aux((unsigned long)num, hexa, temp, 17);
	return (len);
}

int	handle_hexadec_upper(va_list args)
{
	unsigned long	num;
	char			*hexa;
	char			temp[17];
	int				len;

	num = va_arg(args, unsigned int);
	hexa = "0123456789ABCDEF";
	len = 0;
	if (num == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	len = len + hexadec_aux((unsigned long)num, hexa, temp, 17);
	return (len);
}

int	hexadec_aux(unsigned long num, const char *hexa, char *temp, int temp_size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (num > 0 && i < temp_size - 1)
	{
		temp[i++] = hexa[num % 16];
		num = num / 16;
	}
	while (i-- > 0)
	{
		write(1, &temp[i], 1);
		len++;
	}
	return (len);
}
