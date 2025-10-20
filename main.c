#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
    // FIL = bara för att korten ska vara beständiga!!!
    // arrayen med kort ska ta upp 0 bytes vid uppstart (innan du läst in filen)
    //    vid uppstart läsa från filen -> 
    
    // när du lägger till ett kort ska det ta upp 1 * sizeof(Player)
    // när du lägger till ett kort ska det ta upp 2 * sizeof(Player)
    // Den ska kunna växa!

    int age;
//    Player allPlayers[10]; // ALLOKERAD PÅ STACKEN - 10 * sizeof(Player)
//    allPlayers[111] = 
    //Player allPlayers[]; 
    Player *allPlayers; // pekare till en eller flera Player - odefinierat värde
    allPlayers = malloc( 10 * sizeof(Player) ); // int  ALLTID bytes!!!
    // allPlayers arrayen ligger på HEAPEN inte på stacken
    // Stefan förklarar heap efter rasten
    // Men den STORA skillnaden är att nu kan allPlayers VÄXA - men fortsätta vara en array (konsekutivt i minnet)
    // heap kommer at a price


    int b;
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


 