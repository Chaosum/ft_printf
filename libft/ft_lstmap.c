/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:47:10 by mservage          #+#    #+#             */
/*   Updated: 2020/12/06 15:50:44 by mservage         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_malloc_map(t_list *start, void (*del)(void *), int i)
{
	t_list *temp;

	if (i == 0 || start == 0)
		return (NULL);
	temp = start;
	while (temp)
	{
		del(temp->content);
		temp = temp->next;
		free(start);
		start = temp;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*temp;
	t_list	*tempnxt;
	t_list	*tempstart;

	i = 0;
	tempstart = 0;
	while (lst && f)
	{
		if (!(temp = ft_calloc(sizeof(t_list), 1)))
			return (ft_free_malloc_map(tempstart, del, i));
		temp->content = f(lst->content);
		if (i < 1)
		{
			tempstart = temp;
			tempnxt = temp;
		}
		if (i++ > 0)
		{
			tempnxt->next = temp;
			tempnxt = tempnxt->next;
		}
		lst = lst->next;
	}
	return (tempstart);
}
