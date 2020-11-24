/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:25:18 by ukim              #+#    #+#             */
/*   Updated: 2020/11/24 17:28:08 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*change_base_to_string(unsigned long long num, char *base)
{
	int				len;
	char			*str;
	int				base_len;

	base_len = ft_strlen(base);
	len = ull_length(num, base_len);
	if (num == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	while (num > 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

int					ft_print_ux(t_flags *flag, va_list ap, char *base)
{
	int				t_len;
	unsigned int	num;
	char			*str;
	char			*tmp[2];
	char			c;

	num = va_arg(ap, unsigned int);
	str = change_base_to_string(num, base);
	if (num == 0 && flag->precision == 0 && flag->dot == 1)
	{
		free(str);
		str = ft_strdup("");
	}
	t_len = flag->precision - ft_strlen(str);
	if (t_len > 0)
	{
		tmp[0] = init_c_malloc('0', t_len);
		str = ft_free_strjoin(tmp[0], str);
	}
	t_len = flag->width - ft_strlen(str);
	if (t_len > 0)
	{
		if (flag->minus)
		{
			tmp[0] = str;
			tmp[1] = init_c_malloc(' ', t_len);
		}
		else
		{
			c = flag->zero && flag->pf == 0 ? '0' : ' ';
			tmp[0] = init_c_malloc(c, t_len);
			tmp[1] = str;
		}
		str = ft_free_strjoin(tmp[0], tmp[1]);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
