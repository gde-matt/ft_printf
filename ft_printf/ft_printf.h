/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-matt <gde-matt@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:42:08 by gde-matt          #+#    #+#             */
/*   Updated: 2020/12/21 21:13:32 by gde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef	struct	s_flags{
	int		minus;
	int		zero;
	int		star;
	int		point;
	int		width;
	int		len;
	char	type;
}				t_flags;

int				ft_isnum(int c);
int				ft_putnbr(int n);
int				ft_numlen(int num);
int				ft_strlen(char *s);
int				ft_putchar(char c);
void			init(t_flags *flags);
int				ft_putflags(int condition, char c);
void			checkflag(const char f, t_flags *flags);
int				readflag(t_flags *flags, const char *str);
int				ft_isconversion(t_flags *flags, va_list args);
char			*ft_itoa_base(unsigned long int n, char type);
int				ft_printf_d(t_flags *flags, va_list args);
int				ft_printf_c(t_flags *flags, va_list args);
int				ft_printf_s(t_flags *flags, va_list args);
int				ft_printf_x(t_flags *flags, va_list args);
int				ft_printf_u(t_flags *flags, va_list args);
int				ft_printf_p(t_flags *flags, va_list args);
int				ft_printf_pct(t_flags *flags, va_list args);
int				ft_printf(const char *str, ...);
void			ft_printf_star(t_flags *flags, va_list args);

#endif
