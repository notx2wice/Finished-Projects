/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:47:31 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 12:48:54 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = argc - 1;
	while (x > 0)
	{
		y = 0;
		while (argv[x][y])
		{
			write(1, &argv[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x--;
	}
	return (0);
}
