/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:33:12 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:59:16 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_string(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temporary;

	if (stack != NULL && (*stack) != NULL)
	{
		while (*stack != NULL)
		{
			temporary = (*stack)->next;
			free(*stack);
			*stack = temporary;
		}
		*stack = NULL;
	}
}

void	ft_error(t_stack **a_stack, t_stack **b_stack)
{
	free_stack(a_stack);
	free_stack(b_stack);
	write(2, "Error\n", 6);
	exit (1);
}
