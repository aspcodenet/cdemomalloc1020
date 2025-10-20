#include <stdio.h>

typedef struct {
    int jersey;
    char name[20];
}Player;

void printMenu(){
    printf("1. Skapa ny\n");
    printf("2. Lista alla\n");
    printf("3. Exit\n");
}

void createNew(Player *newPlayer){
    printf("Skapa ny\n************************\n");
    printf("Name:");
    scanf(" %s",newPlayer->name); // mellanslag + buffer overflow fel + 
    printf("Jersey:");
    scanf(" %d",&newPlayer->jersey); // om error = ingen clear
}


int main(){

    while(1){
        printMenu();
        int selection;
        scanf(" %d", &selection);
        switch(selection){
            case 1:
                Player player;
                createNew(&player);
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


