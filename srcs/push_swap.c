/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:01:57 by dgerguri          #+#    #+#             */
/*   Updated: 2023/04/03 19:06:28 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_highest_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack != NULL)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

int	get_index_position(t_stack *stack, int highest_index)
{
	int	i;

	i = stack->position;
	while (stack != NULL)
	{
		if (stack->index == highest_index)
			i = stack->position;
		stack = stack->next;
	}
	return (i);
}

void	sorting_three(t_stack **a_stack)
{
	int	highest_index;

	highest_index = get_highest_index(*a_stack);
	if ((*a_stack)->index == highest_index)
		ra(a_stack);
	if ((*a_stack)->next->index == highest_index)
		rra(a_stack);
	if ((*a_stack)->index > (*a_stack)->next->index)
		sa(a_stack);
}

int	push_swap(t_stack **a_stack, t_stack **b_stack, int size_of_stack)
{
	if (ft_issorted(*a_stack))
		return (0);
	else if (size_of_stack == 2)
		sa(a_stack);
	else if (size_of_stack == 3)
		sorting_three(a_stack);
	else if (size_of_stack > 3)
		sorting(a_stack, b_stack);
	return (0);
}
