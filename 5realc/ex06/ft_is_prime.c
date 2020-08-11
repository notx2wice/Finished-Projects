/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:11:52 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 12:14:49 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int x;
	int temp;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	temp = nb / 2;
	while (x <= temp)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}
