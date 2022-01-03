/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:11:18 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 17:41:22 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	stack_clear(t_stack *lst)
{
	t_stack	*l;

	while (lst)
	{
		l = lst->next;
		free(lst);
		lst = l;
	}
}

int	check_error_rest(char **tab, int n, char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] == '\0')
		{
			destroy_split(n, tab);
			write (1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	check_error(char **tab, int n, char **str)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][0] != '-')
			{
				destroy_split(n, tab);
				write (1, "Error\n", 6);
				return (0);
			}
		}
	}
	if (!check_error_rest(tab, n, str))
		return (0);
	return (1);
}

int	check_repeat(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->value == temp -> value)
			{
				stack_clear(a);
				write (1, "Error\n", 6);
				return (0);
			}
			temp = temp -> next;
		}
		if (a->value > 2147483647 || a->value < -2147483648)
		{
			stack_clear(a);
			write (1, "Error\n", 6);
			return (0);
		}
		a = a -> next;
	}
	return (1);
}
