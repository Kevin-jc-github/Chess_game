/* Team 20 */
/* File name: Pieces.c */
/* Author: Pengfei Yan */
/* Date: 2022/04/14 */

#include "Pieces.h"

/*Initialize piece*/
void CreatePiece(c_piece *p, c_color co, piece_type typ){
  
  p->color = co;
  p->type = typ;
  
}

/* Get the color of the piece */
c_color GetColor(c_piece *p){
    return p->color;
}

/* Get the type of a piece */
piece_type GetType(c_piece *p){
    return p->type;
}