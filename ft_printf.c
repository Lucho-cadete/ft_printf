/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:06:54 by luimarti          #+#    #+#             */
/*   Updated: 2025/05/20 08:17:50 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			counter = counter + data_filter(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
			i++;
		}
	}
	va_end(args);
	return (counter);
}
