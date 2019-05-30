/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:14:44 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:07:53 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL. Example
** : ft_strsplit("*hello*fellow***students*", ’*’) returns
** the array ["hello", "fellow", "students"].
*/

static void		freedom(char **fresh)
{
	size_t		i;

	i = 0;
	if (fresh[i])
	{
		while (fresh[i])
		{
			free(fresh[i]);
			i++;
		}
		fresh = NULL;
	}
}

static size_t	size(const char *s, char c)
{
	const char	*s_copy;
	size_t		count;

	s_copy = s;
	count = 0;
	while (*s_copy)
	{
		if (*s_copy == c)
			s_copy++;
		else if (*s_copy != c && *s_copy)
		{
			count += 1;
			while (*s_copy && *s_copy != c)
				s_copy++;
		}
	}
	return (count);
}

static void		creat(char **fresh, const char *s, char c, size_t count)
{
	size_t	i;
	size_t	s_size;

	i = 0;
	while (i < count && *s)
	{
		if (*s == c)
			s++;
		else if (*s != c && *s)
		{
			s_size = 0;
			while (*s && *s != c)
			{
				s_size += 1;
				s++;
			}
			fresh[i] = (char *)malloc(sizeof(char) * s_size + 1);
			if (!fresh[i])
				freedom(fresh);
			i++;
		}
	}
}

static void		copy_str(char **fresh, const char *s, char c, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < count && *s)
	{
		if (*s == c)
			s++;
		else if (*s != c && *s)
		{
			j = 0;
			while (*s && *s != c)
			{
				fresh[i][j] = *s;
				s++;
				j++;
			}
			fresh[i][j] = '\0';
			i++;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	size_t	f_size;

	if (s)
	{
		f_size = size(s, c);
		fresh = (char **)malloc(sizeof(char *) * (f_size + 1));
		if (!fresh)
			return (NULL);
		fresh[f_size] = NULL;
		creat(fresh, s, c, f_size);
		if (!fresh)
			return (NULL);
		copy_str(fresh, s, c, f_size);
		return (fresh);
	}
	return (NULL);
}
