/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:50:37 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/14 08:37:07 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int		data;
	t_node	*node;
	t_node	*prev;

	data = 0;
	if (stack->size == 0)
		return ;
	node = stack->head;
	prev = NULL;
	while (node->next != NULL)
	{
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
	data = node->data;
	free(node);
	stack->size --;
	push(stack, data);
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
