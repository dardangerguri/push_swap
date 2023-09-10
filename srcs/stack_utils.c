/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:35 by dgerguri          #+#    #+#             */
/*   Updated: 2023/04/13 14:42:15 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_last_node(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*new_stack_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->index = 0;
	new_node->position = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_end(t_stack **lst, t_stack *new)
{
	t_stack	*temporary_n;

	if (lst == NULL)
		ft_error(NULL, NULL);
	if (new == NULL)
		ft_error(lst, NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		temporary_n = get_last_node(*lst);
		temporary_n->next = new;
	}
}

void	add_node_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int	stack_size(t_stack *a_stack)
{
	int	size;

	size = 0;
	if (a_stack == NULL)
		return (0);
	while (a_stack != NULL)
	{
		a_stack = a_stack->next;
		size++;
	}
	return (size);
}
