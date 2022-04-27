/* Team 20  */
/* File name: Board.h */
/* author: Kevin Zhu & Yuan Wang */
/* Date: 2022/04/11 */

#ifndef BOARD_H
#define BOARD_H


#include <stdlib.h>
#include "Pieces.h"
#include "IO.h"

/* initializes board to all NULL */
void CreateBoard(c_piece *board[8][8], c_piece* pieces[12]);

/*Copies one board to another board array (used much in AI)*/
void Copyboard(c_piece *oldboard[8][8],c_piece *newboard[8][8]);

/*initializes board with no peices*/
void Blankboard(c_piece *board[8][8]);

/*add single piece to board */
void addPiece(c_piece *board[8][8], piece_type type, c_color color, c_coords position);

#endif /* BOARD_H */