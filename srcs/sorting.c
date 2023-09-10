/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:01 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:59:09 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_node(t_stack **a_stack, t_stack **b_stack, int index_to_push)
{
	int		highest_index_position;
	int		size;
	int		i;

	size = stack_size(*b_stack);
	assign_position(b_stack);
	highest_index_position = get_index_position(*b_stack, index_to_push);
	i = 1;
	while (highest_index_position <= size / 2 && i++ < highest_index_position)
		rb(b_stack);
	i = 0;
	while (index_to_push != 1 && highest_index_position > size / 2
		&& i++ < size - highest_index_position + 1)
	{
		if (size == 1)
		{
			pa(a_stack, b_stack);
			break ;
		}
		rrb(b_stack);
	}
	pa(a_stack, b_stack);
}

int	count_the_moves(t_stack **b_stack, int index)
{
	int	index_position;
	int	size;
	int	moves;

	assign_position(b_stack);
	index_position = get_index_position(*b_stack, index);
	size = stack_size(*b_stack);
	moves = 0;
	if (index_position == 1)
	{
		moves = 0;
		return (moves);
	}
	if (index_position <= size / 2)
	{
		while (index_position > 1)
		{
			moves++;
			index_position--;
		}
	}
	else if (index_position > size / 2)
		moves = size - index_position + 1;
	return (moves);
}

int	b_sorting_three(t_stack **a_stack, t_stack **b_stack, int size)
{
	int		highest_i;
	int		highest_moves;
	int		second_moves;
	int		third_moves;

	highest_i = get_highest_index(*b_stack);
	highest_moves = count_the_moves(b_stack, highest_i);
	second_moves = count_the_moves(b_stack, highest_i - 1);
	third_moves = count_the_moves(b_stack, highest_i - 2);
	if (highest_moves <= second_moves && highest_moves <= third_moves)
		size = h_1st(a_stack, b_stack, highest_i, size);
	else if (second_moves < highest_moves && second_moves <= third_moves)
		size = h_2nd(a_stack, b_stack, highest_i, size);
	else if (third_moves < highest_moves && third_moves < second_moves)
		size = h_3rd(a_stack, b_stack, highest_i, size);
	return (size);
}

static int	b_sorting(t_stack **a_stack, t_stack **b_stack, int size)
{
	int			highest_index;
	t_sorting	s;

	highest_index = get_highest_index(*b_stack);
	s.first = count_the_moves(b_stack, highest_index);
	s.second = count_the_moves(b_stack, highest_index - 1);
	s.third = count_the_moves(b_stack, highest_index - 2);
	s.fourth = count_the_moves(b_stack, highest_index - 3);
	if (s.first <= s.second && s.first <= s.third
		&& s.first <= s.fourth)
	{
		push_node(a_stack, b_stack, highest_index);
		size--;
	}
	else if (s.second < s.first && s.second <= s.third && s.second <= s.fourth)
		size = second_h(a_stack, b_stack, highest_index, size);
	else if (s.third < s.first && s.third < s.second && s.third <= s.fourth)
		size = h_3rd(a_stack, b_stack, highest_index, size);
	else if (s.fourth < s.first && s.fourth < s.second && s.fourth < s.third)
		size = h_4th(a_stack, b_stack, highest_index, size);
	return (size);
}

void	sorting(t_stack **a_stack, t_stack **b_stack)
{
	int	size;
	int	size_a;

	size_a = get_highest_index(*a_stack);
	keep_three_largest(a_stack, b_stack, size_a);
	sorting_three(a_stack);
	size = stack_size(*b_stack);
	while (*b_stack != NULL && size > 3)
	{
		size = b_sorting(a_stack, b_stack, size);
	}
	if (*b_stack != NULL && size == 3)
		size = b_sorting_three(a_stack, b_stack, size);
	while (*b_stack != NULL)
	{
		pa(a_stack, b_stack);
	}
	if (!ft_issorted(*a_stack))
		sa(a_stack);
}
