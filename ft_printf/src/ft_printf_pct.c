/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <gde-matt@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:44:50 by gde-matt          #+#    #+#             */
/*   Updated: 2020/12/21 21:16:03 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_pct(t_flags *flags, va_list args)
{
	int		count;

	ft_printf_star(flags, args);
	count = 0;
	if (flags->minus)
		count += ft_putchar('%');
	while (flags->width-- > 1)
		count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
	if (!flags->minus)
		count += ft_putchar('%');
	return (count);
}
