/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:25:07 by ukim              #+#    #+#             */
/*   Updated: 2020/11/13 18:45:46 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*init_c_malloc(char c, int i)
{
	char *str;

	str = malloc(i + 1);
	str[i] = 0;
	while (i--)
		str[i] = c;
	return (str);
}

char		*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

void	add_space(char **istr, t_flags *fg)
{
	int x;

	x = fg->width - (int)ft_strlen(*istr);
	if (x > 0)
	{
		if (fg->minus)
			*istr = ft_free_strjoin(*istr, init_c_malloc(' ', x));
		else
			*istr = ft_free_strjoin(init_c_malloc(' ', x), *istr);
	}
}

void	add_zero(char **istr, int minus, t_flags *fg)
{
	int nlen;
	int x;

	nlen = (int)ft_strlen(*istr);
	if (fg->precision >= 0)
	{
		x = fg->precision - nlen;
		if (x > 0)
			*istr = ft_free_strjoin(init_c_malloc('0', x), *istr);
	}
	else
	{
		x = fg->width - nlen;
		if (!fg->minus && fg->zero && x > 0)
			*istr = ft_free_strjoin(init_c_malloc('0', x + minus), *istr);
	}
}

int		ft_print_digit(t_flags *flag, va_list ap)
{
	int		slen;
	int		para_int;
	char	*istr;
	char	*mstr;

	change_star(flag, ap);
	para_int = va_arg(ap, int);
	if (para_int < 0)
	{
		slen = -1;
		para_int *= -1;
	}
	istr = ft_itoa(para_int);
	add_zero(&istr, slen, flag);
	if (slen >= flag->width && slen >= flag->precision)
		write(1, istr, slen);
	if (slen == -1)
	{
		mstr = ft_strdup("-");
		istr = ft_free_strjoin(mstr,istr);
	}
	add_space(&istr, flag);
	slen = ft_strlen(istr);
	write(1, istr, slen);
	return (slen);
}
