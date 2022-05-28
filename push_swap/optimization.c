/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:13:51 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 19:13:53 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_replace_help(char **str, char *to_replace, int k, int i)
{
	char	*before;
	char	*after;
	char	*new;

	before = NULL;
	after = NULL;
	before = ft_strsub(*str, 0, k);
	after = ft_strdup(&((*str)[k + i]));
	free(*str);
	*str = NULL;
	new = ft_strjoin(before, to_replace);
	free(before);
	*str = ft_strjoin(new, after);
	free(new);
	free(after);
}

static void	ft_replace(char **str, char *to_find, char *to_replace)
{
	int		i;
	int		k;

	if (to_find[0] == '\0')
		return ;
	k = 0;
	while ((*str)[k] != '\0')
	{
		i = 0;
		while (to_find[i] == (*str)[k + i])
		{
			i++;
			if (to_find[i] == '\0')
			{
				ft_replace_help(str, to_replace, k, i);
				return ;
			}
		}
		k++;
	}
}

void		optimization(char **res)
{
	char	*new;

	new = ft_strnew(0);
	while (ft_strlen(*res) != ft_strlen(new))
	{
		free(new);
		new = ft_strdup(*res);
		ft_replace(res, "\npa\npb\n", "\n");
		ft_replace(res, "\npb\npa\n", "\n");
		ft_replace(res, "\nra\nrra\n", "\n");
		ft_replace(res, "\nrra\nra\n", "\n");
		ft_replace(res, "\nrb\nrrb\n", "\n");
		ft_replace(res, "\nrrb\nrb\n", "\n");
		ft_replace(res, "\nra\nrb\n", "\nrr\n");
		ft_replace(res, "\nrra\nrrb\n", "\nrrr\n");
		ft_replace(res, "\nsa\nsb\n", "\nss\n");
		ft_replace(res, "\nsa\nsa\n", "\n");
		ft_replace(res, "\nsb\nsb\n", "\n");
		ft_replace(res, "\npb\nrra\npa\n", "\nrra\nsa\n");
	}
	free(new);
}
