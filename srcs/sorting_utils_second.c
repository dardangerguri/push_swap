/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:18:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/04 20:29:17 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	second_h(t_stack **a_stack, t_stack **b_stack, int highest_i, int size)
{
	push_node(a_stack, b_stack, highest_i - 1);
	push_node(a_stack, b_stack, highest_i);
	sa(a_stack);
	size = size - 2;
	return (size);
}

int	h_1st(t_stack **a_stack, t_stack **b_stack, int highest_i, int size)
{
	int	highest_moves;
	int	second_moves;

	push_node(a_stack, b_stack, highest_i);
	highest_i = get_highest_index(*b_stack);
	highest_moves = count_the_moves(b_stack, highest_i);
	second_moves = count_the_moves(b_stack, highest_i - 1);
	if (highest_moves < second_moves || highest_moves == second_moves)
	{
		push_node(a_stack, b_stack, highest_i);
		push_node(a_stack, b_stack, highest_i - 1);
	}
	else if (highest_moves > second_moves)
	{
		push_node(a_stack, b_stack, highest_i - 1);
		push_node(a_stack, b_stack, highest_i);
		sa(a_stack);
	}
	size = size - 3;
	return (size);
}

int	h_2nd(t_stack **a_stack, t_stack **b_stack, int highest_i, int size)
{
	int	highest_moves;
	int	second_moves;

	push_node(a_stack, b_stack, highest_i - 1);
	highest_i = get_highest_index(*b_stack);
	highest_moves = count_the_moves(b_stack, highest_i);
	second_moves = count_the_moves(b_stack, highest_i - 2);
	if (highest_moves < second_moves || highest_moves == second_moves)
	{
		push_node(a_stack, b_stack, highest_i);
		sa(a_stack);
		push_node(a_stack, b_stack, highest_i - 2);
	}
	else if (highest_moves > second_moves)
	{
		push_node(a_stack, b_stack, highest_i - 2);
		ra(a_stack);
		push_node(a_stack, b_stack, highest_i);
		sa(a_stack);
		rra(a_stack);
	}
	size = size - 3;
	return (size);
}

int	h_3rd(t_stack **a_stack, t_stack **b_stack, int highest_i, int size)
{
	int	highest_moves;
	int	second_moves;

	push_node(a_stack, b_stack, highest_i - 2);
	ra(a_stack);
	highest_i = get_highest_index(*b_stack);
	highest_moves = count_the_moves(b_stack, highest_i);
	second_moves = count_the_moves(b_stack, highest_i - 1);
	if (highest_moves < second_moves || highest_moves == second_moves)
	{
		push_node(a_stack, b_stack, highest_i);
		push_node(a_stack, b_stack, highest_i - 1);
	}
	else if (highest_moves > second_moves)
	{
		push_node(a_stack, b_stack, highest_i - 1);
		push_node(a_stack, b_stack, highest_i);
		sa(a_stack);
	}
	rra(a_stack);
	size = size - 3;
	return (size);
}

int	h_4th(t_stack **a_stack, t_stack **b_stack, int highest_i, int size)
{
	push_node(a_stack, b_stack, highest_i - 3);
	size--;
	ra(a_stack);
	size = b_sorting_three(a_stack, b_stack, size);
	rra(a_stack);
	return (size);
}
