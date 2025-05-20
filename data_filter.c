/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_filter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:24:48 by luimarti          #+#    #+#             */
/*   Updated: 2025/05/17 17:23:42 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int	data_filter(char datatype, va_list args)
{
	if (datatype == 'c')
		return (handle_char(args));
	if (datatype == 's')
		return (handle_str(args));
	if (datatype == 'p')
		return (handle_ptr(args));
	if (datatype == 'd' || datatype == 'i')
		return (handle_int_decimal(args));
	if (datatype == 'u')
		return (handler_unsigned_int(args));
	if (datatype == 'x')
		return (handle_hexadec_lower(args));
	if (datatype == 'X')
		return (handle_hexadec_upper(args));
	if (datatype == '%')
		return (handle_percent(args));
	return (0);
}
