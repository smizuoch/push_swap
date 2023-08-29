/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_same.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:03:10 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/27 09:07:13 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	chack_same_num(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack->head;
	while (node1 != NULL)
	{
		node2 = node1->next;
		while (node2 != NULL)
		{
			if (node1->data == node2->data)
			{
				stack_free(stack);
				error_exit();
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
}
