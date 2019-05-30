/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:04:10 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 19:46:20 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the integer n to the file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long int	num;
	unsigned char		nbr;

	if (fd >= 0)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n + 1;
			num = n * -1;
			num = num + 1;
		}
		else
			num = n;
		if (num < 10)
		{
			nbr = num + '0';
			write(fd, &nbr, 1);
		}
		else if (num >= 10)
		{
			ft_putnbr_fd((int)(num / 10), fd);
			ft_putnbr_fd((int)(num % 10), fd);
		}
	}
}
