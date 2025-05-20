/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:04:36 by luimarti          #+#    #+#             */
/*   Updated: 2025/05/17 17:18:25 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	data_filter(char datatype, va_list args);
int	handle_char(va_list args);
int	handle_int_decimal(va_list args);
int	handle_str(va_list args);
int	handler_unsigned_int(va_list args);
int	handle_percent(va_list args);
int	handle_ptr(va_list args);
int	handle_hexadec_lower(va_list args);
int	handle_hexadec_upper(va_list args);
int	hexadec_aux(unsigned long num, const char *hexa, char *temp, int temp_size);

#endif