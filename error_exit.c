/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:02:30 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/16 13:32:37 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	error_check(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		error_exit();
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error_exit();
		i ++;
	}
	if (str[i - 1] == '-' || str[i - 1] == '+')
		error_exit();
}
