/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:49:29 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/14 08:38:29 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	void	swap(t_stack *stack)
{
	int		data1;
	int		data2;
	t_node	*node1;
	t_node	*node2;

	if (stack->size < 2)
		return ;
	node1 = stack->head;
	node2 = node1->next;
	data1 = node1->data;
	data2 = node2->data;
	node1->data = data2;
	node2->data = data1;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
