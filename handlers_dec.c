/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:28:00 by luimarti          #+#    #+#             */
/*   Updated: 2025/05/17 17:05:01 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int	handle_char(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	return (write(1, &c, 1));
}

int	handle_int_decimal(va_list args)
{
	int		number;
	char	*str;
	int		len;

	number = va_arg(args, int);
	str = ft_itoa(number);
	if (!str)
		return (write (1, "(null)", 6));
	len = ft_strlen(str);
	write(1, str, len);
	free (str);
	return (len);
}

int	handle_str(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		return (write (1, "(null)", 6));
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

int	handle_percent(va_list args)
{
	(void)args;
	return (write (1, "%", 1));
}
