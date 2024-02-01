#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define NBRE_C 100
#define PWD 010124

int main() {
    // Storage board
    client* storage;
    int verification;
    int nbre = 0;
    int option = 0;
    int id = 0;
    int password = 0;
    storage = (client*)malloc(NBRE_C * sizeof(client));


    // Menu
    do{
        printf("...........................\n   WELCOME to BorisBank   \n...........................\n\n");
        printf("You can : \n- Create an account(1)\n- Display your account(2)\n- Delete your account(3)\n- Display all account(4)\nStop the program(0)\n\n");
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
            printf("Creation Success\n");
            break;
        case 3:
            id = verificationOption(storage, nbre);
            if(id != -1) deleteAccount(storage, id);
            else printf("Error\n");
            printf("Delete Success\n");
            break;
        case 4:
           printf("Enter the Password please: ");
           scanf("%d",&password);
           getchar();
           if(password == PWD) displayAllCustomer(storage,nbre);
           else printf("try again\n");
           break;
        default:
            break;
        }
    } while (option!= 0);
   

    

     
    return 0;
}
