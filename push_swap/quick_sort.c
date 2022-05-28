/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:48:42 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 18:48:45 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_to_a_help(t_stack **a, t_stack **b, int *p, char **s)
{
	int	k;

	k = 1;
	while (k <= p[2])
	{
		if ((*b)->ord <= p[1] && (*b)->ord >= p[0])
		{
			do_op(a, b, s, "pa\n");
			k++;
		}
		else
			direction(*b, p) ? do_op(a, b, s, "rb\n") : do_op(a, b, s, "rrb\n");
	}
}

static void	divide_to_a(t_stack **a, t_stack **b, int *n, char **s)
{
	int p[3];
	int q[3];

	if (n[2] == 1)
	{
		while (((*b)->ord != n[0]))
			direction(*b, n) ? do_op(a, b, s, "rb\n") : do_op(a, b, s, "rrb\n");
		do_op(a, b, s, "pa\n");
		return ;
	}
	range_max(n, p);
	range_min(n, q);
	divide_to_a_help(a, b, p, s);
	if (!is_sorted_stack(a))
		divide_to_b(a, b, p, s);
	if (is_sorted_stack(a) && *b)
		divide_to_a(a, b, q, s);
}

static void	divide_to_b_help(t_stack **a, t_stack **b, int *q, char **s)
{
	int	k;

	k = 1;
	while (k <= q[2])
	{
		if ((*a)->ord <= q[1] && (*a)->ord >= q[0])
		{
			do_op(a, b, s, "pb\n");
			k++;
		}
		else
		{
			if (direction(*a, q))
				do_op(a, b, s, "ra\n");
			else
				direction(*a, q) ? do_op(a, b, s, "ra\n") :
				do_op(a, b, s, "rra\n");
		}
	}
}

void		divide_to_b(t_stack **a, t_stack **b, int *n, char **s)
{
	int p[3];
	int q[3];

	if (n[2] == 1 && !is_sorted_stack(a))
		while (!is_sorted_stack(a))
			direction(*a, n) ? do_op(a, b, s, "ra\n") : do_op(a, b, s, "rra\n");
	if (is_sorted_stack(a))
		return ;
	range_max(n, p);
	range_min(n, q);
	divide_to_b_help(a, b, q, s);
	if (!is_sorted_stack(a))
		divide_to_b(a, b, p, s);
	divide_to_a(a, b, q, s);
}

void		quick_sort(t_stack **a, int n, char **res)
{
	t_stack	*b;
	int		array[3];

	*res = ft_strnew(0);
	b = NULL;
	array[0] = 1;
	array[1] = n;
	array[2] = n;
	divide_to_b(a, &b, array, res);
}
