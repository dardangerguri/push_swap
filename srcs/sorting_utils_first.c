/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:34:47 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/08 18:39:34 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	organize_b(t_stack **a_stack, t_stack **b_stack, int size, int type)
{
	static int	pushed;

	if (b_stack != NULL && type == 0)
	{
		if (pushed > 2 && (*b_stack)->index <= (size / 4))
		{
			if ((*a_stack)->index > size / 2)
				rr(a_stack, b_stack);
			else
				rb(b_stack);
		}
	}
	else if (b_stack != NULL && type == 1)
	{
		if ((*b_stack)->index <= ((size - pushed / 2) - ((size / 4) / 2)))
		{
			if ((*a_stack)->index > (size / 4 * 3))
				rr(a_stack, b_stack);
			else
				rb(b_stack);
		}
	}
	pushed++;
}

static int	push_organize(t_stack **a, t_stack **b, int size, int remaining)
{
	pb(a, b);
	remaining--;
	if (b != NULL && remaining > 6)
	{
		if ((*b)->index <= (size - remaining / 2))
		{
			if ((*a)->index <= size - 3)
				rr(a, b);
			else
				rb(b);
		}
	}
	return (remaining);
}

static void	push(t_stack **a_stack, t_stack **b_stack, int size, int pushed)
{
	int	i;

	i = 0;
	while (size > 6 && i++ < size && pushed < size / 2)
	{
		if ((*a_stack)->index <= ((size / 2)))
		{
			pb(a_stack, b_stack);
			pushed++;
			organize_b(a_stack, b_stack, size, 0);
		}
		else
			ra(a_stack);
	}
	while (size > 6 && i++ < (size + (size / 2 + 1)) && pushed < (size / 4 * 3))
	{
		if ((*a_stack)->index <= (size / 4 * 3))
		{
			pb(a_stack, b_stack);
			organize_b(a_stack, b_stack, size, 1);
			pushed++;
		}
		else
			ra(a_stack);
	}
}

void	keep_three_largest(t_stack **a_stack, t_stack **b_stack, int size)
{
	int	remaining;
	int	i;

	remaining = 0;
	push(a_stack, b_stack, size, 0);
	if (size <= 6)
		remaining = size;
	else
		remaining = (size - (size / 4 * 3));
	i = -1;
	while (remaining > 6 && i++ <= (size / 4))
	{
		if ((*a_stack)->index <= ((size - (size / 4) / 2))
			&& remaining-- > (size / 4) / 2)
			pb(a_stack, b_stack);
		else
			ra(a_stack);
	}
	while (remaining > 3)
	{
		if ((*a_stack)->index <= size - 3)
			remaining = push_organize(a_stack, b_stack, size, remaining);
		else
			ra(a_stack);
	}
}
