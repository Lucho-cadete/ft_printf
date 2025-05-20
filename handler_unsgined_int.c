/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_unsgined_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:44:37 by luimarti          #+#    #+#             */
/*   Updated: 2025/05/17 17:33:19 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	buffer_unsigned_int(unsigned int n, char *str);

int	handler_unsigned_int(va_list args)
{
	unsigned int	num;
	char			str[11];
	int				len;

	num = va_arg(args, unsigned int);
	buffer_unsigned_int(num, str);
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

void	buffer_unsigned_int(unsigned int n, char *str)
{
	int				len;
	unsigned int	tmp;

	len = 0;
	tmp = n;
	if (tmp == 0)
		len = 1;
	else
	{
		while (tmp > 0)
		{
			len++;
			tmp = tmp / 10;
		}
	}
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
}
