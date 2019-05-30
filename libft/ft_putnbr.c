/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:14:13 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 19:43:59 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the integer n to the standard output.
*/

void	ft_putnbr(int n)
{
	unsigned long int	num;
	unsigned char		nbr;

	if (n < 0)
	{
		write(1, "-", 1);
		n = n + 1;
		num = n * -1;
		num = num + 1;
	}
	else
		num = n;
	if (num < 10)
	{
		nbr = num + '0';
		write(1, &nbr, 1);
	}
	else if (num >= 10)
	{
		ft_putnbr((int)(num / 10));
		ft_putnbr((int)(num % 10));
	}
}
