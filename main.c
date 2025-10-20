#include <stdio.h>

typedef struct {
    int jersey;
    char name[20];
}Player;

void printMenu(){
    printf("1. Skapa ny");
    printf("2. Lista alla");
    printf("3. Exit");
}


int main(){

    while(1){
        printMenu();
        int selection;
        scanf(" %d", &selection);
        switch(selection){
            case 1:
                printf("Ny");
                break;
            case 2:
                printf("Lista alla");
                break;
            case 3:
                return;
        }

    }

    return 0;
}


