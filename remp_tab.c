/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:30:17 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 17:42:27 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	check_tab(int *tab, t_stack **a, int len, int *i)
{
	t_stack	*temp;

	temp = *a;
	*i = 0;
	if (*a == NULL)
		return (-1);
	while (temp)
	{
		if (temp->value <= tab[len])
			return (*i);
		(*i)++;
		temp = temp->next;
	}
	return (-1);
}

int	*remp_tab(t_stack *a, int *size)
{
	t_stack	*temp;
	int		*tab;

	*size = 0;
	temp = a;
	*size = stacklen(temp);
	tab = (int *)malloc(sizeof(int) * (*size));
	if (!tab)
	{
		stack_clear(a);
		exit (0);
	}
	*size = 0;
	while (a)
	{
		tab[*size] = a->value;
		a = a->next;
		(*size)++;
	}
	sort_tab(tab, *size);
	return (tab);
}
