/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:22:54 by mtan              #+#    #+#             */
/*   Updated: 2018/03/14 12:22:56 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_state *game, int x, int y, int *placed)
{
	if (x < 0 || y < 0 || x >= game->rows || y >= game->cols)
		return (0);
	else if (game->map[x][y] == game->opponent ||
			game->map[x][y] == ft_toupper(game->opponent))
		return (0);
	else if (*placed && (game->map[x][y] == game->player ||
			game->map[x][y] == ft_toupper(game->player)))
		return (0);
	else if (game->map[x][y] == game->player ||
			game->map[x][y] == ft_toupper(game->player))
		*placed = 1;
	return (1);
}

int		place_piece(t_state *game, int top_x, int top_y)
{
	int		placed;
	int		x;
	int		y;

	x = 0;
	y = 0;
	placed = 0;
	while (game->piece[x])
	{
		y = 0;
		while (game->piece[x][y])
		{
			if (game->piece[x][y] == '*')
				if (!check(game, top_x + x, top_y + y, &placed))
					return (0);
			y++;
		}
		x++;
	}
	if (placed == 0)
		return (0);
	return (1);
}

int		*is_valid_move(t_state *game, int i, int j)
{
	int	*ret;
	int x;
	int y;

	ret = malloc(sizeof(int) * 2);
	x = 0;
	while (game->piece[x])
	{
		y = 0;
		while (game->piece[x][y])
		{
			if (game->piece[x][y] == '*')
				if (place_piece(game, i - x, j - y))
				{
					ret[0] = i - x;
					ret[1] = j - y;
					return (ret);
				}
			y++;
		}
		x++;
	}
	return (NULL);
}

t_list	*get_legal_moves(t_state *game)
{
	t_list	*moves;
	int		x;
	int		y;
	int		*ret;

	moves = NULL;
	x = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->cols && game->map[x][y])
		{
			if ((ret = is_valid_move(game, x, y)))
			{
				ft_lstadd(&moves, ft_lstnew((int[]) {ret[0], ret[1]}, 8));
				free(ret);
				ret = NULL;
			}
			y++;
		}
		x++;
	}
	return (moves);
}
