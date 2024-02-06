#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define NBRE_C 100



int main() {
    // Storage board
    client* storage;
    int capacity = NBRE_C;
    int verification;
    int top = 0;
    int option;
    int id;
    int password = 0;
    storage = (client*)malloc(NBRE_C * sizeof(client));
    if(storage == NULL){
        printf("Memory not allocated !!\n");
    
        return 1;
    }


    // Menu
    do{
        printf("...........................\n   WELCOME to BorisBank   \n...........................\n\n");
        printf("You can : \n- Create an account (1)\n- Display your account (2)\n- Delete your account (3)\n- Transfer money (4)\n- Display all account (5)\n- Stop the program (0)\n\n");
        printf("Please choose an option: ");
        scanf("%d",&option);
        getchar();
        switch (option)
        {
        case 1:
            verification = create_account(storage, &top);
            if(!verification) printf("\nSuccess !!!!\n\n");
            else printf("\nError: Can't create an account\n\n");
            break;
        case 2:
            id = verificationOptionRegister(storage,top);
            if(id != -1) displayCustomer(storage[id]);
            else printf("Error: Can't display\n");
            break;
        case 3:
            id =verificationOptionRegister(storage, top);
            if(id != -1){
                deleteAccount(storage,&top, id);
                printf("Delete Success\n");
            }
            else printf("Error: Account not found !!!\n");
            break;
        case 4:
            transfer(storage,top);
            break;
        case 5:
           displayAllCustomer(storage,top);
          
           break;
        default:
            break;
        }
    } while (option!= 0);
   

    for(int i = 0; i < top; i++){
        free(storage[i].name);
        storage[i].name = NULL;

        free(storage[i].firstName);
        storage[i].name = NULL;
    }
    free(storage);
    storage = NULL;
    return 0;
}