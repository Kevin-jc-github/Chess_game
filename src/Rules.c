/* Team 20 */
/* File name: Pieces.c */
/* Author: Kevin Zhu & Pengfei Yan & Chengyu Mou*/
/* Date: 2022/04/15 */

#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "IO.h"
#include "Pieces.h"
#include "Rules.h"

void move(c_piece *board[8][8],int x1, int y1, int x2, int y2){
    c_piece *temp = malloc(sizeof(c_piece));
    if(board[y1][x1]){
        temp = board[y1][x1];
        board[y2][x2] = temp;
        board[y1][x1] = NULL;
    }
}

void Undo(c_piece *board[8][8],int x1, int y1, int x2, int y2){
    c_piece *temp2 = malloc(sizeof(c_piece));
    if(board[y2][x2]){
        temp2 = board[y2][x2];
        board[y1][x1] = temp2;
        board[y2][x2] = NULL;
    }
}

/* Check if the next move will make the king in a check mate situation*/
void IfinCheck(c_piece *board[8][8],int x2, int y2){
    int object; // The type of the next object
    object = GetType(board[y2][x2]);
    if(object == 6){
        printf("The King will be in the situaion of Check Mate!\n");
    }
}


/* check the legality of each move */
int CheckMove(c_piece *board[8][8], int x1, int y1, int x2, int y2){
	/* get the type of the peice that player want to move */
	int typ = GetType(board[y1][x1]);
	if(typ == 1){
		return CheckPawn(board, x1, y1, x2, y2);
	}
	else if(typ  == 2){
		return CheckRook(board, x1, y1, x2, y2);
	}
	else if(typ == 3){
		return CheckBishop(board, x1, y1, x2, y2);
	}
	else if(typ == 4){
		return CheckKnight(board, x1, y1, x2, y2);
	}
	else if(typ == 5){
		return CheckQueen(board, x1, y1, x2, y2);
	} 
	else if(typ == 6){
		return CheckKing(board, x1, y1, x2, y2);
	}
	else{
		return 0;
	}
}


// The rule to check the move the pawn
int CheckPawn(c_piece *board[8][8],int x1, int y1,int x2,int y2){ // The rules for moving Pawn.
    // For white perspective
    if(y1 == 1 || y1 == 6){ //when the y of the piecevwe want to move is equal to the 2nd or 7th row, it is the first time
        if(board[y2][x2] == NULL && (y2 == (y1 + 1))){ //if the pawn have nothing in front it, and user choose to move it for 1 unit
            return 1;
        }
        else if(board[y2][x2] != NULL && (x2 == x1) && (y2 == (y1 + 1))){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
                }
                else{
                    board[y2][x2] = NULL;
                    return 1;
                }
        }
        else if(board[y2][x2] == NULL && (x2 == x1) && (y2 == (y1 + 2))){
            if(board[y1 + 1][x1] != NULL){
                if(GetColor(board[y1][x1]) == GetColor(board[y1 + 1][x1])){
                    return 0;
                }
                else{
                    board[y1 + 1][x1] = NULL;
                    return 1;
                } 
            }
            else{
                return 1;
            }
        }
        else if(board[y2][x2] != NULL && (x2 == x1) && (y2 == (y1 + 2))){
            if(board[y1 + 1][x1] == NULL){
                if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
                }
                else{
                    board[y2][x2] = NULL;
                    return 1;
                }
            }
            else{
                if(GetColor(board[y1][x1]) == GetColor(board[y1 + 1][x1])){
                    return 0;
                }
                else{
                    board[y1 + 1][x1] = NULL;
                    return 1;
                } 
            }
        }
        // For Black Perspective
        if(board[y2][x2] == NULL && (y2 == (y1 - 1))){ //if the pawn have nothing in front it, and user choose to move it for 1 unit
            return 1;
        }
        else if(board[y2][x2] != NULL && (x2 == x1) && (y2 == (y1 - 1))){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
                }
                else{
                    board[y2][x2] = NULL;
                    return 1;
                }
        }
        else if(board[y2][x2] == NULL && (x2 == x1) && (y2 == (y1 - 2))){
            if(board[y1 - 1][x1] != NULL){
                if(GetColor(board[y1][x1]) == GetColor(board[y1 - 1][x1])){
                    return 0;
                }
                else{
                    board[y2][x2] = NULL;
                    return 1;
                } 
            }
            else{
                return 1;
            }
        }
        else if(board[y2][x2] != NULL && (x2 == x1) && (y2 == (y1 - 2))){
            if(board[y1 - 1][x1] == NULL){
                if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
                }
                else{
                    board[y2][x2] = NULL;
                    return 1;
                }
            }
            else{
                if(GetColor(board[y1][x1]) == GetColor(board[y1 - 1][x1])){
                    return 0;
                }
                else{
                    board[y1 - 1][x1] = NULL;
                    return 1;
                } 
            }
        }
        
    }
    else if(y1 != 1 || y1 != 6){
        if(abs((y2-y1)) > 1){
            return 0;
        }
        else{
            if(board[y2][x2] == NULL && (x2 == x1) && (y2 == (y1 + 1))){ //if the pawn have nothing in front it, and user choose to move it for 1 unit
                return 1;
            }
            else if(board[y2][x2] != NULL && (x2 == x1) && (y2 == (y1 + 1))){
                if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
                }
                else{
                    board[y2][x2] = NULL;
                    return 1;
                }
            }
        }
    }
    else if((x2 == x1 - 1)||(y2 == y1 - 1)){
        return 0;
    }
    else if(x2 == x1 + 1 && y2 == y1 + 1){
        if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
            return 0;
        }
        else{
            board[y2][x2] = NULL;
            return 1;
        }
    }
    else if(x2 == x1 - 1 && y2 == y1 + 1){
        if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
            return 0;
        }
        else{
            board[y2][x2] = NULL;
            return 1;
        }
    }
    else{
        return 0;
    }
}

// The rule to check the move the King
int CheckKing(c_piece *board[8][8], int x1, int y1, int x2, int y2){
    if(abs(x2 - x1)>1 || abs(y2-y1)>1){
        return 0;
    }
    else{
        // The vertical direction
        if(x2 == x1 && board[y2][x1] != NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        else if(x2 == x1 && board[y2][x1] == NULL){
            return 1;
        }
        
        // The horizontal direction
        else if(y2 == y1 && board[y2][x1] != NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        else if(y2 == y1 && board[y2][x1] == NULL){
            return 1;
        }
        
        // The upper right diagonal direction
        else if((y2 == y1 + 1)&&(x2 == x1 + 1)&&board[y2][x2]==NULL){
            return 1;
        }
        else if((y2 == y1 + 1)&&(x2 == x1 + 1)&&board[y2][x2]!=NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        
        // The lower right diagonal direction
        else if((y2 == y1 - 1)&&(x2 == x1 + 1)&&board[y2][x2]==NULL){
            return 1;
        }
        else if((y2 == y1 - 1)&&(x2 == x1 + 1)&&board[y2][x2]!=NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        
        // The upper left diagonal direction
        else if((y2 == y1 + 1)&&(x2 == x1 - 1)&&board[y2][x2]==NULL){
            return 1;
        }
        else if((y2 == y1 + 1)&&(x2 == x1 - 1)&&board[y2][x2]!=NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        
        // The lower left diagonal direction
        else if((y2 == y1 - 1)&&(x2 == x1 - 1)&&board[y2][x2]==NULL){
            return 1;
        }
        else if((y2 == y1 - 1)&&(x2 == x1 - 1)&&board[y2][x2]!=NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        else{
            return 0;
        }
    }
}

// The rule to check the move of the Rook
int CheckRook(c_piece *board[8][8], int x1, int y1, int x2, int y2){
    int i,j;//To count how many distance between y2 and y1, and x2,x1
    if(x1 == x2 && abs(y2-y1)<1){
        if(board[y2][x1] != NULL){
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                    return 0;
            }
            else{
                    board[y2][x2] = NULL;
                    return 1;
            }
        }
        else if(board[y2][x1] == NULL){
            return 1;
        }
    }
    else if(x1 == x2 && abs(y2-y1)>1){
        for(i = 1; i<=abs(y2-y1);i++){
            if(board[i][x2] == NULL && i!=abs(y2-y1)){
                continue;
            }
            else if(board[i][x2] == NULL && i==abs(y2-y1)){
                return 1;
            }
            else if(board[i][x2] != NULL && i==abs(y2-y1)){
                if(GetColor(board[y1][x1]) == GetColor(board[i][x2])){
                    return 0;
                }
                else{
                    board[i][x2] = NULL;
                    return 1;
                }
            }
            else if(board[i][x2] != NULL){
                return 0; 
            }
            else{
                return 0;
            }
        }
    }
    else if(y1 == y2 && abs(x2-x1)>1){
        for(j = 1; i<=abs(x2-x1);j++){
            if(board[y2][j] == NULL && j!=abs(x2-x1)){
                continue;
            }
            else if(board[y2][j] == NULL && j==abs(x2-x1)){
                return 1;
            }
            else if(board[y2][j] != NULL && j==abs(x2-x1)){
                if(GetColor(board[y1][x1]) == GetColor(board[y2][j])){
                    return 0;
                }
                else{
                    board[y2][j] = NULL;
                    return 1;
                }
            }
            else if(board[y2][j] != NULL){
                return 0; 
            }
            else{
                return 0;
            }
        }
    }
    else{
        return 0;
    }
}

// The rule to check the move of the Bishop
int CheckBishop(c_piece *board[8][8], int x1, int y1, int x2, int y2){
    int i;
    int finalpoint = abs(y2 - y1);
    // if user move bishop to horizontal or vertical
    if(y2 == y1 || x2 == x1){
        return 0;
    }
    else{
         //First check upper right diagonal
        for(i = 1;i <= finalpoint;i++){
            if(board[y1 + i][x1 + i] == NULL && i!=finalpoint){
                continue;
            }
            else if(board[y1 + i][x1 + i] == NULL && i==finalpoint){
                return 1;
            }
            else if(board[y1 + i][x1 + i] != NULL && i == finalpoint){
               if(GetColor(board[y1][x1]) == GetColor(board[y1 + i][x1 + i])){
                    return 0;
                }
                else{
                    board[y1+i][x1+i] = NULL;
                    return 1;
                } 
            }
            else{
                return 0;
            }
        }
        //Then check lower Right diagonal
        for(i = 1;i < finalpoint;i++){
            if(board[y1 - i][x1 + i] == NULL && i!=finalpoint){
                continue;
            }
            else if(board[y1 - i][x1 + i] == NULL && i==finalpoint){
                return 1;
            }
            else if(board[y1 - i][x1 + i] != NULL && i == finalpoint){
               if(GetColor(board[y1][x1]) == GetColor(board[y1 - i][x1 + i])){
                    return 0;
                }
                else{
                    board[y1-i][x1+i] = NULL;
                    return 1;
                } 
            }
            else{
                return 0;
            }
        }
        //Then check Upper left diagonal
        for(i = 1;i < finalpoint;i++){
            if(board[y1 + i][x1 - i] == NULL && i!=finalpoint){
                continue;
            }
            else if(board[y1 + i][x1 - i] == NULL && i==finalpoint){
                return 1;
            }
            else if(board[y1 + i][x1 - i] != NULL && i == finalpoint){
               if(GetColor(board[y1][x1]) == GetColor(board[y1 + i][x1 - i])){
                    return 0;
                }
                else{
                    board[y1+i][x1-i] = NULL;
                    return 1;
                } 
            }
            else{
                return 0;
            }
        }
        //Then check lower left diagonal
        for(i = 1;i < finalpoint;i++){
            if(board[y1 - i][x1 - i] == NULL && i!=finalpoint){
                continue;
            }
            else if(board[y1 - i][x1 - i] == NULL && i==finalpoint){
                return 1;
            }
            else if(board[y1 - i][x1 - i] != NULL && i == finalpoint){
               if(GetColor(board[y1][x1]) == GetColor(board[y1 - i][x1 - i])){
                    return 0;
                }
                else{
                    board[y1-i][x1-i] = NULL;
                    return 1;
                } 
            }
            else{
                return 0;
            }
        }
    }
}

// The rule to check the move of the Queen
int CheckQueen(c_piece *board[8][8], int x1, int y1, int x2, int y2){
    
    CheckBishop(board, x1, y1, x2, y2);
    CheckRook(board, x1, y1, x2, y2);
    
}

// The rule to check the move of the Knight
int CheckKnight(c_piece *board[8][8], int x1, int y1, int x2, int y2){

    if((x2 == (x1 + 2)) && (y2 == (y1 + 1))){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if((x2 == (x1 + 2)) && (y2 == (y1 - 1))){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if(x2 == (x1 - 2) && y2 == (y1 + 1)){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if(x2 == (x1 - 2) && y2 == (y1 - 1)){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if(x2 == (x1 + 1) && y2 == (y1 - 2)){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if(x2 == (x1 - 1) && y2 == (y1 - 2)){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if((x2 == (x1 + 1)) && (y2 == (y1 + 2))){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else if(x2 == (x1 - 1) && y2 == (y1 + 2)){
        if(board[y2][x2] == NULL){
            return 1;
        }
        else{
            if(GetColor(board[y1][x1]) == GetColor(board[y2][x2])){
                return 0;
            }
            else{
                board[y2][x2] = NULL;
                return 1;
            }
        }
    }
    else{
        return 0;
    }
}