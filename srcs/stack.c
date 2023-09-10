/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:35:04 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/08 22:01:19 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	overflows(t_stack *a_stack, long int number, char *argv)
{
	char	*nbr;
	char	*new_argv;
	int		i;
	int		minus;

	i = 0;
	minus = 0;
	nbr = ft_itoa((int)number);
	if (argv[i] == '-' || argv[i] == '+')
		minus++;
	while ((argv[i] == '0' && argv[1] != '\0')
		|| argv[i] == '-' || argv[i] == '+')
		i++;
	if (minus == 1 && argv[0] != '+')
	{
		new_argv = argv + i;
		if (argv[0] == '-')
			new_argv = ft_strjoin("-", argv + i);
		if (ft_strcmp(nbr, new_argv) != 0)
			ft_error(&a_stack, NULL);
		free(new_argv);
	}
	else if (ft_strcmp(nbr, argv + i) != 0)
		ft_error(&a_stack, NULL);
	free(nbr);
}

t_stack	*filling_stack(char **argv)
{
	t_stack		*a_stack;
	int			i;
	long int	number;

	a_stack = NULL;
	i = 0;
	number = 1;
	if (ft_strncmp(argv[i], "./push_swap", 1) == 0)
		i++;
	while (argv[i] != NULL)
	{
		number = ft_atoi(argv[i]);
		overflows(a_stack, number, argv[i]);
		if ((number < 0 && argv[i][0] != '-') || \
			(number > 0 && argv[i][0] == '-'))
			ft_error(&a_stack, NULL);
		if (number < INT_MIN || number > INT_MAX)
			ft_error(&a_stack, NULL);
		add_node_end(&a_stack, new_stack_node((int)number));
		i++;
	}
	return (a_stack);
}

static int	check_limits(t_stack **stack, int size)
{
	t_stack	*temporary;
	int		flag;

	temporary = *stack;
	flag = 0;
	while (temporary)
	{
		if (temporary->content == INT_MIN)
			temporary->index = 0;
		else if (temporary->content == INT_MAX)
		{
			temporary->index = size - 1;
			flag = 1;
		}
		temporary = temporary->next;
	}
	return (flag);
}

void	indexing_the_stack(t_stack *stack, int stack_size)
{
	t_stack	*node;
	int		max_value;
	int		min_value;

	max_value = INT_MAX;
	if (check_limits(&stack, stack_size))
		stack_size--;
	while (stack_size > 0)
	{
		min_value = INT_MIN;
		node = stack;
		while (node != NULL)
		{
			if (node->content > min_value && node->content < max_value)
			{
				min_value = node->content;
				node->index = stack_size - 1;
			}
			node = node->next;
		}
		max_value = min_value;
		stack_size--;
	}
}

void	assign_position(t_stack **stack)
{
	t_stack	*temporary;
	int		size_of_stack;
	int		i;

	temporary = *stack;
	size_of_stack = get_highest_index(*stack);
	i = 1;
	while (temporary != NULL && i <= size_of_stack)
	{
		temporary->position = i;
		temporary = temporary->next;
		i++;
	}
}
