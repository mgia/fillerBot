# Filler

Watching algorithms fight can be very satisfying too!
Filler is a game where AI players compete to fill pieces on a map.

A virtual machine organizes the game by:
- Create a game map
- Giving each player a piece to place on the board

On each turn, a player is required to place a piece that extends his current territory. This is done by returning the coordinates of the desired position to the virtual machine in "Y X" format on standard input. 

The player that fills more pieces on the board wins!

## Algorithm

My algorithm focuses on establishing territory early in the game. It is spreads aggressively to the corners of the map and aims to cut off the opponent, causing him to stay localized within a portion of the map.

How the player calculates the best move is by determining the move that allows it to spread the greatest distance. As such, even if the opponent has created density within a part of the map, the algorithm remains ambivalent and creates the barrier around the opponent.

![Start](https://raw.githubusercontent.com/mgia/filler/master/img/start.png)

![Game](https://raw.githubusercontent.com/mgia/filler/master/img/game.png)

For instance, in this game, my player cuts off the left side of the map, creating a foothold on majority of the map, optimizing its chance to win.

## Installation

`make`

## Run

Standard mode : 
`./filler_vm -f [map] -p1 [player1] -p2 [player2]`

Example from the root folder : 
`resources/./filler_vm -f resources/maps/map02 -p1 ./mtan.filler -p2 resources/players/superjeannot.filler

## Final Mark

`100/100`
