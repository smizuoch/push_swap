/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:30:22 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/26 17:14:51 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_b500(t_stack *a, t_stack *b, int *arr, int size)
{
	int	i;
	int	j;
	int	median;

	i = 0;
	j = 0;
	median = size / 20;
	while (a->size)
	{
		if (a->head->data <= arr[median + j])
		{
			pb(a, b);
			if (median + j < size - 1)
				j ++;
			if (b->head->data >= arr[median + j - 25] && b->size != size)
				rb(b);
		}
		else
			ra(a);
	}
}

void	push_b100(t_stack *a, t_stack *b, int *arr, int size)
{
	int	i;
	int	j;
	int	median;

	i = 0;
	j = 0;
	median = size / 6;
	while (a->size)
	{
		if (a->head->data <= arr[median + j])
		{
			pb(a, b);
			if (median + j < size - 1)
				j ++;
			if (b->head->data >= arr[median + j - 15] && b->size != size)
				rb(b);
		}
		else
			ra(a);
	}
}

void	find_b(t_stack *b, int *arr, int size)
{
	int		i;
	int		f;
	t_node	*tmp;

	f = 0;
	i = b->size / 2;
	tmp = b->head;
	while (i)
	{
		if (tmp->data == arr[size - 1])
		{
			f = 1;
			break ;
		}
		tmp = tmp->next;
		i --;
	}
	if (f == 1)
		rb(b);
	else
		rrb(b);
}

void	pop_all(t_stack *b, t_stack *a, int *arr, int size)
{
	while (b->size)
	{
		if (b->head->data == arr[size - 1])
		{	
			pa(a, b);
			size --;
		}
		else if (b->head->next->data == arr[size - 1])
			sb(b);
		else
			find_b(b, arr, size);
	}
	free(arr);
}

void	sort_push_swap(t_stack *a, t_stack *b)
{
	int		*arr;
	int		i;
	int		size;
	t_node	*tmp;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		error_exit();
	i = 0;
	size = a->size;
	tmp = a->head;
	while (i < size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	quick_sort(arr, 0, a->size - 1);
	if (a->size <= 300)
		push_b100(a, b, arr, size);
	else
		push_b500(a, b, arr, size);
	pop_all(b, a, arr, size);
}
