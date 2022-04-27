/* Team 20  */
/* File name: Board.c */
/* author: Kevin Zhu & Yuan Wang */
/* Date: 2022/04/11 */

#include "Board.h"
#include <stdio.h>
#include <string.h>
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Pieces.h"

/* initialilze the chess board */
void CreateBoard(c_piece *board[8][8], c_piece* pieces[12]){
    c_piece *bp = malloc(sizeof(c_piece));
	c_piece *bkn = malloc(sizeof(c_piece));
	c_piece *bb = malloc(sizeof(c_piece));
	c_piece *br = malloc(sizeof(c_piece));
	c_piece *bq = malloc(sizeof(c_piece));
	c_piece *bk = malloc(sizeof(c_piece));

	c_piece *wp = malloc(sizeof(c_piece));
	c_piece *wkn = malloc(sizeof(c_piece));
	c_piece *wb = malloc(sizeof(c_piece));
	c_piece *wr = malloc(sizeof(c_piece));
	c_piece *wq = malloc(sizeof(c_piece));
	c_piece *wk = malloc(sizeof(c_piece));
    
    /* initialize pieces for white chesses */
    CreatePiece(wp, WHITE, PAWN);
	pieces[6] = wp;
	CreatePiece(wkn, WHITE, KNIGHT);
	pieces[7] = wkn;
	CreatePiece(wb, WHITE, BISHOP);
	pieces[8] = wb;
	CreatePiece(wr, WHITE, ROOK);
	pieces[9] = wr;
	CreatePiece(wq, WHITE, QUEEN);
	pieces[10] = wq;
	CreatePiece(wk, WHITE, KING);
	pieces[11] = wk;
	
	/* initialize pieces for black chesses */
	CreatePiece(bp, BLACK, PAWN);
	pieces[0] = bp;
	CreatePiece(bkn, BLACK, KNIGHT);
	pieces[1] = bkn;
	CreatePiece(bb, BLACK, BISHOP);
	pieces[2] = bb;
	CreatePiece(br, BLACK, ROOK);
	pieces[3] = br;
	CreatePiece(bq, BLACK, QUEEN);
	pieces[4] = bq;
	CreatePiece(bk, BLACK, KING);
	pieces[5] = bk;
    
    /* Since there are too many rooks of white or black side, we decide to use for loop to put them onto their position */
	int i,j;
	for(i = 0; i < 8; i++)
	{
		board[1][i] = wp;
		board[6][i] = bp;
	}
	
	for(j = 2; j < 6; j++){
		for(i = 0; i < 8; i++){
			board[j][i] = NULL;
		}
	}
	
    /* put the chess onto their inital position */
    board[0][3] = wq;
	board[0][4] = wk;
	board[0][0] = board[0][7] = wr;
	board[0][1] = board[0][6] = wkn;
	board[0][2] = board[0][5] = wb;
	
    board[7][3] = bq;
	board[7][4] = bk;
	board[7][0] = board[7][7] = br;
	board[7][1] = board[7][6] = bkn;
	board[7][2] = board[7][5] = bb;
	
    
}


/* Add every single piece on the board */
void addPiece(c_piece *board[8][8], piece_type type, c_color color, c_coords position){
    
    c_piece *piece = (c_piece*)malloc(sizeof(c_piece));
    CreatePiece(piece, color, type);
    board[position.Posy][position.Posx] = piece;
    
}


/*initializes a blank board with no peices*/
void Blankboard(c_piece *board[8][8]){
	int i,j;
    for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j] = NULL;
        }
    }
}


/*Coping one board to another board array*/
void Copyboard(c_piece *oldboard[8][8],c_piece *newboard[8][8]){
	int i,j;
    for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			newboard[i][j] = oldboard[i][j];
        }
    }
}

