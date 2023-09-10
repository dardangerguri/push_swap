/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:26:03 by dgerguri          #+#    #+#             */
/*   Updated: 2023/04/05 16:47:49 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	int	temporary;

	if (stack != NULL)
	{
		temporary = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temporary;
		temporary = stack->index;
		stack->index = stack->next->index;
		stack->next->index = temporary;
	}
}

void	sa(t_stack	**a_stack)
{
	swap(*a_stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack	**b_stack)
{
	swap(*b_stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack	**a_stack, t_stack **b_stack)
{
	swap(*a_stack);
	swap(*b_stack);
	ft_putstr_fd("ss\n", 1);
}
