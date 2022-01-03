/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:40:24 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 17:40:28 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	instruct_a(t_stack **a, t_stack **b, int i, int size)
{
	int		n;

	n = size - i;
	if (i == 1)
		swap(*a, "sa");
	else if (i < size / 2)
		while (i-- > 0)
			rotate (*a, "ra");
	else if (i >= size / 2 && i != 0)
		while (n-- > 0)
			rrotate (*a, "rra");
	push(b, a, "pb");
}

void	sort_rest(t_stack **b, t_stack **a, t_data *data)
{
	int	i;

	if (*a)
		sort_three(a);
	while (*b)
	{
		i = get_maxindex(*b, &data->size);
		data->n = data->size - i;
		if (i == 1)
			swap(*b, "sb");
		else if (i < data->size / 2)
			while (i-- > 0)
				rotate (*b, "rb");
		else if (i >= data->size / 2 && i != 0)
			while (data->n-- > 0)
				rrotate (*b, "rrb");
		push(a, b, "pa");
	}
}

void	ft_init(int *q, int len)
{
	if (len <= 100)
		*q = 5;
	else
		*q = 10;
}

void	sort(t_stack **a, t_stack **b)
{
	t_data	data;
	int		*tab;
	int		i;
	int		q;

	q = 0;
	tab = remp_tab(*a, &data.len);
	ft_init(&q, data.len);
	data.size = data.len;
	data.pos = data.len / q;
	while (*a)
	{
		while (check_tab(tab, a, data.pos, &i) >= 0)
		{
			instruct_a(a, b, i, data.size);
			data.size = stacklen(*a);
		}
		data.pos += data.len / q;
		if (data.size == 3)
			break ;
		if (data.pos > data.len)
			data.pos = data.len - 1;
	}
	free(tab);
	sort_rest(b, a, &data);
}
