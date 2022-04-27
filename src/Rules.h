/* Team 20 */
/* File name: Pieces.c */
/* Author: Kevin Zhu & Pengfei Yan & Chengyu Mou*/
/* Date: 2022/04/15 */

#ifndef RULES_H
#define RULES_H

#include "Board.h"
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include "Pieces.h"

/* The function to Move a piece */
void move(c_piece *board[8][8],int x1, int y1, int x2, int y2);

/* The function to Undo a piece */
void Undo(c_piece *board[8][8],int x1, int y1, int x2, int y2);

/* check the legality of each move */
int CheckMove(c_piece *board[8][8], int x1, int y1, int x2, int y2);

// The rule to check the move the pawn
int CheckPawn(c_piece *board[8][8],int x1, int y1,int x2,int y2);

// The rule to check the move the King
int CheckKing(c_piece *board[8][8], int x1, int y1, int x2, int y2);

// The rule to check the move of the Rook
int CheckRook(c_piece *board[8][8], int x1, int y1, int x2, int y2);

// The rule to check the move of the Queen
int CheckQueen(c_piece *board[8][8], int x1, int y1, int x2, int y2);

// The rule to check the move of the Bishop
int CheckBishop(c_piece *board[8][8], int x1, int y1, int x2, int y2);

// The rule to check the move of the Knight
int CheckKnight(c_piece *board[8][8], int x1, int y1, int x2, int y2);

#endif /* RULES_H */