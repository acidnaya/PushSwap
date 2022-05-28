/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:05:24 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 19:05:27 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*merge(t_stack *sort1, t_stack *sort2)
{
	t_stack	*ptr1;
	t_stack	*ptr2;
	t_stack	*prev;
	t_stack	*first;

	ptr1 = sort1;
	ptr2 = sort2;
	first = (sort1)->num <= (sort2)->num ? sort1 : sort2;
	while (ptr1 && ptr2)
	{
		prev = ptr1;
		while (ptr1 && ptr1->num <= ptr2->num)
		{
			prev = ptr1;
			ptr1 = ptr1->next;
		}
		prev->num <= ptr2->num ? prev->next = ptr2 : prev->next;
		while (ptr1 && ptr2 && ptr1->num > ptr2->num)
		{
			prev = ptr2;
			ptr2 = ptr2->next;
		}
		ptr1 ? prev->next = ptr1 : prev->next;
	}
	return (first);
}

t_stack			*merge_sort(t_stack *a, int n)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*pr;
	int		i;

	if (!a || !(a->next))
		return (a);
	a1 = a;
	a2 = a;
	pr = a2;
	i = n / 2;
	while (i > 0)
	{
		pr = a2;
		a2 = a2->next;
		i--;
	}
	pr->next = NULL;
	return (merge(merge_sort(a1, n / 2), merge_sort(a2, n / 2 + n % 2)));
}
