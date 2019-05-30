/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:16:22 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 16:56:39 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function
** returns NULL.
** Param. #1 A pointer’s to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
** Return value The new list.
*/

static t_list	*ft_body(t_list *new_link, t_list *new_temp,
				t_list *(*f)(t_list *elem), size_t flag)
{
	t_list	*temp;

	if (flag == 0)
	{
		new_link = (*f)(new_temp);
		free(new_temp);
		return (new_link);
	}
	temp = (*f)(new_temp);
	new_link->next = temp;
	free(new_temp);
	return (temp);
}

static t_list	*ft_del(t_list *head)
{
	t_list	*temp;
	void	**ast;
	void	**content;

	if (head)
	{
		temp = head;
		while (temp)
		{
			ast = (void **)&temp;
			content = &temp->content;
			temp = temp->next;
			ft_memdel(content);
			ft_memdel(ast);
		}
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_link;
	t_list	*new_temp;
	t_list	*head;
	size_t	flag;

	flag = 0;
	while (lst)
	{
		if ((new_temp = ft_lstnew(lst->content, lst->content_size)))
		{
			if (flag == 0)
			{
				new_link = ft_body(new_link, new_temp, (*f), flag);
				head = new_link;
				flag++;
			}
			else
				new_link = ft_body(new_link, new_temp, (*f), flag);
			lst = lst->next;
		}
		else
			return (ft_del(head));
	}
	return (head);
}
