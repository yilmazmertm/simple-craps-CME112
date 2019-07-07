#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolldice(){
    int dice1 = 1 + (rand()%6);
    int dice2 = 1 + (rand()%6);
    int sumof = dice1 + dice2;
    return sumof;
}
int main(){
    int balance;
    printf("Enter Balance to Start the game : \n" );
    scanf("%d", &balance);
    srand(time(NULL));
    int sumofDice, playerScore, flag =0;
    char decision;
    while(1){
        printf("Press 'd' to dice or 'e' to exit \n");
        scanf(" %c", &decision);
        int sumofDice = rolldice();
        if(decision == 'e'){
            printf("Exiting the game \n" );
            printf("Your balance is : %d \n", balance);
            break;
        }else if(balance<0){
                printf("You are out of money.\n" );
                break;
        }else if (decision == 'd'){
            printf("First round completed, Your number is : %d\n", sumofDice);
            printf("\n" );
            switch (sumofDice) {
                case 7:
                    balance += balance / 2;
                    printf("Congarts, you got 7 and you won. Your balance is : %d\n", balance );
                    printf("--------------------------\n" );
                    printf("\n" );
                    break;
                case 11:
                    balance += balance / 2;
                    printf("Congarts, you got 7 and you won. Your balance is : %d\n", balance );
                    printf("--------------------------\n" );
                    printf("\n" );
                    break;
                case 2:
                    balance -= balance / 4;
                    printf("You Lose , try again. Your balance is : %d \n", balance);
                    printf("--------------------------\n" );
                    printf("\n" );
                    break;
                case 3:
                    balance -= balance / 4;
                    printf("You Lose , try again. Your balance is : %d \n", balance);
                    printf("--------------------------\n" );
                    printf("\n" );
                    break;
                case 12:
                    balance -= balance / 4;
                    printf("You Lose , try again. Your balance is : %d \n", balance);
                    printf("--------------------------\n" );
                    printf("\n" );
                    break;
                default:
                    printf("You couldnt get the number at the first round. Your balance is : %d \n", balance);
                    printf("\n" );
                    printf("Second Round is starting \n" );
                    playerScore = sumofDice;
                    flag = 1;
                    printf("Press 'd' to dice \n");
                    printf("\n" );
                }
                while(flag == 1){
                    scanf(" %c", &decision);
                    if(decision == 'd'){
                        int sumofDice = rolldice();
                        if(sumofDice == 7){
                            balance -= balance / 4;
                            printf("You lose because you got 7. Your balance is : %d\n", balance );
                            printf("----------------------------------------------------\n" );
                            flag = 0;
                            break;
                        }
                        else if(sumofDice == playerScore){
                            balance += balance / 4;
                            printf("You won, you get : %d . Your balance is : %d \n" ,playerScore, balance);
                            printf("-------------------------------------------------\n" );
                            printf("\n" );
                            flag = 0;
                            break;
                        }
                        else{
                            printf("\n");
                            printf("Dice sum is : %d , you should be getting : %d\n",sumofDice, playerScore);
                            printf("\n");
                            printf("You must dice again\n");
                            printf("Press 'd' to dice \n");
                        }
                    }
                }
            }
    }
    return 0;
}
