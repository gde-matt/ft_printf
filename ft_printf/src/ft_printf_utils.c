/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <gde-matt@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:45:54 by gde-matt          #+#    #+#             */
/*   Updated: 2020/12/21 21:17:32 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr(int n)
{
	unsigned	i;
	int			count;

	count = 1;
	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
		count++;
	}
	else
		i = n;
	if (i >= 10)
		count += ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
	return (count);
}

int		ft_isnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_numlen(int num)
{
	int i;

	i = 1;
	if (num < 0)
		i++;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
