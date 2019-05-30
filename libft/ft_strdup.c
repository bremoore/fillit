/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:00:04 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/21 10:30:09 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it. The pointer may subsequently
** be used as an argument to the function free(3). If insufficient memory is
** available, NULL is returned
*/

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*temp;

	i = 0;
	len = (int)ft_strlen(s1);
	temp = (char *)malloc(sizeof(*s1) * len + 1);
	if (!(temp))
	{
		return (NULL);
	}
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[len] = '\0';
	return (temp);
}
