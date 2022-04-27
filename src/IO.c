/******************************************************************************

Team 20
File name: IO.c
author: TianTian Lu
Date: 2022/4/14

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "IO.h"
#include "Board.h"
#include "Pieces.h"

int StartMenu(int Startchoose){                            //  starting game, choose game mode
        printf("1. Human vs Human \n");
        printf("2. Human vs Computer \n");
        printf("3. Exit \n");
reenter1:        printf("Make your choice: ");
        scanf("%d",&Startchoose);
        if(Startchoose == 2){
            return 2;// chose pvc
        }
        else if(Startchoose == 1){
            return 1;//choose pvp
        }
        else{
            exit(0);
        }
}                                  

int GameMenu(int sidechoose){                            //  let user choose, make move or exit
	printf("Please choose a side(1 for White or 2 for Black):");
	scanf("%d",&sidechoose);
	printf("\n");
	if(sidechoose == 2){
		printf("You choose the Black side!\n");
		printf("You need to wait for the white move first!\n");
		return 2; // when choose black
	 }
	 else if(sidechoose == 1){
		printf("You choose the White side!\n");
        return 1;//when choose white side
       }
}



void printBoard(c_piece* gameboard[8][8]){
  
  char t;
  char c;
  int i, j;
  
  for(i=0;i<8;i++){
    printf("  +----+----+----+----+----+----+----+----+");
    printf("\n");
    for(j=0;j<8;j++){
      if(j == 0){
	    printf("%d | ", 7-i);
      }
      else{
	    printf(" | ");
      }
      if(gameboard[7-i][j]==NULL){
	    printf("  ");
              }
      else{
	    t= getPTypeChar(gameboard[7-i][j]);
        c= getPieceColorChar(gameboard[7-i][j]);
	    printf("%c%c",c,t);

	}
      }
    printf(" |");
    printf("\n");
    }
  printf("  +----+----+----+----+----+----+----+----+\n"
         "    0    1    2    3    4    5    6    7   \n");
  printf("\n\n");
}


/* returns string associated with piecetype */
char getPTypeChar(c_piece  *piece){
  switch( piece->type)
    {
    case KING:
      return 'K';
    case QUEEN:
      return 'Q';
    case BISHOP:
      return 'B';
    case KNIGHT:
      return 'N';
    case ROOK:
      return 'R';
    case PAWN:
      return 'P';
    }
    
}

/* returns string associated with team color */
char getPieceColorChar(c_piece *piece){
  switch(piece->color)
    {
    case 1:
      return 'b';
    case 0:
      return 'w';
    }

}








