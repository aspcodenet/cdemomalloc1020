#include <stdio.h>
#include <stdbool.h>
#include "safeinput.h"

typedef struct {
    int jersey;
    char name[20];
}Player;

void printMenu(){
    printf("1. Skapa ny\n");
    printf("2. Lista alla\n");
    printf("3. Exit\n");
}

// typedef enum{
//   WITHDRAWAL_OK,
//   WITHDRAWAL_BELOPP_LARGER_THAN_DAILY_AMOUNT, //  
//   WITHDRAWAL_BELOPP_LARGER_THAN_SALDO,
//   WITHDRAWAL_BLA
// } WITHDRAWAL_ERROR;

// WITHDRAWAL_ERROR withDrawal(int amount){ // uttag
//     // om beloppet > 5000
//     return WITHDRAWAL_BELOPP_LARGER_THAN_DAILY_AMOUNT;
//     // om beloppet > saldo 
//     return WITHDRAWAL_BELOPP_LARGER_THAN_SALDO;
//     // annars
//     return WITHDRAWAL_OK;
// }


// input, print
// API - färdiga funktioner - 
// avr_gcc Embedded - färdiga funktioner 

void createNew(Player *newPlayer){
    // if(withDrawal(100) == WITHDRAWAL_BELOPP_LARGER_THAN_DAILY_AMOUNT){

    // }
    // Felhantering - loopa till alla är "ok"
    printf("Skapa ny\n************************\n");
    INPUT_RESULT result = GetInput("Name:",newPlayer->name,20);
    if(result == INPUT_RESULT_OK ){
        printf("Du får bara skriva in 20 tecken");
    }
    
    bool successfulInput = GetInputInt("Jersey:",&newPlayer->jersey);
    // printf("Jersey:");
    // scanf(" %d",&newPlayer->jersey); // om error = ingen clear
}


int main(){
    while(true){
        printMenu();
        int selection;
        GetInputInt("Ange val:",&selection);
        switch(selection){
            case 1:
                Player player;
                createNew(&player);
                printf("Ny spelare som heter:%s\n", player.name);
                //Put player into a "list"  (dvs array!) (konsektivt minne)
                break;
            case 2:
                printf("Lista alla");
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}


