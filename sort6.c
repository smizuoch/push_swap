/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:51:51 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/16 14:12:11 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	findmin(t_stack *stack)
{
	int		min;
	t_node	*node;

	min = stack->head->data;
	node = stack->head;
	while (node != NULL)
	{
		if (min > node->data)
			min = node->data;
		node = node->next;
	}
	return (min);
}

int	findmax(t_stack *stack)
{
	int		max;
	t_node	*node;

	max = stack->head->data;
	node = stack->head;
	while (node != NULL)
	{
		if (max < node->data)
			max = node->data;
		node = node->next;
	}
	return (max);
}

void	sort3(t_stack *a)
{
	int		data1;
	int		data2;
	int		data3;

	data1 = a->head->data;
	data2 = a->head->next->data;
	data3 = a->head->next->next->data;
	if (data1 < data2 && data2 > data3 && data1 < data3)
	{
		rra(a);
		sa(a);
	}
	else if (data1 > data2 && data2 < data3 && data1 < data3)
		sa(a);
	else if (data1 < data2 && data2 > data3)
		rra(a);
	else if (data1 > data2 && data2 < data3)
		ra(a);
	else if (data1 > data2 && data2 > data3)
	{
		sa(a);
		rra(a);
	}
}

void	sort4_5_6(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->head->data == findmin(a))
			pb(a, b);
		if (a->head->next->data == findmin(a))
			ra(a);
		else
			rra(a);
	}
	sort3(a);
	while (b->size > 0)
	{
		if (b->head->data == findmax(b))
			pa(a, b);
		else
			rb(b);
	}
}

void	sort6(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->head->data > a->head->next->data)
		{
			sa(a);
		}
		return ;
	}
	else if (a->size == 3)
	{
		sort3(a);
		return ;
	}
	else if (a->size == 4 || a->size == 5 || a->size == 6)
	{
		sort4_5_6(a, b);
		return ;
	}
}
