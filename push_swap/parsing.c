/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:20:21 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 17:20:22 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		string_parsing(t_stack **a, char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (!(atoi_stat(&(s[i]), &n)) || !(add_elem_back(a, n)))
		{
			message(a, NULL, -1, NULL);
		}
		while ((s[i] >= '0') && (s[i] <= '9'))
			i++;
		while (s[i] == ' ')
			i++;
	}
}

void		args_parsing(t_stack **a, int ac, char **av)
{
	int	i;
	int	n;

	i = 0;
	while (++i < ac)
		if (!(atoi_stat(av[i], &n)) || !(add_elem_back(a, n)))
			message(a, NULL, -1, NULL);
}
