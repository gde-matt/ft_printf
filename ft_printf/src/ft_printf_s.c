/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <gde-matt@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:45:14 by gde-matt          #+#    #+#             */
/*   Updated: 2020/12/21 21:16:26 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printf_sa(t_flags *flags, int len, char *str)
{
	int count;

	count = 0;
	while ((flags->width-- - len) && !(flags->minus))
		count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
	while (*str)
		count += ft_putchar(*str++);
	while ((flags->width-- - len + 1) && flags->minus)
		count += ft_putchar(' ');
	return (count);
}

static int	ft_printf_sb(t_flags *flags, int point, char *str)
{
	int count;

	count = 0;
	while ((flags->width-- - point) && !(flags->minus))
		count += ft_putchar(' ');
	while (flags->point-- && *str)
		count += ft_putchar(*str++);
	while ((flags->width-- - point + 1) && flags->minus)
		count += ft_putchar(' ');
	return (count);
}

static int	ft_printf_sc(t_flags *flags, int len, int point, char *str)
{
	int count;

	count = 0;
	if (flags->point == 0 && flags->width == 0)
		return (0);
	while ((flags->point-- > len) && (flags->width > len) && !flags->minus)
	{
		count += ft_putchar(' ');
		flags->width--;
	}
	while (!len && (flags->width-- > 0) && !flags->minus)
		count += ft_putchar(' ');
	while (point-- && *str)
	{
		count += ft_putchar(*str++);
		flags->width--;
	}
	while (flags->minus && flags->width-- > 0)
		count += ft_putchar(' ');
	return (count);
}

int			ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		len;
	int		point;

	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	count = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	point = flags->point > len ? len : flags->point;
	if (flags->len == 0 || (flags->point == -1 && len >= flags->width))
		while (*str)
			count += ft_putchar(*str++);
	else if (flags->point == -1 && flags->width > len)
		count += ft_printf_sa(flags, len, str);
	else if (flags->width > flags->point)
		count += ft_printf_sb(flags, point, str);
	else if (flags->width <= flags->point)
		count += ft_printf_sc(flags, len, point, str);
	return (count);
}
