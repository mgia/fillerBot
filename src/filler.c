/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:22:54 by mtan              #+#    #+#             */
/*   Updated: 2018/03/14 12:22:56 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		play(t_state *game)
{
	t_list	*moves;

	initialize_turn(game);
	moves = get_legal_moves(game);
	if (!moves)
	{
		ft_printf("0 0\n");
		exit(1);
	}
	make_move(game, moves);
	free_game(game);
	return (1);
}

int		main(void)
{
	t_state	*game;

	game = malloc(sizeof(t_state));
	assign_players(game);
	while (play(game))
		continue ;
	return (0);
}
