#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "IO.h"
#include "Pieces.h"
#include "Rules.h"
#include <time.h>


void AIMOVE(c_piece*board[8][8], int turn){
    
    srand((unsigned)time(NULL));
    int x2 = rand() % 8;
    int y2 = rand() % 8;
    int checkm;
    
    int i,j;
    if(turn == 1){ //when as black side make the move
        for(i = 0;i<8;i++){
            for(j = 0; j<8;j++){
                if(board[j][i] == NULL){
                    continue;
                }
                else if(board[j][i] != NULL && board[y2][x2] == NULL){
                    if(GetColor(board[j][i]) == 1){
                        checkm = CheckMove(board,i,j,x2,y2);
                        if(checkm == 1){
                            move(board,i,j,x2,y2);
                            printf("%d,%d\n",x2,y2);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    else if(board[j][i] != NULL && board[y2][x2] != NULL){
                        if(GetColor(board[j][i]) == GetColor(board[y2][x2])){
                            continue;
                        }
                        else{
                            if(checkm == 1){
                                move(board,i,j,x2,y2);
                                printf("%d,%d\n",x2,y2);
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                    }
                    else{
                        x2 = rand() % 8;
                        y2 = rand() % 8;
                        continue;
                    }
                }
            }
        }
    }
    else if(turn == 0){ //When as white side make the move
       for(i = 0;i<8;i++){
            for(j = 0; j<8;j++){
                if(board[j][i] == NULL){
                    continue;
                }
                else if(board[j][i] != NULL){
                    if(GetColor(board[j][i]) == 0){
                        checkm = CheckMove(board,i,j,x2,y2);
                        if(checkm == 1){
                            move(board,i,j,x2,y2);
                            printf("%d,%d\n",x2,y2);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    else if(GetColor(board[j][i]) == 0 && board[j][i] != NULL && board[y2][x2] != NULL){
                        if(GetColor(board[j][i]) == GetColor(board[y2][x2])){
                            continue;
                        }
                        else{
                            checkm = CheckMove(board,i,j,x2,y2);
                            if(checkm == 1){
                                move(board,i,j,x2,y2);
                                printf("%d,%d\n",x2,y2);
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                    }
                    else if(GetColor(board[j][i]) == 0 && board[j][i] != NULL && board[y2][x2] == NULL){
                        checkm = CheckMove(board,i,j,x2,y2);
                        if(checkm == 1){
                            move(board,i,j,x2,y2);
                            printf("%d,%d\n",x2,y2);
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    else{
                        continue;
                    }
                }
                else{
                    x2 = rand() % 8;
                    y2 = rand() % 8;
                    continue;
                }
            }
        } 
    }
}