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
    if(result == INPUT_RESULT_TOO_LONG){
        printf("Du får bara skriva in 20 tecken");
    }
    
    bool successfulInput = GetInputInt("Jersey:",&newPlayer->jersey);
    // printf("Jersey:");
    // scanf(" %d",&newPlayer->jersey); // om error = ingen clear
}

typedef struct{
    Player *allPlayers;
    int playersCount;
} PLAYERLIST;


// void adminMenu(){
//     int bla = 12;
//     while(){
//     // skriv ut admin
//     // 1, ta fram rapport
//     // 3. exit
//     int sel;
//     scanf(" %d",&sel);
//     if(sel == 3){
//        return;
//     }
//     }
// }


// void huvudMenu(){
//     int age = 12;
//     while(){
//     // skriv ut huvudmenyn
//     // 1, Admin
//     // 2, Skapa
//     // 3. exit
//     int sel;
//     scanf(" %d",&sel);
//     if(sel == 1){
//         adminMenu();
//     }
//     }
// }


int main(){
    // FIL = bara för att korten ska vara beständiga!!!
    // arrayen med kort ska ta upp 0 bytes vid uppstart (innan du läst in filen)
    //    vid uppstart läsa från filen -> 
    
    // när du lägger till ett kort ska det ta upp 1 * sizeof(Player)
    // när du lägger till ett kort ska det ta upp 2 * sizeof(Player)
    // Den ska kunna växa!

    int age;
    // 
    //Player allPlayers[10]; // ALLOKERAD PÅ STACKEN - 10 * sizeof(Player)

    // Python = listan är så stor som vi har saker i den
    // C array har två "sizes" - MINNESALLOKERING - använder
    // 0

//    allPlayers[111] = 
    //Player allPlayers[]; 
    PLAYERLIST playersList;
    playersList.allPlayers = NULL;
    playersList.playersCount = 0;
    // Player *allPlayers = NULL; // pekare till en eller flera Player - odefinierat värde
    // int playersCount = 0;
    //allPlayers = malloc( 10 * sizeof(Player) ); // int  ALLTID bytes!!!

    // allPlayers arrayen ligger på HEAPEN inte på stacken
    // Stefan förklarar heap efter rasten
    // Men den STORA skillnaden är att nu kan allPlayers VÄXA - men fortsätta vara en array (konsekutivt i minnet)
    // heap kommer at a price

    // en stackallokerad variabel lever tills SCOPE:t är slut
    // en heapallokerad variabel lever tills vi frigör den

    if(1){
        char *s = malloc(100);
        free(s);
        // s är en pekare 
        // s ligger på stacken
        // men det den pekar på ligger på heapen
    }
    // s försvinner
    // men det som s pekade på ligger på heapen
    


    int b;
    while(true){
        printMenu();
        int selection;
        GetInputInt("Ange val:",&selection);
        switch(selection){
            case 1:
                // Förstora array med 1 
                // MALLOC första gången!!!
                // andra gången och senare köra man REALLOC

                // allPlayers = realloc(allPlayers,(playersCount  + 1) * sizeof(Player));

                if(playersList.playersCount == 0){
                    playersList.allPlayers = malloc(sizeof(Player));  // void * betyder pekare till vad som helst
                } else {
                    // "storleken" just nu PLUS 1 * sizeof(Player)
                    // (playersCount  + 1) * sizeof(Player)
                    // playersCount * sizeof(Player)
                    playersList.allPlayers = realloc(playersList.allPlayers,(playersList.playersCount  + 1) * sizeof(Player));
                }

                createNew(&playersList.allPlayers[playersList.playersCount]);

                playersList.playersCount++;
                
//                Player player;
//                createNew(&player);
                //printf("Ny spelare som heter:%s\n", player.name);
                //Put player into a "list"  (dvs array!) (konsektivt minne)
                break;
            case 2:
                printf("Lista alla\n");
                printf("***********************\n");
                for(int i = 0; i < playersList.playersCount;i++){
                    printf("Spelare:%s\n", playersList.allPlayers[i].name);
                }
                break;
            case 3:
                free(playersList.allPlayers); // JAG VISAR ATT JAG VET ATT JAG SKA LÄMNA TILLBAKA
                return 0;
        }
    }
    return 0;
}


 