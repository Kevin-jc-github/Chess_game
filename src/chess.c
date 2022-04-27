/******************************************************************************
/* Team 20  */
/* File name: chess.c */
/* author: Kevin Zhu*/
/* Date: 2022/04/20 */

#include "Board.h"
#include <stdio.h>
#include <string.h>
#include "IO.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Pieces.h"
#include "Rules.h"
#include <time.h>
#include "AI.h"



int main()
{   
    c_piece *board[8][8];
    c_piece* pieces[12];
    CreateBoard(board,pieces);
    int     sidechoose;
    int     Startchoose;
    int userchoice1; //To store the selection of Startmenu
    int userchoice2; // To store the selection of Gamemenu
    int choice; // To store the what action the user want to do at pvp
    int fromx; 
    int fromy;
    int finalx;
    int finaly;
    int undo;// To store if the user want to undo or not.
    int turn = 0;
    int check; // To store the result of check rules
    int AIturn = 0;
    
    userchoice1 = StartMenu(Startchoose);
    if(userchoice1 == 1){// user choose to play player vs player
        userchoice2 = GameMenu(sidechoose);
        printf("\n");
        if(userchoice2 == 2){ // user choose to play at the black side
            printBoard(board);
            printf("\n");
            goto reenter;
        }
        else if(userchoice2 == 1){// user choose to play the white side
            printf("\n");
            printBoard(board);
        reenter:if(turn == 0){
                printf("It is the white side's turn to make a move!\n");
                printf("\n");
                printf("To make a move press 1 \n");
                printf("To exit press 2 \n");
            }
            else if(turn == 1){
                printf("To make a move press 1 \n");
                printf("To exit press 2 \n");
            }
            
    reenter2:printf("Make your choice: ");
            scanf("%d",&choice);
            if(choice == 1){
	            printf(" Please make a move!\n");  
            }
            else if(choice == 2){
                exit(0);
            }
            else{
            printf("Option does not exist, please re-enter!\n");
            goto reenter2;
            }
        undo1:printf(" First, enter the x coordinate of the piece you wanted to move: ");
            scanf("%d", &fromx);
            printf(" Enter the y coordinate of the piece you wanted to move: ");
            scanf("%d", &fromy);
            printf(" Then, enter the x coordinate of the destination: ");
            scanf("%d", &finalx);
            printf(" Enter the y coordinate of the destination: ");
            scanf("%d", &finaly);
            check = CheckMove(board,fromx,fromy,finalx,finaly);
            if(check == 0){
                printf("This is an illegal move, please re-enter!\n");
                printf("\n");
                goto undo1;
            }
            else if(check == 1){
                move(board,fromx,fromy,finalx,finaly);
                printBoard(board);
                printf("\n");
            undo2:printf("You still have a chance to undo a move,type 1 to undo, 2 to continue:");
                scanf("%d",&undo);
                if(undo == 2){
                    if(turn == 0){ // Now is time to turn to Black side move
                        printf("It is the black side's turn to make a move!\n");
                        printf("\n");
                        turn = 1;
                        goto reenter;
                    }
                    else if(turn == 1){
                        turn = 0;
                        goto reenter;
                    }
                }
                else if(undo ==1){
                    Undo(board,fromx,fromy,finalx,finaly);
                    printf("Undo is successful! Please re-make a move!\n");
                    printBoard(board);
                    goto undo1;
                }
                else{
                    printf("Option does not exist, please re-enter!\n");
                    goto undo2;
                }
            }
        }
    }
    
    // if the user choose to play human vs computer
    else if(userchoice1 == 2){
        userchoice2 = GameMenu(sidechoose);
        printf("\n");
        // user choose to play at the black side
        if(userchoice2 == 2){ 
            AIturn = 0;//which means the AI choose the white side, AIturn = 0;
            turn = 1; //which means the human choose the balck side, turn = 1;
            printBoard(board);
            printf("\n");
        ai: AIMOVE(board,AIturn);
            printBoard(board);
            printf("It is the black side's turn to make a move!\n");
            goto reenter4;
        }
        // if the user choose to play at the white side
        else if(userchoice2 == 1){ 
            AIturn = 1;//which means the AI choose the black side
            turn = 0;
            printBoard(board);
    reenter4:printf("To make a move press 1 \n");
            printf("To exit press 2 \n");
            printf("Make your choice: ");
            scanf("%d",&choice);
            if(choice == 1){
	            printf(" Please make a move!\n");  
            }
            else if(choice == 2){
                exit(0);
            }
            else{
            printf("Option does not exist, please re-enter!\n");
            goto reenter4;
            }
            undo3:printf(" First, enter the x coordinate of the piece you wanted to move: ");
            scanf("%d", &fromx);
            printf(" Enter the y coordinate of the piece you wanted to move: ");
            scanf("%d", &fromy);
            printf(" Then, enter the x coordinate of the destination: ");
            scanf("%d", &finalx);
            printf(" Enter the y coordinate of the destination: ");
            scanf("%d", &finaly);
            check = CheckMove(board,fromx,fromy,finalx,finaly);
            if(check == 0){
                printf("This is an illegal move, please re-enter!\n");
                printf("\n");
                goto undo3;
            }
            else if(check == 1){
                move(board,fromx,fromy,finalx,finaly);
                printBoard(board);
                printf("\n");
            undo4:printf("You still have a chance to undo a move,type 1 to undo, 2 to continue:");
                scanf("%d",&undo);
                if(undo ==1){
                    Undo(board,fromx,fromy,finalx,finaly);
                    printf("Undo is successful! Please re-make a move!\n");
                    printBoard(board);
                    goto undo3;
                }
                else if(undo == 2 && turn == 0){
                    printf("It is the black side's turn to make a move!\n");
                    printf("\n");
                    AIMOVE(board,AIturn);
                    printBoard(board);
                    printf("It is the White side's turn to make a move!\n");
                    printf("\n");
                    goto reenter4;
                }
                else if(undo == 2 && turn == 1){
                    printf("It is the White side's turn to make a move!\n");
                    printf("\n");
                    goto ai;
                }
            }
        }
            
        
    }
   return 0;
}

