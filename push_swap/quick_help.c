/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:34:00 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 19:34:02 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_stack **a, t_stack **b, char **s, char *op)
{
	if (strcmp(op, "sa\n") == 0)
		operations(a, b, "sa\n");
	else if (strcmp(op, "sb\n") == 0)
		operations(a, b, "sb\n");
	else if (strcmp(op, "ss\n") == 0)
		operations(a, b, "ss\n");
	else if (strcmp(op, "pa\n") == 0)
		operations(a, b, "pa\n");
	else if (strcmp(op, "pb\n") == 0)
		operations(a, b, "pb\n");
	else if (strcmp(op, "ra\n") == 0)
		operations(a, b, "ra\n");
	else if (strcmp(op, "rb\n") == 0)
		operations(a, b, "rb\n");
	else if (strcmp(op, "rr\n") == 0)
		operations(a, b, "rr\n");
	else if (strcmp(op, "rra\n") == 0)
		operations(a, b, "rra\n");
	else if (strcmp(op, "rrb\n") == 0)
		operations(a, b, "rrb\n");
	else if (strcmp(op, "rrr\n") == 0)
		operations(a, b, "rrr\n");
	join_del(s, op);
}

int		minimum(int a, int b)
{
	return (a < b ? a : b);
}

int		direction(t_stack *b, int *n)
{
	t_stack *s;
	int		h;
	int		i;
	int		k;

	k = 0;
	s = b;
	i = 0;
	while (s)
	{
		s = s->next;
		k++;
	}
	h = k / 2;
	s = b;
	while (s)
	{
		if ((s->ord <= n[1]) && (s->ord >= n[0]) &&
			((MIN(h, k - h)) >= (MIN(i, k - i))))
			h = i;
		s = s->next;
		i++;
	}
	return (h < k - h ? 1 : 0);
}

void	range_max(int *n, int p[3])
{
	p[0] = n[0] + (n[1] - n[0] + 1) / 2;
	p[1] = n[1];
	p[2] = p[1] - p[0] + 1;
}

void	range_min(int *n, int q[3])
{
	q[0] = n[0];
	q[1] = n[0] + (n[1] - n[0] + 1) / 2 - 1;
	q[2] = q[1] - q[0] + 1;
}
