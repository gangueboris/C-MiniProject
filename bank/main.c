#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define NBRE_C 100
#define CHAR 10


int main() {
    // Storage board
    client* storage;
    int verification;
    int nbre = 0;
    int option = 0;
    int id = 0;
    int password = 0;
    storage = (client*)malloc(NBRE_C * sizeof(client));
    if(storage == NULL){
        printf("Memory not allocated !!\n");
        return 1;
    }


    // Menu
    do{
        printf("...........................\n   WELCOME to BorisBank   \n...........................\n\n");
        printf("You can : \n- Create an account (1)\n- Display your account (2)\n- Delete your account (3)\n- Display all account (4)\n- Stop the program (0)\n\n");
        printf("Please choose an option: ");
        scanf("%d",&option);
        getchar();
        switch (option)
        {
        case 1:
            verification = create_account(storage, &nbre);
            if(!verification) printf("\nSuccess !!!!\n\n");
            else printf("\nIssue !!!!\n\n");
            break;
        case 2:
            id = verificationOption(storage,nbre);
            if(id != -1) displayCustomer(storage[id]);
            else printf("Error\n");
            break;
        case 3:
            id = verificationOption(storage, nbre);
            if(id != -1){
                deleteAccount(storage, id);
                printf("Delete Success\n");
            }
            else printf("Error\n");
            break;
        case 4:
           displayAllCustomer(storage,nbre);
          
           break;
        default:
            break;
        }
    } while (option!= 0);
   

    for(int i = 0; i < NBRE_C ; i++){
        free(storage[i].name);
        storage[i].name = NULL;

        free(storage[i].firstName);
        storage[i].name = NULL;
    }
    free(storage);
    storage = NULL;
    return 0;
}