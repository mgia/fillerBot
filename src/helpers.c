/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:22:54 by mtan              #+#    #+#             */
/*   Updated: 2018/03/14 12:22:56 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_abs(int n)
{
	return ((n < 0) ? (-n) : n);
}

void	free_item(char ***src)
{
	char	**arr;
	int		i;

	arr = *src;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	*src = NULL;
}

void	free_game(t_state *game)
{
	free_item(&(game->map));
	free_item(&(game->piece));
}
