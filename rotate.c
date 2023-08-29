/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:31:56 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/14 08:37:38 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*node;
	t_node	*prev;

	if (stack->size == 0)
		return ;
	node = stack->head;
	prev = NULL;
	while (node->next != NULL)
	{
		prev = node;
		node = node->next;
	}
	node->next = stack->head;
	prev = stack->head;
	stack->head = stack->head->next;
	prev->next = NULL;
}

void	ra(t_stack *stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack)
{
	rotate(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
