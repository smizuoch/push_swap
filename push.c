/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:17:47 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/27 09:16:31 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	if (stack->size == stack->max)
		error_exit();
	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		error_exit();
	new_node->data = data;
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size ++;
}

int	pop(t_stack *stack)
{
	int		data;
	t_node	*node;

	if (stack->size == 0)
		error_exit();
	node = stack->head;
	stack->head = node->next;
	stack->size --;
	data = node->data;
	free(node);
	return (data);
}

void	pa(t_stack *a, t_stack *b)
{
	int	data;

	if (b->size == 0)
		return ;
	data = pop(b);
	push(a, data);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	int	data;

	if (a->size == 0)
		return ;
	data = pop(a);
	push(b, data);
	ft_putendl_fd("pb", 1);
}
