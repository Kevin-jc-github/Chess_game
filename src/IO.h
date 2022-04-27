/******************************************************************************
 *
 * Team 20
 * File name: IO.h
 * author: TianTian Lu
 * date: 2022/4/14
 * *******************************************************************************/
#ifndef IO_H
#define IO_H

#include "Pieces.h"

int fromxcoord, fromycoord;

int finalxcoord, finalycoord;

int StartMenu(int Startchoose);  //  Starting menu of the chess game, let user choose game mode
int GameMenu(int sidechoose);   //  allow user make move, undo move, or exit game

void move(c_piece *board[8][8],int x1, int y1, int x2, int y2);

void Undo(c_piece *board[8][8],int x1, int y1, int x2, int y2);

char getPTypeChar(c_piece  *piece);

char getPieceColorChar(c_piece *piece);

void printBoard(c_piece* gameboard[8][8]);

#endif
