/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:21:44 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 18:04:16 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
*/

static int	i_size(int c)
{
	int					size;
	unsigned long int	num;

	size = 0;
	if (c == 0)
	{
		size = 1;
		return (size);
	}
	if (c > 0)
		num = c;
	if (c < 0)
	{
		size += 1;
		c = c + 1;
		c *= -1;
		num = (unsigned long int)c;
		num = num + 1;
	}
	while (num)
	{
		num = num / 10;
		size += 1;
	}
	return (size);
}

static void	mkstr(int n, char *str, int i)
{
	unsigned long int num;

	if (n < 0)
	{
		str[0] = '-';
		n = (n + 1);
		n *= -1;
		num = (unsigned long int)n;
		num = num + 1;
		while (--i > 0)
		{
			str[i] = (num % 10) + '0';
			num = num / 10;
		}
	}
	else if (n >= 0)
	{
		num = n;
		while (--i >= 0)
		{
			str[i] = (num % 10) + '0';
			num = num / 10;
		}
	}
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		i;

	size = i_size(n);
	i = size;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size] = '\0';
		mkstr(n, str, i);
		return (str);
	}
	return (NULL);
}
