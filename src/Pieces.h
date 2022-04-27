/* Team 20 */
/* File name: Pieces.h */
/* Author: Pengfei Yan */
/* Date: 2022/04/12 */

#ifndef PIECES_H
#define PIECES_H

#include <stdlib.h>

/* defination of the type of pieces */
typedef enum piece_type
{
    PAWN = 1,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING,
}piece_type;

/* defination of the color of a piece */
typedef enum c_color
{
    WHITE = 0, 
    BLACK = 1
}c_color; 

/* defination of a piece */
typedef struct piece
{
    enum piece_type type;
    enum c_color color;
}c_piece;

typedef struct c_coords
{
int Posy;
int Posx;
} c_coords;


/* Create a piece */
void CreatePiece(c_piece *p, c_color co, piece_type typ);

/* Get the color of a piece */
c_color GetColor(c_piece *p);

/* Get the type of a piece */
piece_type GetType(c_piece *p);

#endif/* PIECES_H */
