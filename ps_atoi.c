/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:59:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/16 13:38:37 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	chack_flow(long long n, int sign)
{
	if (n * sign > INT_MAX)
		error_exit();
	else if (n * sign < INT_MIN)
		error_exit();
}

static long int	check_overflow(long long n, int sign, const char *str)
{
	if (n * sign > LONG_MAX / 10)
		error_exit();
	else if (n * sign < LONG_MIN / 10)
		error_exit();
	if (n * sign == LONG_MAX / 10 && *str >= '7')
		error_exit();
	else if (n * sign == LONG_MIN / 10 && *str >= '8')
		error_exit();
	return (1);
}

long	ps_atoi(const char *str)
{
	long long int	n;
	int				sign;
	int				ret;

	n = 0;
	ret = 0;
	sign = 1;
	error_check(str);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str ++ == '-')
			sign = -1;
	}
	while ('0' <= *str && *str <= '9')
	{
		check_overflow(n, sign, str);
		n = n * 10 + (*str - '0');
		str ++;
	}
	chack_flow(n, sign);
	return (n * sign);
}
