/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:46:53 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/09 14:46:59 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	int		n;
	char	*res;

	a = NULL;
	if (argc == 2)
		string_parsing((&a), argv[1]);
	else
		args_parsing((&a), argc, argv);
	n = stack_size(a);
	if (n > 1)
	{
		duplicate_check(&a, n);
		quick_sort(&a, n, &res);
		optimization(&res);
		ft_putstr(res);
		delete_stack(&a);
		free(res);
	}
	exit(0);
}
