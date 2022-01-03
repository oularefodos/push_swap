/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:02:07 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 17:40:00 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*ft_alloc(t_stack *a)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
	{
		free(temp);
		stack_clear(a);
		exit (0);
	}
	return (temp);
}

int	stack_init(int ac, char **str, t_stack **a)
{
	int		j;
	t_stack	*temp;
	char	**tab;

	ac = ac - 1;
	while (ac > 0)
	{
		tab = ft_split(str[ac], ' ');
		j = taille_tab(str[ac], ' ') - 1;
		if (!check_error(tab, j, str))
			return (0);
		while (j >= 0)
		{
			temp = ft_alloc(*a);
			temp->value = ft_atoi(tab[j]);
			temp->next = *a;
			*a = temp;
			j--;
		}
		destroy_split(taille_tab(str[ac], ' ') - 1, tab);
		ac--;
	}
	return (1);
}

void	sort_rest(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "ss\n", ft_strlen(line)) && *a && *b)
	{
		swap_b(*a);
		swap_b(*b);
	}
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)) && *a && *b)
	{
		rotate_b(*a);
		rotate_b(*b);
	}
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)) && *a && *b)
	{
		rrotate_b(*a);
		rrotate_b(*b);
	}
	else
	{
		write (1, "Error\n", 6);
		exit(1);
	}
}

void	sort_stack(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)) && *a)
		swap_b(*a);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)) && *a)
		rotate_b(*a);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)) && *a)
		rrotate_b(*a);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)) && *a)
		push_b(b, a);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)) && *b)
		swap_b(*b);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)) && *b)
		rotate_b(*b);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)) && *b)
		rrotate_b(*b);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)) && *b)
		push_b(a, b);
	else
		sort_rest(a, b, line);
	free(line);
}	

int	main(int ac, char **str)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (!stack_init(ac, str, &a) || !check_repeat(a))
		return (0);
	line = get_next_line(0);
	while (line)
	{
		sort_stack(&a, &b, line);
		line = get_next_line(0);
	}
	if (check_sort(a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	stack_clear(a);
	return (0);
}
