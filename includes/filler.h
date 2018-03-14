/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:05:58 by mtan              #+#    #+#             */
/*   Updated: 2018/03/14 12:06:00 by mtan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <libft.h>

typedef struct		s_state
{
	char			**map;
	char			**piece;
	char			player;
	char			opponent;
	int				rows;
	int				cols;
}					t_state;

/*
**	Main functions
*/

int					main(void);
int					play(t_state *game);

/*
**	Initializers
*/

void				assign_players(t_state *game);
void				get_map_size(t_state *game);
void				get_map(t_state *game);
void				get_piece(t_state *game);
void				initialize_turn(t_state *game);

/*
**	Checkers
*/

int					check(t_state *game, int x, int y, int *placed);
int					place_piece(t_state *game, int top_x, int top_y);
int					*is_valid_move(t_state *game, int i, int j);
t_list				*get_legal_moves(t_state *game);

/*
**	Movers
*/

int					is_best_move(int *pos, int oldx, int oldy, int *dir);
int					*max_distance(t_state *game, int i, int j);
int					*get_best_direction(t_state *game, int avg_x, int avg_y);
void				make_move(t_state *game, t_list *moves);

/*
**	Helpers
*/

int					ft_abs(int n);
void				free_item(char ***src);
void				free_game(t_state *game);

#endif
