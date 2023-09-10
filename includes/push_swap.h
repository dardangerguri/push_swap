/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:21:39 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/09 17:11:15 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	struct s_stack	*next;
}				t_stack;

typedef struct s_sorting
{
	int			first;
	int			second;
	int			third;
	int			fourth;
}		t_sorting;

/* main */
int		ft_issorted(t_stack *a_stack);

/* validation */
int		input_validation(char **argv);

/* stack initialization */
t_stack	*filling_stack(char **argv);
void	indexing_the_stack(t_stack *a_stack, int size_of_stack);
void	assign_position(t_stack **stack);

/* stack utils */
t_stack	*get_last_node(t_stack *lst);
t_stack	*new_stack_node(int content);
void	add_node_end(t_stack **lst, t_stack *new);
void	add_node_front(t_stack **lst, t_stack *new);
int		stack_size(t_stack *a_stack);

/* push_swap */
int		push_swap(t_stack **a_stack, t_stack **b_stack, int size_of_stack);
int		get_highest_index(t_stack *a_stack);
int		get_index_position(t_stack *stack, int highest_index);
void	sorting_three(t_stack **a_stack);

/* sorting */
int		count_the_moves(t_stack **b_stack, int index);
void	push_node(t_stack **a_stack, t_stack **b_stack, int index_to_push);
void	sorting(t_stack **a_stack, t_stack **b_stack);
int		b_sorting_three(t_stack **a_stack, t_stack **b_stack, int size);

/* sorting utils first */
void	keep_three_largest(t_stack **a_stack, t_stack **b_stack, int size);

/* sorting utils second */
int		second_h(t_stack **a_stack, t_stack **b_stack, int highest_i, int size);
int		h_1st(t_stack **a_stack, t_stack **b_stack, int highest_i, int size);
int		h_2nd(t_stack **a_stack, t_stack **b_stack, int highest_i, int size);
int		h_3rd(t_stack **a_stack, t_stack **b_stack, int highest_i, int size);
int		h_4th(t_stack **a_stack, t_stack **b_stack, int highest_i, int size);

/* swap*/
void	sa(t_stack	**a_stack);
void	sb(t_stack	**b_stack);
void	ss(t_stack	**a_stack, t_stack **b_stack);

/* push */
void	pa(t_stack **a_stack, t_stack **b_stack);
void	pb(t_stack **a_stack, t_stack **b_stack);

/* rotate */
void	ra(t_stack **a_stack);
void	rb(t_stack **a_stack);
void	rr(t_stack **a_stack, t_stack **b_stack);

/* reverse */
void	rra(t_stack **a_stack);
void	rrb(t_stack **a_stack);
void	rrr(t_stack **a_stack, t_stack **b_stack);

/* free and error */
void	ft_error(t_stack **a_stack, t_stack **b_stack);
void	free_stack(t_stack **stack);
void	free_string(char **str);

#endif
