/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:44:56 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 17:44:58 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	destroy_split(int n, char **str)
{
	while (n >= 0)
	{
		free(str[n]);
		n--;
	}
	free(str);
}

int	stacklen(t_stack *a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (-1);
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	check_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_maxindex(t_stack *a, int *i)
{
	int	temp;
	int	max;

	*i = 0;
	temp = 0;
	max = a->value;
	while (a)
	{
		if (max < a->value)
		{
			max = a->value;
			temp = *i;
		}
		(*i)++;
		a = a->next;
	}
	return (temp);
}

int	get_minindex(t_stack *a, int *tail)
{
	int	temp;
	int	min;

	temp = 0;
	*tail = 0;
	min = a->value;
	while (a)
	{
		if (min > a->value)
		{
			min = a->value;
			temp = *tail;
		}
		a = a->next;
		(*tail)++;
	}
	return (temp);
}
